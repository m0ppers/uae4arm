/*
 * UAE - The Un*x Amiga Emulator
 *
 * Pandora interface
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdarg.h>
#include <asm/sigcontext.h>
#include <signal.h>
#include <dlfcn.h>
#ifndef ANDROID
#include <execinfo.h>
#endif
#include "sysconfig.h"
#include "sysdeps.h"
#include "config.h"
#include "autoconf.h"
#include "uae.h"
#include "options.h"
#include "threaddep/thread.h"
#include "gui.h"
#include "memory-uae.h"
#include "newcpu.h"
#include "custom.h"
#include "xwin.h"
#include "drawing.h"
#include "inputdevice.h"
#include "keybuf.h"
#include "keyboard.h"
#include "disk.h"
#include "savestate.h"
#include "traps.h"
#include "bsdsocket.h"
#include "blkdev.h"
#include "native2amiga.h"
#include "rtgmodes.h"
#include "uaeresource.h"
#include "rommgr.h"
#include "akiko.h"
#include <SDL.h>
#include "pandora_rp9.h"

/*
#define DBG_MAX_THREADS 128
uae_thread_id running_threads[DBG_MAX_THREADS];
char running_threads_name[DBG_MAX_THREADS][64];

void dbg_add_thread(uae_thread_id id, const char *name)
{
  int i;
  for(i=0; i<DBG_MAX_THREADS; ++i)
  {
    if(running_threads[i] == 0)
    {
      running_threads[i] = id;
      if(name != NULL)
        strncpy(running_threads_name[i], name, 64);
      else
        strncpy(running_threads_name[i], "<empty>", 64);
      write_log("dbg_add_thread: id = %d, name = %s, pos = %d\n", id, running_threads_name[i], i);
      return;
    }
  }
  write_log("dbg_add_thread: no more free entries\n");
}

void dbg_rem_thread(uae_thread_id id)
{
  int i;
  for(i=0; i<DBG_MAX_THREADS; ++i)
  {
    if(running_threads[i] == id)
    {
      write_log("dbg_rem_thread: id = %d, name = %s, pos = %d\n", id, running_threads_name[i], i);
      running_threads[i] = 0;
      return;
    }
  }
}

void dbg_list_threads(void)
{
  int i;
  for(i=0; i<DBG_MAX_THREADS; ++i)
  {
    if(running_threads[i] != 0)
    {
      write_log("dbg_list_threads: id = %d, name = %s, pos = %d\n", running_threads[i], running_threads_name[i], i);
    }
  }
}
*/

extern void signal_segv(int signum, siginfo_t* info, void*ptr);
extern void gui_force_rtarea_hdchange(void);

static int delayed_mousebutton = 0;
static int doStylusRightClick;

extern int loadconfig_old(struct uae_prefs *p, const char *orgpath);
extern void SetLastActiveConfig(const char *filename);

/* Keyboard */
int customControlMap[SDLK_LAST];

char start_path_data[MAX_DPATH];
char currentDir[MAX_DPATH];

static char config_path[MAX_DPATH];
static char rom_path[MAX_DPATH];
static char rp9_path[MAX_DPATH];
char last_loaded_config[MAX_DPATH] = { '\0' };

static bool cpuSpeedChanged = false;
static int lastCpuSpeed = 600;
int defaultCpuSpeed = 600;

int max_uae_width;
int max_uae_height;


extern "C" int main( int argc, char *argv[] );


void reinit_amiga(void)
{
  write_log("reinit_amiga() called\n");
  DISK_free ();
#ifdef CD32
	akiko_free ();
#endif
#ifdef FILESYS
  filesys_cleanup ();
  hardfile_reset();
#endif
#ifdef AUTOCONFIG
#if defined (BSDSOCKET)
  bsdlib_reset();
#endif
  expansion_cleanup ();
#endif
	device_func_reset ();
  memory_cleanup ();
  
  /* At this point, there might run some threads from bsdsocket.*/
//  write_log("Threads in reinit_amiga():\n");
//  dbg_list_threads();

  currprefs = changed_prefs;
  /* force sound settings change */
  currprefs.produce_sound = 0;

  framecnt = 1;
#ifdef AUTOCONFIG
  rtarea_setup ();
#endif
#ifdef FILESYS
  rtarea_init ();
  uaeres_install ();
  hardfile_install();
#endif
  keybuf_init();

#ifdef AUTOCONFIG
  expansion_init ();
#endif
#ifdef FILESYS
  filesys_install (); 
#endif
  memory_init ();
  memory_reset ();

#ifdef AUTOCONFIG
#if defined (BSDSOCKET)
	bsdlib_install ();
#endif
  emulib_install ();
  native2amiga_install ();
#endif

  custom_init (); /* Must come after memory_init */
  DISK_init ();
  
  reset_frame_rate_hack ();
  init_m68k();
}


void sleep_millis_main (int ms)
{
  usleep(ms * 1000);
}

void sleep_millis (int ms)
{
  usleep(ms * 1000);
}


void logging_init( void )
{
#ifdef WITH_LOGGING
  static int started;
  static int first;
  char debugfilename[MAX_DPATH];

  if (first > 1) {
  	write_log ("***** RESTART *****\n");
	  return;
  }
  if (first == 1) {
  	if (debugfile)
	    fclose (debugfile);
    debugfile = 0;
  }

	sprintf(debugfilename, "%s/uae4arm_log.txt", start_path_data);
	if(!debugfile)
    debugfile = fopen(debugfilename, "wt");

  first++;
  write_log ( "UAE4ARM Logfile\n\n");
#endif
}

void logging_cleanup( void )
{
#ifdef WITH_LOGGING
  if(debugfile)
    fclose(debugfile);
  debugfile = 0;
#endif
}


void stripslashes (TCHAR *p)
{
	while (_tcslen (p) > 0 && (p[_tcslen (p) - 1] == '\\' || p[_tcslen (p) - 1] == '/'))
		p[_tcslen (p) - 1] = 0;
}
void fixtrailing (TCHAR *p)
{
	if (_tcslen(p) == 0)
		return;
	if (p[_tcslen(p) - 1] == '/' || p[_tcslen(p) - 1] == '\\')
		return;
	_tcscat(p, "/");
}

