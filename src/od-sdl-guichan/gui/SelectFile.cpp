#include <algorithm>
#include <guichan.hpp>
#include <iostream>
#include <sstream>
#include <SDL/SDL_ttf.h>
#include <guichan/sdl.hpp>
#include "sdltruetypefont.hpp"
#include "SelectorEntry.hpp"

#include "sysconfig.h"
#include "sysdeps.h"
#include "config.h"
#include "uae.h"
#include "gui.h"
#include "gui_handling.h"


#define DIALOG_WIDTH 520
#define DIALOG_HEIGHT 400

static bool dialogResult = false;
static bool dialogFinished = false;
static char workingDir[MAX_PATH];
static const char **filefilter;

static gcn::Window *wndSelectFile;
static gcn::Button* cmdOK;
static gcn::Button* cmdCancel;
static gcn::ListBox* lstFiles;
static gcn::ScrollArea* scrAreaFiles;
static gcn::TextField *txtCurrent;


class SelectFileListModel : public gcn::ListModel
{
  std::vector<std::string> dirs;
  std::vector<std::string> files;

  public:
    SelectFileListModel(const char * path)
    {
      changeDir(path);
    }
      
    int getNumberOfElements()
    {
      return dirs.size() + files.size();
    }
      
    std::string getElementAt(int i)
    {
      if(i >= dirs.size() + files.size() || i < 0)
        return "---";
      if(i < dirs.size())
        return dirs[i];
      return files[i - dirs.size()];
    }
      
    void changeDir(const char *path)
    {
      ReadDirectory(path, &dirs, &files);
      if(dirs.size() == 0)
        dirs.push_back("..");
      FilterFiles(&files, filefilter);
    }

    bool isDir(int i)
    {
      return (i < dirs.size());
    }
};
static SelectFileListModel *fileList;


class FileButtonActionListener : public gcn::ActionListener
{
  public:
    void action(const gcn::ActionEvent& actionEvent)
    {
      if (actionEvent.getSource() == cmdOK)
      {
        int selected_item;
        selected_item = lstFiles->getSelected();
        if(fileList->isDir(selected_item))
          return; // Directory selected -> Ok not possible
        strcat(workingDir, "/");
        strcat(workingDir, fileList->getElementAt(selected_item).c_str());
        dialogResult = true;
      }
      dialogFinished = true;
    }
};
static FileButtonActionListener* fileButtonActionListener;


static void checkfoldername (char *current)
{
	char *ptr;
	char actualpath [MAX_PATH];
	DIR *dir;
	
	if (dir = opendir(current))
	{ 
	  fileList->changeDir(current);
	  ptr = realpath(current, actualpath);
	  strcpy(workingDir, ptr);
	  closedir(dir);
	}
  else
    strcpy(workingDir, start_path_data);
  txtCurrent->setText(workingDir);
}

static void checkfilename(char *current)
{
  char actfile[MAX_PATH];
  extractFileName(current, actfile);
  for(int i=0; i<fileList->getNumberOfElements(); ++i)
  {
    if(!fileList->isDir(i) && !strcasecmp(fileList->getElementAt(i).c_str(), actfile))
    {
      lstFiles->setSelected(i);
      break;
    }
  }
}


class SelectFileActionListener : public gcn::ActionListener
{
  public:
    void action(const gcn::ActionEvent& actionEvent)
    {
      int selected_item;
      char foldername[256] = "";

      selected_item = lstFiles->getSelected();
      strcpy(foldername, workingDir);
      strcat(foldername, "/");
      strcat(foldername, fileList->getElementAt(selected_item).c_str());
      if(fileList->isDir(selected_item))
        checkfoldername(foldername);
      else
      {
        strncpy(workingDir, foldername, sizeof(workingDir));
        dialogResult = true;
        dialogFinished = true;
      }
    }
};
static SelectFileActionListener* selectFileActionListener;