void getpathpart (TCHAR *outpath, int size, const TCHAR *inpath)
{
	_tcscpy (outpath, inpath);
	TCHAR *p = _tcsrchr (outpath, '/');
	if (p)
		p[0] = 0;
	fixtrailing (outpath);
}
void getfilepart (TCHAR *out, int size, const TCHAR *path)
{
	out[0] = 0;
	const TCHAR *p = _tcsrchr (path, '/');
	if (p)
		_tcscpy (out, p + 1);
	else
		_tcscpy (out, path);
}


uae_u8 *target_load_keyfile (struct uae_prefs *p, const char *path, int *sizep, char *name)
{
  return 0;
}


void target_run (void)
{
}
void target_quit (void)
{
}


void target_fixup_options (struct uae_prefs *p)
{
	p->rtgmem_type = 1;
  if (p->z3fastmem_start != z3_start_adr)
  	p->z3fastmem_start = z3_start_adr;

	p->picasso96_modeflags = RGBFF_CLUT | RGBFF_R5G6B5 | RGBFF_R8G8B8A8;
  p->gfx_resolution = p->gfx_size.width > 600 ? 1 : 0;
}


void target_default_options (struct uae_prefs *p, int type)
{
  p->pandora_horizontal_offset = 0;
  p->pandora_vertical_offset = 0;
  p->pandora_cpu_speed = defaultCpuSpeed;
  p->pandora_hide_idle_led = 0;
  
  p->pandora_tapDelay = 10;
	p->pandora_customControls = 0;

	p->picasso96_modeflags = RGBFF_CLUT | RGBFF_R5G6B5 | RGBFF_R8G8B8A8;
	
#ifdef ANDROIDSDL
	p->onScreen = 1;
	p->onScreen_textinput = 1;
	p->onScreen_dpad = 1;
	p->onScreen_button1 = 1;
	p->onScreen_button2 = 1;
	p->onScreen_button3 = 1;
	p->onScreen_button4 = 1;
	p->onScreen_button5 = 0;
	p->onScreen_button6 = 0;
	p->custom_position = 0;
	p->pos_x_textinput = 0;
	p->pos_y_textinput = 0;
	p->pos_x_dpad = 4;
	p->pos_y_dpad = 215;
	p->pos_x_button1 = 430;
	p->pos_y_button1 = 286;
	p->pos_x_button2 = 378;
	p->pos_y_button2 = 286;
	p->pos_x_button3 = 430;
	p->pos_y_button3 = 214;
	p->pos_x_button4 = 378;
	p->pos_y_button4 = 214;
	p->pos_x_button5 = 430;
	p->pos_y_button5 = 142;
	p->pos_x_button6 = 378;
	p->pos_y_button6 = 142;
	p->extfilter = 1;
	p->quickSwitch = 0;
	p->floatingJoystick = 0;
	p->disableMenuVKeyb = 0;
#endif
	memset(customControlMap, 0, sizeof(customControlMap));
}


void target_save_options (struct zfile *f, struct uae_prefs *p)
{
  cfgfile_write (f, "pandora.cpu_speed", "%d", p->pandora_cpu_speed);
  cfgfile_write (f, "pandora.hide_idle_led", "%d", p->pandora_hide_idle_led);
  cfgfile_write (f, "pandora.tap_delay", "%d", p->pandora_tapDelay);
  cfgfile_write (f, "pandora.custom_controls", "%d", p->pandora_customControls);
  cfgfile_write (f, "pandora.custom_up", "%d", customControlMap[SDLK_UP]);
  cfgfile_write (f, "pandora.custom_down", "%d", customControlMap[SDLK_DOWN]);
  cfgfile_write (f, "pandora.custom_left", "%d", customControlMap[SDLK_LEFT]);
  cfgfile_write (f, "pandora.custom_right", "%d", customControlMap[SDLK_RIGHT]);
  cfgfile_write (f, "pandora.custom_a", "%d", customControlMap[SDLK_HOME]);
  cfgfile_write (f, "pandora.custom_b", "%d", customControlMap[SDLK_END]);
  cfgfile_write (f, "pandora.custom_x", "%d", customControlMap[SDLK_PAGEDOWN]);
  cfgfile_write (f, "pandora.custom_y", "%d", customControlMap[SDLK_PAGEUP]);
#ifdef ANDROIDSDL
  cfgfile_write (f, "pandora.custom_l", "%d", customControlMap[SDLK_F13]);
#else
  cfgfile_write (f, "pandora.custom_l", "%d", customControlMap[SDLK_RSHIFT]);
#endif
  cfgfile_write (f, "pandora.custom_r", "%d", customControlMap[SDLK_RCTRL]);
  cfgfile_write (f, "pandora.move_x", "%d", p->pandora_horizontal_offset);
  cfgfile_write (f, "pandora.move_y", "%d", p->pandora_vertical_offset);
#ifdef ANDROIDSDL
  cfgfile_write (f, "pandora.onscreen", "%d", p->onScreen);
  cfgfile_write (f, "pandora.onscreen_textinput", "%d", p->onScreen_textinput);
  cfgfile_write (f, "pandora.onscreen_dpad", "%d", p->onScreen_dpad);
  cfgfile_write (f, "pandora.onscreen_button1", "%d", p->onScreen_button1);
  cfgfile_write (f, "pandora.onscreen_button2", "%d", p->onScreen_button2);
  cfgfile_write (f, "pandora.onscreen_button3", "%d", p->onScreen_button3);
  cfgfile_write (f, "pandora.onscreen_button4", "%d", p->onScreen_button4);
  cfgfile_write (f, "pandora.onscreen_button5", "%d", p->onScreen_button5);
  cfgfile_write (f, "pandora.onscreen_button6", "%d", p->onScreen_button6);
  cfgfile_write (f, "pandora.custom_position", "%d", p->custom_position);
  cfgfile_write (f, "pandora.pos_x_textinput", "%d", p->pos_x_textinput);
  cfgfile_write (f, "pandora.pos_y_textinput", "%d", p->pos_y_textinput);
  cfgfile_write (f, "pandora.pos_x_dpad", "%d", p->pos_x_dpad);
  cfgfile_write (f, "pandora.pos_y_dpad", "%d", p->pos_y_dpad);
  cfgfile_write (f, "pandora.pos_x_button1", "%d", p->pos_x_button1);
  cfgfile_write (f, "pandora.pos_y_button1", "%d", p->pos_y_button1);
  cfgfile_write (f, "pandora.pos_x_button2", "%d", p->pos_x_button2);
  cfgfile_write (f, "pandora.pos_y_button2", "%d", p->pos_y_button2);
  cfgfile_write (f, "pandora.pos_x_button3", "%d", p->pos_x_button3);
  cfgfile_write (f, "pandora.pos_y_button3", "%d", p->pos_y_button3);
  cfgfile_write (f, "pandora.pos_x_button4", "%d", p->pos_x_button4);
  cfgfile_write (f, "pandora.pos_y_button4", "%d", p->pos_y_button4);
  cfgfile_write (f, "pandora.pos_x_button5", "%d", p->pos_x_button5);
  cfgfile_write (f, "pandora.pos_y_button5", "%d", p->pos_y_button5);
  cfgfile_write (f, "pandora.pos_x_button6", "%d", p->pos_x_button6);
  cfgfile_write (f, "pandora.pos_y_button6", "%d", p->pos_y_button6);
  cfgfile_write (f, "pandora.floating_joystick", "%d", p->floatingJoystick);
  cfgfile_write (f, "pandora.disable_menu_vkeyb", "%d", p->disableMenuVKeyb);
#endif
}


void target_restart (void)
{
}


TCHAR *target_expand_environment (const TCHAR *path)
{
  return strdup(path);
}

int target_parse_option (struct uae_prefs *p, const char *option, const char *value)
{
  int result = (cfgfile_intval (option, value, "cpu_speed", &p->pandora_cpu_speed, 1)
    || cfgfile_intval (option, value, "hide_idle_led", &p->pandora_hide_idle_led, 1)
    || cfgfile_intval (option, value, "tap_delay", &p->pandora_tapDelay, 1)
    || cfgfile_intval (option, value, "custom_controls", &p->pandora_customControls, 1)
    || cfgfile_intval (option, value, "custom_up", &customControlMap[SDLK_UP], 1)
    || cfgfile_intval (option, value, "custom_down", &customControlMap[SDLK_DOWN], 1)
    || cfgfile_intval (option, value, "custom_left", &customControlMap[SDLK_LEFT], 1)
    || cfgfile_intval (option, value, "custom_right", &customControlMap[SDLK_RIGHT], 1)
    || cfgfile_intval (option, value, "custom_a", &customControlMap[SDLK_HOME], 1)
    || cfgfile_intval (option, value, "custom_b", &customControlMap[SDLK_END], 1)
    || cfgfile_intval (option, value, "custom_x", &customControlMap[SDLK_PAGEDOWN], 1)
    || cfgfile_intval (option, value, "custom_y", &customControlMap[SDLK_PAGEUP], 1)
#ifdef ANDROIDSDL
    || cfgfile_intval (option, value, "custom_l", &customControlMap[SDLK_F13], 1)
#else
    || cfgfile_intval (option, value, "custom_l", &customControlMap[SDLK_RSHIFT], 1)
#endif
    || cfgfile_intval (option, value, "custom_r", &customControlMap[SDLK_RCTRL], 1)
    || cfgfile_intval (option, value, "move_x", &p->pandora_horizontal_offset, 1)
    || cfgfile_intval (option, value, "move_y", &p->pandora_vertical_offset, 1)
#ifdef ANDROIDSDL
    || cfgfile_intval (option, value, "onscreen", &p->onScreen, 1)
    || cfgfile_intval (option, value, "onscreen_textinput", &p->onScreen_textinput, 1)
    || cfgfile_intval (option, value, "onscreen_dpad", &p->onScreen_dpad, 1)
    || cfgfile_intval (option, value, "onscreen_button1", &p->onScreen_button1, 1)
    || cfgfile_intval (option, value, "onscreen_button2", &p->onScreen_button2, 1)
    || cfgfile_intval (option, value, "onscreen_button3", &p->onScreen_button3, 1)
    || cfgfile_intval (option, value, "onscreen_button4", &p->onScreen_button4, 1)
    || cfgfile_intval (option, value, "onscreen_button5", &p->onScreen_button5, 1)
    || cfgfile_intval (option, value, "onscreen_button6", &p->onScreen_button6, 1)
    || cfgfile_intval (option, value, "custom_position", &p->custom_position, 1)
    || cfgfile_intval (option, value, "pos_x_textinput", &p->pos_x_textinput, 1)
    || cfgfile_intval (option, value, "pos_y_textinput", &p->pos_y_textinput, 1)
    || cfgfile_intval (option, value, "pos_x_dpad", &p->pos_x_dpad, 1)
    || cfgfile_intval (option, value, "pos_y_dpad", &p->pos_y_dpad, 1)
    || cfgfile_intval (option, value, "pos_x_button1", &p->pos_x_button1, 1)
    || cfgfile_intval (option, value, "pos_y_button1", &p->pos_y_button1, 1)
    || cfgfile_intval (option, value, "pos_x_button2", &p->pos_x_button2, 1)
    || cfgfile_intval (option, value, "pos_y_button2", &p->pos_y_button2, 1)
    || cfgfile_intval (option, value, "pos_x_button3", &p->pos_x_button3, 1)
    || cfgfile_intval (option, value, "pos_y_button3", &p->pos_y_button3, 1)
    || cfgfile_intval (option, value, "pos_x_button4", &p->pos_x_button4, 1)
    || cfgfile_intval (option, value, "pos_y_button4", &p->pos_y_button4, 1)
    || cfgfile_intval (option, value, "pos_x_button5", &p->pos_x_button5, 1)
    || cfgfile_intval (option, value, "pos_y_button5", &p->pos_y_button5, 1)
    || cfgfile_intval (option, value, "pos_x_button6", &p->pos_x_button6, 1)
    || cfgfile_intval (option, value, "pos_y_button6", &p->pos_y_button6, 1)
    || cfgfile_intval (option, value, "floating_joystick", &p->floatingJoystick, 1)
    || cfgfile_intval (option, value, "disable_menu_vkeyb", &p->disableMenuVKeyb, 1)
#endif
    );
}