static void InitSelectFile(const char *title)
{
	wndSelectFile = new gcn::Window("Load");
	wndSelectFile->setSize(DIALOG_WIDTH, DIALOG_HEIGHT);
  wndSelectFile->setPosition((GUI_WIDTH - DIALOG_WIDTH) / 2, (GUI_HEIGHT - DIALOG_HEIGHT) / 2);
  wndSelectFile->setBaseColor(gui_baseCol + 0x202020);
  wndSelectFile->setCaption(title);
  wndSelectFile->setTitleBarHeight(TITLEBAR_HEIGHT);
  
  fileButtonActionListener = new FileButtonActionListener();
  
	cmdOK = new gcn::Button("Ok");
	cmdOK->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	cmdOK->setPosition(DIALOG_WIDTH - DISTANCE_BORDER - 2 * BUTTON_WIDTH - DISTANCE_NEXT_X, DIALOG_HEIGHT - 2 * DISTANCE_BORDER - BUTTON_HEIGHT - 10);
  cmdOK->setBaseColor(gui_baseCol + 0x202020);
  cmdOK->addActionListener(fileButtonActionListener);
  
	cmdCancel = new gcn::Button("Cancel");
	cmdCancel->setSize(BUTTON_WIDTH, BUTTON_HEIGHT);
	cmdCancel->setPosition(DIALOG_WIDTH - DISTANCE_BORDER - BUTTON_WIDTH, DIALOG_HEIGHT - 2 * DISTANCE_BORDER - BUTTON_HEIGHT - 10);
  cmdCancel->setBaseColor(gui_baseCol + 0x202020);
  cmdCancel->addActionListener(fileButtonActionListener);

  txtCurrent = new gcn::TextField();
  txtCurrent->setSize(DIALOG_WIDTH - 2 * DISTANCE_BORDER - 4, TEXTFIELD_HEIGHT);
  txtCurrent->setPosition(DISTANCE_BORDER, 10);
  txtCurrent->setEnabled(false);

  selectFileActionListener = new SelectFileActionListener();
  fileList = new SelectFileListModel(".");

  lstFiles = new gcn::ListBox(fileList);
  lstFiles->setSize(800, 252);
  lstFiles->setBaseColor(gui_baseCol);
  lstFiles->setWrappingEnabled(true);
  lstFiles->addActionListener(selectFileActionListener);
  
  scrAreaFiles = new gcn::ScrollArea(lstFiles);
  scrAreaFiles->setFrameSize(1);
  scrAreaFiles->setPosition(DISTANCE_BORDER, 10 + TEXTFIELD_HEIGHT + 10);
  scrAreaFiles->setSize(DIALOG_WIDTH - 2 * DISTANCE_BORDER - 4, 272);
  scrAreaFiles->setScrollbarWidth(20);
  scrAreaFiles->setBaseColor(gui_baseCol + 0x202020);
  
  wndSelectFile->add(cmdOK);
  wndSelectFile->add(cmdCancel);
  wndSelectFile->add(txtCurrent);
  wndSelectFile->add(scrAreaFiles);
  
  gui_top->add(wndSelectFile);
  
  lstFiles->requestFocus();
  lstFiles->setSelected(0);
  wndSelectFile->requestModalFocus();
}


static void ExitSelectFile(void)
{
  wndSelectFile->releaseModalFocus();
  gui_top->remove(wndSelectFile);

  delete cmdOK;
  delete cmdCancel;
  delete fileButtonActionListener;
  
  delete txtCurrent;
  delete lstFiles;
  delete scrAreaFiles;
  delete selectFileActionListener;
  delete fileList;
  
  delete wndSelectFile;
}