void fetch_datapath (char *out, int size)
{
  strncpy(out, start_path_data, size);
  strncat(out, "/", size);
}


void fetch_saveimagepath (char *out, int size, int dir)
{
  strncpy(out, start_path_data, size);
  strncat(out, "/savestates/", size);
}


void fetch_configurationpath (char *out, int size)
{
  strncpy(out, config_path, size);
}


void set_configurationpath(char *newpath)
{
  strncpy(config_path, newpath, MAX_DPATH);
}


void fetch_rompath (char *out, int size)
{
  strncpy(out, rom_path, size);
}


void set_rompath(char *newpath)
{
  strncpy(rom_path, newpath, MAX_DPATH);
}


void fetch_rp9path (char *out, int size)
{
  strncpy(out, rp9_path, size);
}


void fetch_savestatepath(char *out, int size)
{
  strncpy(out, start_path_data, size);
  strncat(out, "/savestates/", size);
}


void fetch_screenshotpath(char *out, int size)
{
  strncpy(out, start_path_data, size);
  strncat(out, "/screenshots/", size);
}


int target_cfgfile_load (struct uae_prefs *p, const char *filename, int type, int isdefault)
{
  int i;
  int result = 0;

  if(emulating && changed_prefs.cdslots[0].inuse)
    gui_force_rtarea_hdchange();

  discard_prefs(p, type);
  default_prefs(p, 0);
  
	char *ptr = strstr(filename, ".rp9");
  if(ptr > 0)
  {
    // Load rp9 config
    result = rp9_parse_file(p, filename);
    if(result)
      extractFileName(filename, last_loaded_config);
  }
  else 
	{
  	ptr = strstr(filename, ".uae");
    if(ptr > 0)
    {
      int type = CONFIG_TYPE_HARDWARE | CONFIG_TYPE_HOST;
      result = cfgfile_load(p, filename, &type, 0, 1);
    }
    if(result)
      extractFileName(filename, last_loaded_config);
    else 
      result = loadconfig_old(p, filename);
  }

  if(result)
  {
    for(i=0; i < p->nr_floppies; ++i)
    {
      if(!DISK_validate_filename(p, p->floppyslots[i].df, 0, NULL, NULL, NULL))
        p->floppyslots[i].df[0] = 0;
      disk_insert(i, p->floppyslots[i].df);
      if(strlen(p->floppyslots[i].df) > 0)
        AddFileToDiskList(p->floppyslots[i].df, 1);
    }

    if(!isdefault)
      inputdevice_updateconfig (NULL, p);
  
    SetLastActiveConfig(filename);

    if(count_HDs(p) > 0) // When loading a config with HDs, always do a hardreset
      gui_force_rtarea_hdchange();
  }

  return result;
}


int check_configfile(char *file)
{
  char tmp[MAX_PATH];
  
  FILE *f = fopen(file, "rt");
  if(f)
  {
    fclose(f);
    return 1;
  }
  
  strcpy(tmp, file);
	char *ptr = strstr(tmp, ".uae");
	if(ptr > 0)
  {
    *(ptr + 1) = '\0';
    strcat(tmp, "conf");
    f = fopen(tmp, "rt");
    if(f)
    {
      fclose(f);
      return 2;
    }
  }

  return 0;
}


void extractFileName(const char * str,char *buffer)
{
	const char *p=str+strlen(str)-1;
	while(*p != '/' && p > str)
		p--;
	p++;
	strcpy(buffer,p);
}


void extractPath(char *str, char *buffer)
{
	strcpy(buffer, str);
	char *p = buffer + strlen(buffer) - 1;
	while(*p != '/' && p > buffer)
		p--;
	p[1] = '\0';
}


void removeFileExtension(char *filename)
{
  char *p = filename + strlen(filename) - 1;
  while(p > filename && *p != '.')
  {
    *p = '\0';
    --p;
  }
  *p = '\0';
}


void ReadDirectory(const char *path, std::vector<std::string> *dirs, std::vector<std::string> *files)
{
  DIR *dir;
  struct dirent *dent;

  if(dirs != NULL)
    dirs->clear();
  if(files != NULL)
    files->clear();
  
  dir = opendir(path);
  if(dir != NULL)
  {
    while((dent = readdir(dir)) != NULL)
    {
      if(dent->d_type == DT_DIR)
      {
        if(dirs != NULL)
          dirs->push_back(dent->d_name);
      }
      else if (files != NULL)
        files->push_back(dent->d_name);
    }
    if(dirs != NULL && dirs->size() > 0 && (*dirs)[0] == ".")
      dirs->erase(dirs->begin());
    closedir(dir);
  }
  
  if(dirs != NULL)
    std::sort(dirs->begin(), dirs->end());
  if(files != NULL)
    std::sort(files->begin(), files->end());
}


void saveAdfDir(void)
{
	char path[MAX_DPATH];
	int i;
	
	snprintf(path, MAX_DPATH, "%s/conf/adfdir.conf", start_path_data);
	FILE *f=fopen(path,"w");
	if (!f)
	  return;
	  
	char buffer[MAX_DPATH];
    
	snprintf(buffer, MAX_DPATH, "path=%s\n", currentDir);
	fputs(buffer,f);

	snprintf(buffer, MAX_DPATH, "config_path=%s\n", config_path);
	fputs(buffer, f);

	snprintf(buffer, MAX_DPATH, "rom_path=%s\n", rom_path);
	fputs(buffer, f);

  snprintf(buffer, MAX_DPATH, "ROMs=%d\n", lstAvailableROMs.size());
  fputs(buffer, f);
  for(i=0; i<lstAvailableROMs.size(); ++i)
  {
    snprintf(buffer, MAX_DPATH, "ROMName=%s\n", lstAvailableROMs[i]->Name);
    fputs(buffer, f);
    snprintf(buffer, MAX_DPATH, "ROMPath=%s\n", lstAvailableROMs[i]->Path);
    fputs(buffer, f);
    snprintf(buffer, MAX_DPATH, "ROMType=%d\n", lstAvailableROMs[i]->ROMType);
    fputs(buffer, f);
  }
  
  snprintf(buffer, MAX_DPATH, "MRUDiskList=%d\n", lstMRUDiskList.size());
  fputs(buffer, f);
  for(i=0; i<lstMRUDiskList.size(); ++i)
  {
    snprintf(buffer, MAX_DPATH, "Diskfile=%s\n", lstMRUDiskList[i].c_str());
    fputs(buffer, f);
  }

  snprintf(buffer, MAX_DPATH, "MRUCDList=%d\n", lstMRUCDList.size());
  fputs(buffer, f);
  for(i=0; i<lstMRUCDList.size(); ++i)
  {
    snprintf(buffer, MAX_DPATH, "CDfile=%s\n", lstMRUCDList[i].c_str());
    fputs(buffer, f);
  }

	fclose(f);
	return;
}


void get_string(FILE *f, char *dst, int size)
{
  char buffer[MAX_PATH];
  fgets(buffer, MAX_PATH, f);
  int i = strlen (buffer);
  while (i > 0 && (buffer[i - 1] == '\t' || buffer[i - 1] == ' ' 
  || buffer[i - 1] == '\r' || buffer[i - 1] == '\n'))
	  buffer[--i] = '\0';
  strncpy(dst, buffer, size);
}


void loadAdfDir(void)
{
	char path[MAX_DPATH];
  int i;
#ifdef ANDROID
	strcpy(currentDir, getenv("SDCARD"));
#else
	strcpy(currentDir, start_path_data);
#endif
	snprintf(config_path, MAX_DPATH, "%s/conf/", start_path_data);
#ifdef ANDROID
    char afepath[MAX_DPATH];
    snprintf(afepath, MAX_DPATH, "%s/Android/data/com.cloanto.amigaforever.essentials/files/rom/", getenv("SDCARD"));
    DIR *afedir = opendir(afepath);
    if (afedir) {
        snprintf(rom_path, MAX_DPATH, afepath);
        closedir(afedir);
    }
	else
        snprintf(rom_path, MAX_DPATH, "%s/kickstarts/", start_path_data);
#else
	snprintf(rom_path, MAX_DPATH, "%s/kickstarts/", start_path_data);
#endif
	snprintf(rp9_path, MAX_DPATH, "%s/rp9/", start_path_data);

	snprintf(path, MAX_DPATH, "%s/conf/adfdir.conf", start_path_data);
	FILE *f1=fopen(path,"rt");
	if(f1)
	{
		fscanf(f1, "path=");
		get_string(f1, currentDir, sizeof(currentDir));
		if(!feof(f1))
		{
		  fscanf(f1, "config_path=");
		  get_string(f1, config_path, sizeof(config_path));
		  fscanf(f1, "rom_path=");
      get_string(f1, rom_path, sizeof(rom_path));
      
      int numROMs;
      fscanf(f1, "ROMs=%d\n", &numROMs);
      for(i=0; i<numROMs; ++i)
      {
        AvailableROM *tmp;
        tmp = new AvailableROM();
        fscanf(f1, "ROMName=");
        get_string(f1, tmp->Name, sizeof(tmp->Name));
        fscanf(f1, "ROMPath=");
        get_string(f1, tmp->Path, sizeof(tmp->Path));
        fscanf(f1, "ROMType=%d\n", &(tmp->ROMType));
        lstAvailableROMs.push_back(tmp);
      }
      
      lstMRUDiskList.clear();
      int numDisks = 0;
      char disk[MAX_PATH];
      fscanf(f1, "MRUDiskList=%d\n", &numDisks);
      for(i=0; i<numDisks; ++i)
      {
        fscanf(f1, "Diskfile=");
        get_string(f1, disk, sizeof(disk));
        FILE *f = fopen(disk, "rb");
        if(f != NULL)
        {
          fclose(f);
          lstMRUDiskList.push_back(disk);
        }
      }

      lstMRUCDList.clear();
      int numCD = 0;
      char cd[MAX_PATH];
      fscanf(f1, "MRUCDList=%d\n", &numCD);
      for(i=0; i<numCD; ++i)
      {
        fscanf(f1, "CDfile=");
        get_string(f1, cd, sizeof(cd));
        FILE *f = fopen(cd, "rb");
        if(f != NULL)
        {
          fclose(f);
          lstMRUCDList.push_back(cd);
        }
      }
	  }
		fclose(f1);
	}
}


int currVSyncRate = 0;
bool SetVSyncRate(int hz)
{
	char cmd[64];
  
  if(currVSyncRate != hz)
  {
    snprintf((char*)cmd, 64, "sudo /usr/pandora/scripts/op_lcdrate.sh %d", hz);
    system(cmd);
    currVSyncRate = hz;
    return true;
  }
  return false;
}

void setCpuSpeed()
{
	char speedCmd[128];

#ifdef ANDROID
	return;
#endif
	
  currprefs.pandora_cpu_speed = changed_prefs.pandora_cpu_speed;

	if(currprefs.pandora_cpu_speed != lastCpuSpeed)
	{
		snprintf((char*)speedCmd, 128, "unset DISPLAY; echo y | sudo -n /usr/pandora/scripts/op_cpuspeed.sh %d", currprefs.pandora_cpu_speed);
		system(speedCmd);
		lastCpuSpeed = currprefs.pandora_cpu_speed;
		cpuSpeedChanged = true;
	}
	if(changed_prefs.ntscmode != currprefs.ntscmode)
	{
		if(changed_prefs.ntscmode)
			SetVSyncRate(60);
		else
			SetVSyncRate(50);
	}
}


int getDefaultCpuSpeed(void)
{
  int speed = 600;
  FILE* f = fopen ("/etc/pandora/conf/cpu.conf", "rt");
  if(f)
  {
    char line[128];
    for(int i=0; i<6; ++i)
    {
      fscanf(f, "%s\n", &line);
      if(strncmp(line, "default:", 8) == 0)
      {
        int value = 0;
        sscanf(line, "default:%d", &value);
        if(value > 500 && value < 1200)
        {
          speed = value;
        }
      }
    }
    fclose(f);
  }
  return speed;
}


void resetCpuSpeed(void)
{
  if(cpuSpeedChanged)
  {
    lastCpuSpeed = defaultCpuSpeed - 10;
    currprefs.pandora_cpu_speed = changed_prefs.pandora_cpu_speed = defaultCpuSpeed;
    setCpuSpeed();
  }
}