static void SelectFileLoop(void)
{
  while(!dialogFinished)
  {
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
      if (event.type == SDL_KEYDOWN)
      {
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            dialogFinished = true;
            break;
            
          case SDLK_LEFT:
            {
              gcn::FocusHandler* focusHdl = gui_top->_getFocusHandler();
              gcn::Widget* activeWidget = focusHdl->getFocused();
              if(activeWidget == lstFiles)
                cmdCancel->requestFocus();
              else if(activeWidget == cmdCancel)
                cmdOK->requestFocus();
              else if(activeWidget == cmdOK)
                lstFiles->requestFocus();
              continue;
            }
            break;
            
          case SDLK_RIGHT:
            {
              gcn::FocusHandler* focusHdl = gui_top->_getFocusHandler();
              gcn::Widget* activeWidget = focusHdl->getFocused();
              if(activeWidget == lstFiles)
                cmdOK->requestFocus();
              else if(activeWidget == cmdCancel)
                lstFiles->requestFocus();
              else if(activeWidget == cmdOK)
                cmdCancel->requestFocus();
              continue;
            }
            break;

          case SDLK_PAGEDOWN:
          case SDLK_HOME:
            event.key.keysym.sym = SDLK_RETURN;
            gui_input->pushInput(event); // Fire key down
            event.type = SDL_KEYUP;  // and the key up
            break;
        }
      }

      //-------------------------------------------------
      // Send event to guichan-controls
      //-------------------------------------------------
#ifdef ANDROID
            /*
             * Now that we are done polling and using SDL events we pass
             * the leftovers to the SDLInput object to later be handled by
             * the Gui. (This example doesn't require us to do this 'cause a
             * label doesn't use input. But will do it anyway to show how to
             * set up an SDL application with Guichan.)
             */
            if (event.type == SDL_MOUSEMOTION ||
                event.type == SDL_MOUSEBUTTONDOWN ||
                event.type == SDL_MOUSEBUTTONUP) {
                // Filter emulated mouse events for Guichan, we wand absolute input
            } else {
                // Convert multitouch event to SDL mouse event
                static int x = 0, y = 0, buttons = 0, wx=0, wy=0, pr=0;
                SDL_Event event2;
                memcpy(&event2, &event, sizeof(event));
                if (event.type == SDL_JOYBALLMOTION &&
                    event.jball.which == 0 &&
                    event.jball.ball == 0) {
                    event2.type = SDL_MOUSEMOTION;
                    event2.motion.which = 0;
                    event2.motion.state = buttons;
                    event2.motion.xrel = event.jball.xrel - x;
                    event2.motion.yrel = event.jball.yrel - y;
                    if (event.jball.xrel!=0) {
                        x = event.jball.xrel;
                        y = event.jball.yrel;
                    }
                    event2.motion.x = x;
                    event2.motion.y = y;
                    //__android_log_print(ANDROID_LOG_INFO, "GUICHAN","Mouse motion %d %d btns %d", x, y, buttons);
                    if (buttons == 0) {
                        // Push mouse motion event first, then button down event
                        gui_input->pushInput(event2);
                        buttons = SDL_BUTTON_LMASK;
                        event2.type = SDL_MOUSEBUTTONDOWN;
                        event2.button.which = 0;
                        event2.button.button = SDL_BUTTON_LEFT;
                        event2.button.state =  SDL_PRESSED;
                        event2.button.x = x;
                        event2.button.y = y;
                        //__android_log_print(ANDROID_LOG_INFO, "GUICHAN","Mouse button %d coords %d %d", buttons, x, y);
                    }
                }
                if (event.type == SDL_JOYBUTTONUP &&
                    event.jbutton.which == 0 &&
                    event.jbutton.button == 0) {
                    // Do not push button down event here, because we need mouse motion event first
                    buttons = 0;
                    event2.type = SDL_MOUSEBUTTONUP;
                    event2.button.which = 0;
                    event2.button.button = SDL_BUTTON_LEFT;
                    event2.button.state = SDL_RELEASED;
                    event2.button.x = x;
                    event2.button.y = y;
                    //__android_log_print(ANDROID_LOG_INFO, "GUICHAN","Mouse button %d coords %d %d", buttons, x, y);
                }
                gui_input->pushInput(event2);
            }
#else
            gui_input->pushInput(event);
#endif
    }

    // Now we let the Gui object perform its logic.
    uae_gui->logic();
    // Now we let the Gui object draw itself.
    uae_gui->draw();
    // Finally we update the screen.
    SDL_Flip(gui_screen);
  }  
}


bool SelectFile(const char *title, char *value, const char *filter[])
{
  dialogResult = false;
  dialogFinished = false;
  filefilter = filter;
  
  InitSelectFile(title);
  extractPath(value, workingDir);
  checkfoldername(workingDir);
  checkfilename(value);
  
  SelectFileLoop();
  ExitSelectFile();
  
  if(dialogResult)
    strncpy(value, workingDir, MAX_PATH);
  return dialogResult;
}