void target_reset (void)
{
}

uae_u32 emulib_target_getcpurate (uae_u32 v, uae_u32 *low)
{
  *low = 0;
  if (v == 1) {
    *low = 1e+9; /* We have nano seconds */
    return 0;
  } else if (v == 2) {
    int64_t time;
    struct timespec ts;
    clock_gettime (CLOCK_MONOTONIC, &ts);
    time = (((int64_t) ts.tv_sec) * 1000000000) + ts.tv_nsec;
    *low = (uae_u32) (time & 0xffffffff);
    return (uae_u32)(time >> 32);
  }
  return 0;
}

int main (int argc, char *argv[])
{
  struct sigaction action;
  
	max_uae_width = 768;
	max_uae_height = 270;

  defaultCpuSpeed = getDefaultCpuSpeed();
  
  // Get startup path
	getcwd(start_path_data, MAX_DPATH);
	loadAdfDir();
  rp9_init();

  snprintf(savestate_fname, MAX_PATH, "%s/saves/default.ads", start_path_data);
	logging_init ();
  
  memset(&action, 0, sizeof(action));
  action.sa_sigaction = signal_segv;
  action.sa_flags = SA_SIGINFO;
  if(sigaction(SIGSEGV, &action, NULL) < 0)
  {
    printf("Failed to set signal handler (SIGSEGV).\n");
    abort();
  }
  if(sigaction(SIGILL, &action, NULL) < 0)
  {
    printf("Failed to set signal handler (SIGILL).\n");
    abort();
  }

  alloc_AmigaMem();
  RescanROMs();

  keyboard_settrans();  
  real_main (argc, argv);
  
  ClearAvailableROMList();
  romlist_clear();
  free_keyring();
  free_AmigaMem();
  lstMRUDiskList.clear();
  lstMRUCDList.clear();
  rp9_cleanup();
  
  logging_cleanup();

//  printf("Threads at exit:\n");
//  dbg_list_threads();
  
  return 0;
}


int handle_msgpump (void)
{
	int got = 0;
  SDL_Event rEvent;
  int keycode;
  int modifier;
  int handled = 0;
  int i;
  
  if(delayed_mousebutton) {
    --delayed_mousebutton;
    if(delayed_mousebutton == 0)
      setmousebuttonstate (0, 0, 1);
  }
  
	while (SDL_PollEvent(&rEvent)) {
		got = 1;
		
		switch (rEvent.type)
		{
  		case SDL_QUIT:
  			uae_quit();
  			break;
  			
  		case SDL_KEYDOWN:
  		  switch(rEvent.key.keysym.sym)
  		  {
#ifdef ANDROID
		    case SDLK_F12: // Select key
#else
  		    case SDLK_LCTRL: // Select key
#endif
  		      inputdevice_add_inputcode (AKS_ENTERGUI, 1);
  		      break;

		    case SDLK_LSHIFT: // Shift key
                        inputdevice_do_keyboard(AK_LSH, 1);
                        break;
#ifdef ANDROID
		    case SDLK_LCTRL:
                        inputdevice_do_keyboard(AK_CTRL, 1);
                        break;
		    case SDLK_RSHIFT:
                        inputdevice_do_keyboard(AK_RSH, 1);
                        break;
		    case SDLK_LALT:
                        inputdevice_do_keyboard(AK_LALT, 1);
                        break;
		    case SDLK_RALT:
                        inputdevice_do_keyboard(AK_RALT, 1);
                        break;
		    case SDLK_LMETA:
                        inputdevice_do_keyboard(AK_LAMI, 1);
                        break;
		    case SDLK_RMETA:
                        inputdevice_do_keyboard(AK_RAMI, 1);
                        break;
		    case SDLK_CAPSLOCK:
                        inputdevice_do_keyboard(AK_CAPSLOCK, 1);
                        break;
		    case SDLK_INSERT:
                        inputdevice_do_keyboard(AK_HELP, 1);
                        break;
		    case SDLK_KP_DIVIDE:
                        inputdevice_do_keyboard(AK_NPDIV, 1);
                        break;
		    case SDLK_KP_MINUS:
                        inputdevice_do_keyboard(AK_NPSUB, 1);
                        break;
		    case SDLK_KP_ENTER:
                        inputdevice_do_keyboard(AK_ENT, 1);
                        break;
		    case SDLK_KP_PERIOD:
                        inputdevice_do_keyboard(AK_NPDEL, 1);
                        break;
		    case SDLK_KP0:
                        inputdevice_do_keyboard(AK_NP0, 1);
                        break;
		    case SDLK_KP1:
                        inputdevice_do_keyboard(AK_NP1, 1);
                        break;
		    case SDLK_KP2:
                        inputdevice_do_keyboard(AK_NP2, 1);
                        break;
		    case SDLK_KP3:
                        inputdevice_do_keyboard(AK_NP3, 1);
                        break;
		    case SDLK_KP4:
                        inputdevice_do_keyboard(AK_NP4, 1);
                        break;
		    case SDLK_KP5:
                        inputdevice_do_keyboard(AK_NP5, 1);
                        break;
		    case SDLK_KP6:
                        inputdevice_do_keyboard(AK_NP6, 1);
                        break;
		    case SDLK_KP7:
                        inputdevice_do_keyboard(AK_NP7, 1);
                        break;
		    case SDLK_KP8:
                        inputdevice_do_keyboard(AK_NP8, 1);
                        break;
		    case SDLK_KP9:
                        inputdevice_do_keyboard(AK_NP9, 1);
                        break;
#endif
#ifdef ANDROIDSDL
				  case SDLK_F13: // Left shoulder button
#else
				  case SDLK_RSHIFT: // Left shoulder button
#endif
				  case SDLK_RCTRL:  // Right shoulder button
  					if(currprefs.input_tablet > TABLET_OFF) {
  					  // Holding left or right shoulder button -> stylus does right mousebutton
  					  doStylusRightClick = 1;
            }
            // Fall through...
            
  				default:
  				  if(currprefs.pandora_customControls) {
  				    keycode = customControlMap[rEvent.key.keysym.sym];
  				    if(keycode < 0) {
  				      // Simulate mouse or joystick
  				      SimulateMouseOrJoy(keycode, 1);
  				      break;
  				    }
  				    else if(keycode > 0) {
  				      // Send mapped key press
  				      inputdevice_do_keyboard(keycode, 1);
  				      break;
  				    }
  				  }
  				    
				    // Handle Pandora specific functions
				    if(rEvent.key.keysym.mod == (KMOD_RCTRL | KMOD_RSHIFT)) {
              // Left and right shoulder
  				    switch(rEvent.key.keysym.sym) {
  				      case SDLK_UP:  // Left and right shoulder + UP -> move display up
  				        moveVertical(1);
  				        handled = 1;
  				        break;
  				        
  				      case SDLK_DOWN:  // Left and right shoulder + DOWN -> move display down
  				        moveVertical(-1);
  				        handled = 1;
  				        break;
  				        
  				      case SDLK_1:
  				      case SDLK_2:
  				      case SDLK_3:
  				      case SDLK_4:
  				      case SDLK_5:
  				      case SDLK_6:
  				        // Change display height direct
  				        changed_prefs.gfx_size.height = amigaheight_values[rEvent.key.keysym.sym - SDLK_1];
  				        update_display(&changed_prefs);
  				        handled = 1;
  				        break;

                case SDLK_9:  // Select next lower display height
            			for(i=0; i<AMIGAHEIGHT_COUNT; ++i)
            			{
            			  if(currprefs.gfx_size.height == amigaheight_values[i])
            		    {
            		      if(i > 0)
            		        changed_prefs.gfx_size.height = amigaheight_values[i - 1];
            		      else
            		        changed_prefs.gfx_size.height = amigaheight_values[AMIGAHEIGHT_COUNT - 1];
            		      break;
            		    }
            			}
            			update_display(&changed_prefs);
  				        handled = 1;
  				        break;

                case SDLK_0:  // Select next higher display height
            			for(i=0; i<AMIGAHEIGHT_COUNT; ++i)
            			{
            			  if(currprefs.gfx_size.height == amigaheight_values[i])
            		    {
            		      if(i < AMIGAHEIGHT_COUNT - 1)
            		        changed_prefs.gfx_size.height = amigaheight_values[i + 1];
            		      else
            		        changed_prefs.gfx_size.height = amigaheight_values[0];
            		      break;
            		    }
            			}
            			update_display(&changed_prefs);
  				        handled = 1;
  				        break;

                case SDLK_w:  // Select next display width
            			for(i=0; i<AMIGAWIDTH_COUNT; ++i)
            			{
            			  if(currprefs.gfx_size.width == amigawidth_values[i])
            		    {
            		      if(i < AMIGAWIDTH_COUNT - 1)
            		        changed_prefs.gfx_size.width = amigawidth_values[i + 1];
            		      else
            		        changed_prefs.gfx_size.width = amigawidth_values[0];
            		      break;
            		    }
            			}
            			update_display(&changed_prefs);
  				        handled = 1;
  				        break;

                case SDLK_r:
            		  // Toggle resolution (lores/hires)
            		  if(currprefs.gfx_size.width > 600)
            		    changed_prefs.gfx_size.width = currprefs.gfx_size.width / 2;
            		  else
            		    changed_prefs.gfx_size.width = currprefs.gfx_size.width * 2;
            			update_display(&changed_prefs);
  				        handled = 1;
  				        break;

              }              
            }
				    else if(rEvent.key.keysym.mod == KMOD_RSHIFT)
			      {
			        // Left shoulder
  				    switch(rEvent.key.keysym.sym) {
  				      case SDLK_c:  // Left shoulder + c -> toggle "Custom control"
  				        currprefs.pandora_customControls = !currprefs.pandora_customControls;
  				        changed_prefs.pandora_customControls = currprefs.pandora_customControls;
  				        handled = 1;
  				        break;
  				        
  				      case SDLK_d:  // Left shoulder + d -> toggle "Status line"
  			          changed_prefs.leds_on_screen = !changed_prefs.leds_on_screen;
  				        handled = 1;
  				        break;
  				        
  				      case SDLK_f:  // Left shoulder + f -> toggle frameskip
  				        changed_prefs.gfx_framerate ? changed_prefs.gfx_framerate = 0 : changed_prefs.gfx_framerate = 1;
  				        handled = 1;
				          break;
				          
				        case SDLK_s:  // Left shoulder + s -> store savestate
				          savestate_state = STATE_DOSAVE;
  				        handled = 1;
				          break;
				          
				        case SDLK_l:  // Left shoulder + l -> load savestate
                	{
                		FILE *f=fopen(savestate_fname, "rb");
                		if(f)
                		{
                			fclose(f);
                			savestate_state = STATE_DORESTORE;
                		}
                	}
  				        handled = 1;
                	break;
  			      }
				    }

            if(!handled) {
    				  modifier = rEvent.key.keysym.mod;
    				  keycode = translate_pandora_keys(rEvent.key.keysym.sym, &modifier);
    				  if(keycode)
    				  {
  				      if(modifier == KMOD_SHIFT)
    				      inputdevice_do_keyboard(AK_LSH, 1);
    				    else
    				      inputdevice_do_keyboard(AK_LSH, 0);
  				      inputdevice_do_keyboard(keycode, 1);
    				  } else {
  				      inputdevice_translatekeycode(0, rEvent.key.keysym.sym, 1);
  				    }
            }
            				    				  
  				  break;
				}
        break;
        
  	  case SDL_KEYUP:
  	    switch(rEvent.key.keysym.sym)
  	    {
#ifdef ANDROID
		    case SDLK_F12: // Select key
#else
  		    case SDLK_LCTRL: // Select key
#endif
  		      break;

		    case SDLK_LSHIFT: // Shift key
                        inputdevice_do_keyboard(AK_LSH, 0);
                        break;
#ifdef ANDROID
		    case SDLK_LCTRL:
                        inputdevice_do_keyboard(AK_CTRL, 0);
                        break;
		    case SDLK_RSHIFT:
                        inputdevice_do_keyboard(AK_RSH, 0);
                        break;
		    case SDLK_LALT:
                        inputdevice_do_keyboard(AK_LALT, 0);
                        break;
		    case SDLK_RALT:
                        inputdevice_do_keyboard(AK_RALT, 0);
                        break;
		    case SDLK_LMETA:
                        inputdevice_do_keyboard(AK_LAMI, 0);
                        break;
		    case SDLK_RMETA:
                        inputdevice_do_keyboard(AK_RAMI, 0);
                        break;
		    case SDLK_CAPSLOCK:
                        inputdevice_do_keyboard(AK_CAPSLOCK, 0);
                        break;
		    case SDLK_INSERT:
                        inputdevice_do_keyboard(AK_HELP, 0);
                        break;
		    case SDLK_KP_DIVIDE:
                        inputdevice_do_keyboard(AK_NPDIV, 0);
                        break;
		    case SDLK_KP_MINUS:
                        inputdevice_do_keyboard(AK_NPSUB, 0);
                        break;
		    case SDLK_KP_ENTER:
                        inputdevice_do_keyboard(AK_ENT, 0);
                        break;
		    case SDLK_KP_PERIOD:
                        inputdevice_do_keyboard(AK_NPDEL, 0);
                        break;
		    case SDLK_KP0:
                        inputdevice_do_keyboard(AK_NP0, 0);
                        break;
		    case SDLK_KP1:
                        inputdevice_do_keyboard(AK_NP1, 0);
                        break;
		    case SDLK_KP2:
                        inputdevice_do_keyboard(AK_NP2, 0);
                        break;
		    case SDLK_KP3:
                        inputdevice_do_keyboard(AK_NP3, 0);
                        break;
		    case SDLK_KP4:
                        inputdevice_do_keyboard(AK_NP4, 0);
                        break;
		    case SDLK_KP5:
                        inputdevice_do_keyboard(AK_NP5, 0);
                        break;
		    case SDLK_KP6:
                        inputdevice_do_keyboard(AK_NP6, 0);
                        break;
		    case SDLK_KP7:
                        inputdevice_do_keyboard(AK_NP7, 0);
                        break;
		    case SDLK_KP8:
                        inputdevice_do_keyboard(AK_NP8, 0);
                        break;
		    case SDLK_KP9:
                        inputdevice_do_keyboard(AK_NP9, 0);
                        break;
#endif
#ifdef ANDROIDSDL
				  case SDLK_F13: // Left shoulder button
#else
				  case SDLK_RSHIFT: // Left shoulder button
#endif
				  case SDLK_RCTRL:  // Right shoulder button

  					if(currprefs.input_tablet > TABLET_OFF) {
  					  // Release left or right shoulder button -> stylus does left mousebutton
    					doStylusRightClick = 0;
            }
            // Fall through...
  				
  				default:
  				  if(currprefs.pandora_customControls) {
  				    keycode = customControlMap[rEvent.key.keysym.sym];
  				    if(keycode < 0) {
  				      // Simulate mouse or joystick
  				      SimulateMouseOrJoy(keycode, 0);
  				      break;
  				    }
  				    else if(keycode > 0) {
  				      // Send mapped key release
  				      inputdevice_do_keyboard(keycode, 0);
  				      break;
  				    }
  				  }

  				  modifier = rEvent.key.keysym.mod;
  				  keycode = translate_pandora_keys(rEvent.key.keysym.sym, &modifier);
  				  if(keycode)
  				  {
				      inputdevice_do_keyboard(keycode, 0);
				      if(modifier == KMOD_SHIFT)
  				      inputdevice_do_keyboard(AK_LSH, 0);
            } else {
				      inputdevice_translatekeycode(0, rEvent.key.keysym.sym, 0);
				    }
  				  break;
  	    }
  	    break;
  	    
  	  case SDL_MOUSEBUTTONDOWN:
        if(currprefs.jports[0].id == JSEM_MICE || currprefs.jports[1].id == JSEM_MICE) {
    	    if(rEvent.button.button == SDL_BUTTON_LEFT) {
    	      if(currprefs.input_tablet > TABLET_OFF && !doStylusRightClick) {
    	        // Delay mousebutton, we need new position first...
    	        delayed_mousebutton = currprefs.pandora_tapDelay << 1;
    	      } else {
      	      setmousebuttonstate (0, doStylusRightClick, 1);
      	    }
    	    }
    	    else if(rEvent.button.button == SDL_BUTTON_RIGHT)
    	      setmousebuttonstate (0, 1, 1);
        }
  	    break;

  	  case SDL_MOUSEBUTTONUP:
        if(currprefs.jports[0].id == JSEM_MICE || currprefs.jports[1].id == JSEM_MICE) {
    	    if(rEvent.button.button == SDL_BUTTON_LEFT) {
  	        setmousebuttonstate (0, doStylusRightClick, 0);
          }
    	    else if(rEvent.button.button == SDL_BUTTON_RIGHT)
    	      setmousebuttonstate (0, 1, 0);
        }
  	    break;
  	    
  		case SDL_MOUSEMOTION:
  		  if(currprefs.input_tablet == TABLET_OFF) {
          if(currprefs.jports[0].id == JSEM_MICE || currprefs.jports[1].id == JSEM_MICE) {
  			    int x, y;
    		    int mouseScale = currprefs.input_joymouse_multiplier / 2;
            x = rEvent.motion.xrel;
    				y = rEvent.motion.yrel;
    				if(rEvent.motion.x == 0 && x > -4)
    					x = -4;
    				if(rEvent.motion.y == 0 && y > -4)
    					y = -4;
    				if(rEvent.motion.x == currprefs.gfx_size.width - 1 && x < 4)
    					x = 4;
    				if(rEvent.motion.y == currprefs.gfx_size.height - 1 && y < 4)
    					y = 4;
  				  setmousestate(0, 0, x * mouseScale, 0);
        	  setmousestate(0, 1, y * mouseScale, 0);
          }
        }
        break;
		}
	}
	return got;
}


static uaecptr clipboard_data;

void amiga_clipboard_die (void)
{
}

void amiga_clipboard_init (void)
{
}

void amiga_clipboard_task_start (uaecptr data)
{
  clipboard_data = data;
}

uae_u32 amiga_clipboard_proc_start (void)
{
  return clipboard_data;
}

void amiga_clipboard_got_data (uaecptr data, uae_u32 size, uae_u32 actual)
{
}

int amiga_clipboard_want_data (void)
{
  return 0;
}

void clipboard_vsync (void)
{
}
