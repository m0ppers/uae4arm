#include "sysconfig.h"
#include "sysdeps.h"
#include "options.h"
#include "memory-uae.h"
#include "newcpu.h"
#include "custom.h"
#include "cpu_prefetch.h"
#include "cputbl.h"
#define CPUFUNC(x) x##_ff
#define SET_CFLG_ALWAYS(x) SET_CFLG(x)
#define SET_NFLG_ALWAYS(x) SET_NFLG(x)
#ifdef NOFLAGS
#include "noflags.h"
#endif

#if !defined(PART_1) && !defined(PART_2) && !defined(PART_3) && !defined(PART_4) && !defined(PART_5) && !defined(PART_6) && !defined(PART_7) && !defined(PART_8)
#define PART_1 1
#define PART_2 1
#define PART_3 1
#define PART_4 1
#define PART_5 1
#define PART_6 1
#define PART_7 1
#define PART_8 1
#endif

#ifdef PART_1
/* OR.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
{	uae_s8 dst = get_byte (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0038_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0039_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_byte (dsta,src);
}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* ORSR.B #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_003c_11)(uae_u32 opcode, struct regstruct &regs)
{
{	MakeSR (regs);
{	uae_s16 src = get_word_prefetch (regs, 4);
	src &= 0xFF;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	regs.sr |= src;
	MakeFromSR (regs);
}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0040_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0050_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0058_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0060_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0068_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0070_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0078_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0079_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_word (dsta,src);
}}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* ORSR.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_007c_11)(uae_u32 opcode, struct regstruct &regs)
{
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{	MakeSR (regs);
{	uae_s16 src = get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	regs.sr |= src;
	MakeFromSR (regs);
}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_00a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 30 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_00a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_long (dsta,src);
}}}}}	m68k_incpc (8);
return 32 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_00b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 8));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_long (dsta,src);
}}}}}	m68k_incpc (8);
return 34 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_00b8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_long (dsta,src);
}}}}}	m68k_incpc (8);
return 32 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_00b9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 12);
	put_long (dsta,src);
}}}}}	m68k_incpc (10);
return 36 * CYCLE_UNIT / 2;
}

/* BTST.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0100_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* MVPMR.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_0108_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr memp = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_u16 val = (get_byte (memp) << 8) + get_byte (memp + 2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0110_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 4);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0118_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	get_word_prefetch (regs, 4);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0120_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	get_word_prefetch (regs, 4);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0128_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0130_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0138_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0139_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_013a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 2;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_getpc (regs) + 2;
	dsta += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_013b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 3;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr tmppc;
	uaecptr dsta;
	tmppc = m68k_getpc (regs) + 2;
	dsta = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,#<data>.B */
unsigned long REGPARAM2 CPUFUNC(op_013c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = (uae_u8)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* BCHG.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0140_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	src &= 31;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* MVPMR.L (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_0148_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr memp = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_u32 val = (get_byte (memp) << 24) + (get_byte (memp + 2) << 16)
              + (get_byte (memp + 4) << 8) + get_byte (memp + 6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0150_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 4);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0158_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	get_word_prefetch (regs, 4);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0160_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	get_word_prefetch (regs, 4);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0168_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0170_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0178_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0179_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_017a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 2;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_getpc (regs) + 2;
	dsta += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_017b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 3;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr tmppc;
	uaecptr dsta;
	tmppc = m68k_getpc (regs) + 2;
	dsta = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* BCLR.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0180_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* MVPRM.W Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0188_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	uaecptr memp = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	put_byte (memp, src >> 8); put_byte (memp + 2, src);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 4);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	get_word_prefetch (regs, 4);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_01a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	get_word_prefetch (regs, 4);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_01a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_01b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_01b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_01b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_01ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 2;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_getpc (regs) + 2;
	dsta += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_01bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 3;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr tmppc;
	uaecptr dsta;
	tmppc = m68k_getpc (regs) + 2;
	dsta = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* BSET.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_01c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* MVPRM.L Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_01c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
	uaecptr memp = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	put_byte (memp, src >> 24); put_byte (memp + 2, src >> 16);
	put_byte (memp + 4, src >> 8); put_byte (memp + 6, src);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_01d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 4);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_01d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	get_word_prefetch (regs, 4);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_01e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	get_word_prefetch (regs, 4);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_01e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_01f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_01f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_01f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_01fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 2;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_getpc (regs) + 2;
	dsta += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_01fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 3;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr tmppc;
	uaecptr dsta;
	tmppc = m68k_getpc (regs) + 2;
	dsta = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0200_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0210_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0218_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0220_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0228_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0230_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
{	uae_s8 dst = get_byte (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0238_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0239_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_byte (dsta,src);
}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* ANDSR.B #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_023c_11)(uae_u32 opcode, struct regstruct &regs)
{
{	MakeSR (regs);
{	uae_s16 src = get_word_prefetch (regs, 4);
	src |= 0xFF00;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	regs.sr &= src;
	MakeFromSR (regs);
}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0240_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0250_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0258_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0260_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0268_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0270_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0278_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0279_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_word (dsta,src);
}}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* ANDSR.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_027c_11)(uae_u32 opcode, struct regstruct &regs)
{
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{	MakeSR (regs);
{	uae_s16 src = get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	regs.sr &= src;
	MakeFromSR (regs);
}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0280_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpc (6);
return 14 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0290_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0298_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_02a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 30 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_02a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_long (dsta,src);
}}}}}	m68k_incpc (8);
return 32 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_02b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 8));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_long (dsta,src);
}}}}}	m68k_incpc (8);
return 34 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_02b8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_long (dsta,src);
}}}}}	m68k_incpc (8);
return 32 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_02b9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 12);
	put_long (dsta,src);
}}}}}	m68k_incpc (10);
return 36 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0400_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0410_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0418_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0420_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0428_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0430_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0438_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0439_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0440_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0450_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0458_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0460_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0468_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0470_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0478_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0479_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0480_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0490_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0498_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_04a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 30 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_04a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (8);
return 32 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_04b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 8));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (8);
return 34 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_04b8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (8);
return 32 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_04b9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 12);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (10);
return 36 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0600_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0610_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0618_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0620_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0628_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0630_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0638_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0639_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0640_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0650_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0658_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0660_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0668_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0670_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0678_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0679_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0680_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0690_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0698_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_06a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 30 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_06a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (8);
return 32 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_06b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 8));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (8);
return 34 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_06b8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (8);
return 32 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_06b9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 12);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (10);
return 36 * CYCLE_UNIT / 2;
}

/* BTST.L #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0800_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}	m68k_incpc (4);
return 10 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0810_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0818_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0820_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0828_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0830_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (6);
return 18 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0838_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0839_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 10);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (8);
return 20 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_083a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = 2;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_getpc (regs) + 4;
	dsta += (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_083b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = 3;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr tmppc;
	uaecptr dsta;
	tmppc = m68k_getpc (regs) + 4;
	dsta = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 6));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpc (6);
return 18 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,#<data>.B */
unsigned long REGPARAM2 CPUFUNC(op_083c_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s8 dst = (uae_u8)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}	m68k_incpc (6);
return 12 * CYCLE_UNIT / 2;
}

/* BCHG.L #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0840_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	src &= 31;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0850_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0858_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	get_word_prefetch (regs, 6);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0860_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	get_word_prefetch (regs, 6);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0868_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0870_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0878_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0879_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 10);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_087a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = 2;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_getpc (regs) + 4;
	dsta += (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_087b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = 3;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr tmppc;
	uaecptr dsta;
	tmppc = m68k_getpc (regs) + 4;
	dsta = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 6));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* BCLR.L #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0880_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0890_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0898_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_08a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_08a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_08b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_08b8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_08b9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 10);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_08ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = 2;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_getpc (regs) + 4;
	dsta += (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_08bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = 3;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr tmppc;
	uaecptr dsta;
	tmppc = m68k_getpc (regs) + 4;
	dsta = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 6));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* BSET.L #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_08c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_08d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_08d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_08e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	get_word_prefetch (regs, 6);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_08e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_08f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_08f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_08f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 10);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_08fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = 2;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_getpc (regs) + 4;
	dsta += (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_08fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = 3;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr tmppc;
	uaecptr dsta;
	tmppc = m68k_getpc (regs) + 4;
	dsta = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 6));
	regs.ir = regs.irc;
	regs.irc = 0;
{	uae_s8 dst = get_byte (dsta);
	get_word_prefetch (regs, 8);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_byte (dsta,dst);
}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0a00_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0a10_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0a18_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0a20_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0a28_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0a30_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
{	uae_s8 dst = get_byte (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0a38_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0a39_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_byte (dsta,src);
}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* EORSR.B #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_0a3c_11)(uae_u32 opcode, struct regstruct &regs)
{
{	MakeSR (regs);
{	uae_s16 src = get_word_prefetch (regs, 4);
	src &= 0xFF;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	regs.sr ^= src;
	MakeFromSR (regs);
}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0a40_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0a50_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0a58_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0a60_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0a68_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0a70_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0a78_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0a79_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_word (dsta,src);
}}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* EORSR.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_0a7c_11)(uae_u32 opcode, struct regstruct &regs)
{
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{	MakeSR (regs);
{	uae_s16 src = get_word_prefetch (regs, 4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	regs.sr ^= src;
	MakeFromSR (regs);
}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_2
/* EOR.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0a80_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0a90_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0a98_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0aa0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 30 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0aa8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_long (dsta,src);
}}}}}	m68k_incpc (8);
return 32 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0ab0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 8));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_long (dsta,src);
}}}}}	m68k_incpc (8);
return 34 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0ab8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
	put_long (dsta,src);
}}}}}	m68k_incpc (8);
return 32 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0ab9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 12);
	put_long (dsta,src);
}}}}}	m68k_incpc (10);
return 36 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0c00_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0c10_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0c18_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0c20_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0c28_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0c30_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (6);
return 18 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0c38_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0c39_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (8);
return 20 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0c40_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0c50_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0c58_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0c60_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0c68_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0c70_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (6);
return 18 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0c78_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0c79_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (8);
return 20 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_0c80_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (6);
return 14 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(An) */
unsigned long REGPARAM2 CPUFUNC(op_0c90_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_0c98_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_0ca0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_0ca8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_0cb0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 8));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (8);
return 26 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_0cb8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (8);
return 24 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_0cb9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 12);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (10);
return 28 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_1000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_1010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_1018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_1020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 10 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_1028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_1030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_1038_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_1039_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_103a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_103b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_103c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_1080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(An) */
unsigned long REGPARAM2 CPUFUNC(op_1090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(An) */
unsigned long REGPARAM2 CPUFUNC(op_1098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(An) */
unsigned long REGPARAM2 CPUFUNC(op_10a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(An) */
unsigned long REGPARAM2 CPUFUNC(op_10a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(An) */
unsigned long REGPARAM2 CPUFUNC(op_10b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_10b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(An) */
unsigned long REGPARAM2 CPUFUNC(op_10b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(An) */
unsigned long REGPARAM2 CPUFUNC(op_10ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(An) */
unsigned long REGPARAM2 CPUFUNC(op_10bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(An) */
unsigned long REGPARAM2 CPUFUNC(op_10bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_10c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_10d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_10d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_10e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_10e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_10f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_10f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_10f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_10fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_10fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_10fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_1100_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_1110_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_1118_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_1120_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (2);
}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_1128_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_1130_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_1138_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_1139_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_113a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_113b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_113c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_1140_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_1150_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_1158_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_1160_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_1168_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_1170_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_1178_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_1179_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_117a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_117b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_117c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_1180_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_1190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_1198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_11a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_11a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_11b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_11b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_11b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 8));
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_11ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_11bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_11bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_11c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_11d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_11d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_11e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_11e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_11f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_11f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_11f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_11fa_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_11fb_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_11fc_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_13c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_13d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 4) << 16;
	dsta |= regs.irc;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_13d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 4) << 16;
	dsta |= regs.irc;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_13e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 4) << 16;
	dsta |= regs.irc;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (6);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_13e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_13f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_13f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_13f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 8) << 16;
	dsta |= regs.irc;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (10);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_13fa_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_13fb_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_13fc_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	put_byte (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_2000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVE.L An,Dn */
unsigned long REGPARAM2 CPUFUNC(op_2008_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_2010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_2018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_2020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_2028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_2030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_2038_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_2039_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_203a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_203b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_203c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.L Dn,An */
unsigned long REGPARAM2 CPUFUNC(op_2040_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVEA.L An,An */
unsigned long REGPARAM2 CPUFUNC(op_2048_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVEA.L (An),An */
unsigned long REGPARAM2 CPUFUNC(op_2050_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.L (An)+,An */
unsigned long REGPARAM2 CPUFUNC(op_2058_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.L -(An),An */
unsigned long REGPARAM2 CPUFUNC(op_2060_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVEA.L (d16,An),An */
unsigned long REGPARAM2 CPUFUNC(op_2068_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVEA.L (d8,An,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_2070_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVEA.L (xxx).W,An */
unsigned long REGPARAM2 CPUFUNC(op_2078_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVEA.L (xxx).L,An */
unsigned long REGPARAM2 CPUFUNC(op_2079_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVEA.L (d16,PC),An */
unsigned long REGPARAM2 CPUFUNC(op_207a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVEA.L (d8,PC,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_207b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVEA.L #<data>.L,An */
unsigned long REGPARAM2 CPUFUNC(op_207c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_2080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(An) */
unsigned long REGPARAM2 CPUFUNC(op_2088_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(An) */
unsigned long REGPARAM2 CPUFUNC(op_2090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,(An) */
unsigned long REGPARAM2 CPUFUNC(op_2098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(An) */
unsigned long REGPARAM2 CPUFUNC(op_20a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),(An) */
unsigned long REGPARAM2 CPUFUNC(op_20a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(An) */
unsigned long REGPARAM2 CPUFUNC(op_20b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_20b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(An) */
unsigned long REGPARAM2 CPUFUNC(op_20b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(An) */
unsigned long REGPARAM2 CPUFUNC(op_20ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(An) */
unsigned long REGPARAM2 CPUFUNC(op_20bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(An) */
unsigned long REGPARAM2 CPUFUNC(op_20bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_20fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_2100_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L An,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_2108_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_2110_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_2118_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_2120_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (2);
}}}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_2128_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_2130_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_2138_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_2139_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_213a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_213b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_213c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_2140_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_2148_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_2150_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_2158_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_2160_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_3
/* MOVE.L (d16,An),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_2168_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_2170_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 30 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_2178_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_2179_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_217a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_217b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 30 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_217c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_2180_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_2188_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_2190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_2198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_21a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_21a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 30 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_21b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_21b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 30 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_21b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 8));
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 34 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_21ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 30 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_21bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_21bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 8));
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 30 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21fa_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21fb_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 30 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_21fc_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 4) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 4) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 4) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (6);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 30 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 34 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 8) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (10);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (10);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 36 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23fa_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23fb_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 34 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_23fc_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (10);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	put_long (dsta,src);
	m68k_incpc (10);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_3000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVE.W An,Dn */
unsigned long REGPARAM2 CPUFUNC(op_3008_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_3010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_3018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_3020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 10 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_3028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_3030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_3038_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_3039_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_303a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_303b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_303c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVEA.W Dn,An */
unsigned long REGPARAM2 CPUFUNC(op_3040_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVEA.W An,An */
unsigned long REGPARAM2 CPUFUNC(op_3048_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVEA.W (An),An */
unsigned long REGPARAM2 CPUFUNC(op_3050_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVEA.W (An)+,An */
unsigned long REGPARAM2 CPUFUNC(op_3058_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVEA.W -(An),An */
unsigned long REGPARAM2 CPUFUNC(op_3060_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 10 * CYCLE_UNIT / 2;
}

/* MOVEA.W (d16,An),An */
unsigned long REGPARAM2 CPUFUNC(op_3068_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.W (d8,An,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_3070_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVEA.W (xxx).W,An */
unsigned long REGPARAM2 CPUFUNC(op_3078_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.W (xxx).L,An */
unsigned long REGPARAM2 CPUFUNC(op_3079_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVEA.W (d16,PC),An */
unsigned long REGPARAM2 CPUFUNC(op_307a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.W (d8,PC,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_307b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVEA.W #<data>.W,An */
unsigned long REGPARAM2 CPUFUNC(op_307c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_3080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(An) */
unsigned long REGPARAM2 CPUFUNC(op_3088_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(An) */
unsigned long REGPARAM2 CPUFUNC(op_3090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(An) */
unsigned long REGPARAM2 CPUFUNC(op_3098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(An) */
unsigned long REGPARAM2 CPUFUNC(op_30a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(An) */
unsigned long REGPARAM2 CPUFUNC(op_30a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(An) */
unsigned long REGPARAM2 CPUFUNC(op_30b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_30b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(An) */
unsigned long REGPARAM2 CPUFUNC(op_30b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(An) */
unsigned long REGPARAM2 CPUFUNC(op_30ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(An) */
unsigned long REGPARAM2 CPUFUNC(op_30bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_30bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_30fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_3100_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W An,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_3108_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_3110_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_3118_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_3120_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (2);
}}}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_3128_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_3130_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
}}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_3138_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_3139_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_313a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_313b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
}}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_313c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_3140_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_3148_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_3150_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_3158_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_3160_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_3168_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_3170_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_3178_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_3179_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_317a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_317b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_317c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_3180_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_3188_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 14 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_3190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_3198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_31a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_31a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_31b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_31b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_31b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 8));
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_31ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_31bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_31bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (4);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 8);
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31fa_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31fb_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_31fc_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 4) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 4) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 4) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (6);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (6);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 22 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (4);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 8) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (10);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (10);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33fa_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33fb_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uaecptr dsta;
	dsta = get_word_prefetch (regs, 6) << 16;
	dsta |= regs.irc;
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (8);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}return 26 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_33fc_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uaecptr dsta = get_long_prefetch (regs, 6);
	if (dsta & 1) {
	m68k_incpc (8);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	put_word (dsta,src);
	m68k_incpc (8);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* NEGX.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_4000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((newv) & 0xff);
}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* NEGX.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_4010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEGX.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEGX.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* NEGX.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEGX.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* NEGX.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4038_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEGX.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4039_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* NEGX.W Dn */
unsigned long REGPARAM2 CPUFUNC(op_4040_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((newv) & 0xffff);
}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* NEGX.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_4050_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_word (srca,newv);
}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEGX.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4058_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_word (srca,newv);
}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEGX.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4060_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_word (srca,newv);
}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* NEGX.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4068_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_word (srca,newv);
}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEGX.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4070_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_word (srca,newv);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* NEGX.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4078_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_word (srca,newv);
}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEGX.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4079_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_word (srca,newv);
}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* NEGX.L Dn */
unsigned long REGPARAM2 CPUFUNC(op_4080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, srcreg) = (newv);
}}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* NEGX.L (An) */
unsigned long REGPARAM2 CPUFUNC(op_4090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_long (srca,newv);
}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* NEGX.L (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_long (srca,newv);
}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* NEGX.L -(An) */
unsigned long REGPARAM2 CPUFUNC(op_40a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_long (srca,newv);
}}}}}}	m68k_incpc (2);
return 22 * CYCLE_UNIT / 2;
}

/* NEGX.L (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_40a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_long (srca,newv);
}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* NEGX.L (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_40b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_long (srca,newv);
}}}}}}	m68k_incpc (4);
return 26 * CYCLE_UNIT / 2;
}

/* NEGX.L (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_40b8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_long (srca,newv);
}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* NEGX.L (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_40b9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_long (srca,newv);
}}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* MVSR2.W Dn */
unsigned long REGPARAM2 CPUFUNC(op_40c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	MakeSR (regs);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((regs.sr) & 0xffff);
}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* MVSR2.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_40d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	MakeSR (regs);
	put_word (srca,regs.sr);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* MVSR2.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_40d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	MakeSR (regs);
	put_word (srca,regs.sr);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* MVSR2.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_40e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	MakeSR (regs);
	put_word (srca,regs.sr);
}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* MVSR2.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_40e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	MakeSR (regs);
	put_word (srca,regs.sr);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* MVSR2.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_40f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	MakeSR (regs);
	put_word (srca,regs.sr);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* MVSR2.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_40f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	MakeSR (regs);
	put_word (srca,regs.sr);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* MVSR2.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_40f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	MakeSR (regs);
	put_word (srca,regs.sr);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* CHK.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_4180_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpc (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6, regs);
		return 40 * CYCLE_UNIT / 2;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6, regs);
		return 40 * CYCLE_UNIT / 2;
	}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 10 * CYCLE_UNIT / 2;
}

/* CHK.W (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_4190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpc (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6, regs);
		return 44 * CYCLE_UNIT / 2;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6, regs);
		return 44 * CYCLE_UNIT / 2;
	}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}
return 14 * CYCLE_UNIT / 2;
}

/* CHK.W (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_4198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpc (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6, regs);
		return 44 * CYCLE_UNIT / 2;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6, regs);
		return 44 * CYCLE_UNIT / 2;
	}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}
return 14 * CYCLE_UNIT / 2;
}

/* CHK.W -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_41a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpc (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6, regs);
		return 46 * CYCLE_UNIT / 2;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6, regs);
		return 46 * CYCLE_UNIT / 2;
	}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}
return 16 * CYCLE_UNIT / 2;
}

/* CHK.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_41a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpc (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6, regs);
		return 48 * CYCLE_UNIT / 2;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6, regs);
		return 48 * CYCLE_UNIT / 2;
	}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}
return 18 * CYCLE_UNIT / 2;
}

/* CHK.W (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_41b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpc (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6, regs);
		return 50 * CYCLE_UNIT / 2;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6, regs);
		return 50 * CYCLE_UNIT / 2;
	}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}
return 20 * CYCLE_UNIT / 2;
}

/* CHK.W (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_41b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpc (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6, regs);
		return 48 * CYCLE_UNIT / 2;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6, regs);
		return 48 * CYCLE_UNIT / 2;
	}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}
return 18 * CYCLE_UNIT / 2;
}

/* CHK.W (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_41b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpc (6);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6, regs);
		return 52 * CYCLE_UNIT / 2;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6, regs);
		return 52 * CYCLE_UNIT / 2;
	}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}
return 22 * CYCLE_UNIT / 2;
}

/* CHK.W (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_41ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpc (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6, regs);
		return 48 * CYCLE_UNIT / 2;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6, regs);
		return 48 * CYCLE_UNIT / 2;
	}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}
return 18 * CYCLE_UNIT / 2;
}

/* CHK.W (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_41bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpc (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6, regs);
		return 50 * CYCLE_UNIT / 2;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6, regs);
		return 50 * CYCLE_UNIT / 2;
	}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}
return 20 * CYCLE_UNIT / 2;
}

/* CHK.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_41bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpc (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6, regs);
		return 44 * CYCLE_UNIT / 2;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6, regs);
		return 44 * CYCLE_UNIT / 2;
	}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* LEA.L (An),An */
unsigned long REGPARAM2 CPUFUNC(op_41d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* LEA.L (d16,An),An */
unsigned long REGPARAM2 CPUFUNC(op_41e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* LEA.L (d8,An,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_41f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* LEA.L (xxx).W,An */
unsigned long REGPARAM2 CPUFUNC(op_41f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* LEA.L (xxx).L,An */
unsigned long REGPARAM2 CPUFUNC(op_41f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpc (6);
return 12 * CYCLE_UNIT / 2;
}

/* LEA.L (d16,PC),An */
unsigned long REGPARAM2 CPUFUNC(op_41fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* LEA.L (d8,PC,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_41fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* CLR.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_4200_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(0)) == 0);
	SET_NFLG   (((uae_s8)(0)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((0) & 0xff);
}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* CLR.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_4210_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(0)) == 0);
	SET_NFLG   (((uae_s8)(0)) < 0);
	put_byte (srca,0);
}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* CLR.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4218_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(0)) == 0);
	SET_NFLG   (((uae_s8)(0)) < 0);
	put_byte (srca,0);
}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* CLR.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4220_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(0)) == 0);
	SET_NFLG   (((uae_s8)(0)) < 0);
	put_byte (srca,0);
}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* CLR.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4228_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(0)) == 0);
	SET_NFLG   (((uae_s8)(0)) < 0);
	put_byte (srca,0);
}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* CLR.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4230_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(0)) == 0);
	SET_NFLG   (((uae_s8)(0)) < 0);
	put_byte (srca,0);
}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* CLR.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4238_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(0)) == 0);
	SET_NFLG   (((uae_s8)(0)) < 0);
	put_byte (srca,0);
}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* CLR.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4239_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(0)) == 0);
	SET_NFLG   (((uae_s8)(0)) < 0);
	put_byte (srca,0);
}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* CLR.W Dn */
unsigned long REGPARAM2 CPUFUNC(op_4240_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(0)) == 0);
	SET_NFLG   (((uae_s16)(0)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((0) & 0xffff);
}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* CLR.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_4250_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(0)) == 0);
	SET_NFLG   (((uae_s16)(0)) < 0);
	put_word (srca,0);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* CLR.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4258_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(0)) == 0);
	SET_NFLG   (((uae_s16)(0)) < 0);
	put_word (srca,0);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* CLR.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4260_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(0)) == 0);
	SET_NFLG   (((uae_s16)(0)) < 0);
	put_word (srca,0);
}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* CLR.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4268_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(0)) == 0);
	SET_NFLG   (((uae_s16)(0)) < 0);
	put_word (srca,0);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* CLR.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4270_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(0)) == 0);
	SET_NFLG   (((uae_s16)(0)) < 0);
	put_word (srca,0);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* CLR.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4278_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(0)) == 0);
	SET_NFLG   (((uae_s16)(0)) < 0);
	put_word (srca,0);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* CLR.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4279_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(0)) == 0);
	SET_NFLG   (((uae_s16)(0)) < 0);
	put_word (srca,0);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* CLR.L Dn */
unsigned long REGPARAM2 CPUFUNC(op_4280_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(0)) == 0);
	SET_NFLG   (((uae_s32)(0)) < 0);
	m68k_dreg (regs, srcreg) = (0);
}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* CLR.L (An) */
unsigned long REGPARAM2 CPUFUNC(op_4290_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(0)) == 0);
	SET_NFLG   (((uae_s32)(0)) < 0);
	put_long (srca,0);
}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* CLR.L (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4298_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(0)) == 0);
	SET_NFLG   (((uae_s32)(0)) < 0);
	put_long (srca,0);
}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* CLR.L -(An) */
unsigned long REGPARAM2 CPUFUNC(op_42a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(0)) == 0);
	SET_NFLG   (((uae_s32)(0)) < 0);
	put_long (srca,0);
}}}}	m68k_incpc (2);
return 22 * CYCLE_UNIT / 2;
}

/* CLR.L (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_42a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(0)) == 0);
	SET_NFLG   (((uae_s32)(0)) < 0);
	put_long (srca,0);
}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* CLR.L (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_42b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(0)) == 0);
	SET_NFLG   (((uae_s32)(0)) < 0);
	put_long (srca,0);
}}}}	m68k_incpc (4);
return 26 * CYCLE_UNIT / 2;
}

/* CLR.L (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_42b8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(0)) == 0);
	SET_NFLG   (((uae_s32)(0)) < 0);
	put_long (srca,0);
}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_4
/* CLR.L (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_42b9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(0)) == 0);
	SET_NFLG   (((uae_s32)(0)) < 0);
	put_long (srca,0);
}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* NEG.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_4400_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((dst) & 0xff);
}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* NEG.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_4410_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (srca,dst);
}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEG.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4418_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (srca,dst);
}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEG.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4420_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (srca,dst);
}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* NEG.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4428_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (srca,dst);
}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEG.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4430_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (srca,dst);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* NEG.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4438_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (srca,dst);
}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEG.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4439_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (srca,dst);
}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* NEG.W Dn */
unsigned long REGPARAM2 CPUFUNC(op_4440_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((dst) & 0xffff);
}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* NEG.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_4450_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (srca,dst);
}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEG.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4458_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (srca,dst);
}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEG.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4460_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (srca,dst);
}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* NEG.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4468_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (srca,dst);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEG.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4470_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (srca,dst);
}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* NEG.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4478_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (srca,dst);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEG.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4479_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (srca,dst);
}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* NEG.L Dn */
unsigned long REGPARAM2 CPUFUNC(op_4480_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, srcreg) = (dst);
}}}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* NEG.L (An) */
unsigned long REGPARAM2 CPUFUNC(op_4490_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (srca,dst);
}}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* NEG.L (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4498_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (srca,dst);
}}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* NEG.L -(An) */
unsigned long REGPARAM2 CPUFUNC(op_44a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (srca,dst);
}}}}}}}	m68k_incpc (2);
return 22 * CYCLE_UNIT / 2;
}

/* NEG.L (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_44a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (srca,dst);
}}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* NEG.L (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_44b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (srca,dst);
}}}}}}}	m68k_incpc (4);
return 26 * CYCLE_UNIT / 2;
}

/* NEG.L (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_44b8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (srca,dst);
}}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* NEG.L (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_44b9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (srca,dst);
}}}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* MV2SR.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_44c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	MakeSR (regs);
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_44d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	MakeSR (regs);
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* MV2SR.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_44d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
	MakeSR (regs);
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* MV2SR.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_44e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
	MakeSR (regs);
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
}}}}	m68k_incpc (2);
return 18 * CYCLE_UNIT / 2;
}

/* MV2SR.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_44e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	MakeSR (regs);
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* MV2SR.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_44f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	MakeSR (regs);
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return 22 * CYCLE_UNIT / 2;
}

/* MV2SR.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_44f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	MakeSR (regs);
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* MV2SR.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_44f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	MakeSR (regs);
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return 24 * CYCLE_UNIT / 2;
}

/* MV2SR.B (d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_44fa_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	MakeSR (regs);
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* MV2SR.B (d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_44fb_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	MakeSR (regs);
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return 22 * CYCLE_UNIT / 2;
}

/* MV2SR.B #<data>.B */
unsigned long REGPARAM2 CPUFUNC(op_44fc_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = get_word_prefetch (regs, 4);
	MakeSR (regs);
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NOT.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_4600_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(dst)) == 0);
	SET_NFLG   (((uae_s8)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((dst) & 0xff);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* NOT.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_4610_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(dst)) == 0);
	SET_NFLG   (((uae_s8)(dst)) < 0);
	put_byte (srca,dst);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NOT.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4618_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(dst)) == 0);
	SET_NFLG   (((uae_s8)(dst)) < 0);
	put_byte (srca,dst);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NOT.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4620_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(dst)) == 0);
	SET_NFLG   (((uae_s8)(dst)) < 0);
	put_byte (srca,dst);
}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* NOT.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4628_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(dst)) == 0);
	SET_NFLG   (((uae_s8)(dst)) < 0);
	put_byte (srca,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NOT.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4630_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(dst)) == 0);
	SET_NFLG   (((uae_s8)(dst)) < 0);
	put_byte (srca,dst);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* NOT.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4638_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(dst)) == 0);
	SET_NFLG   (((uae_s8)(dst)) < 0);
	put_byte (srca,dst);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NOT.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4639_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(dst)) == 0);
	SET_NFLG   (((uae_s8)(dst)) < 0);
	put_byte (srca,dst);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* NOT.W Dn */
unsigned long REGPARAM2 CPUFUNC(op_4640_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(dst)) == 0);
	SET_NFLG   (((uae_s16)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((dst) & 0xffff);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* NOT.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_4650_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(dst)) == 0);
	SET_NFLG   (((uae_s16)(dst)) < 0);
	put_word (srca,dst);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NOT.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4658_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(dst)) == 0);
	SET_NFLG   (((uae_s16)(dst)) < 0);
	put_word (srca,dst);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NOT.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4660_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(dst)) == 0);
	SET_NFLG   (((uae_s16)(dst)) < 0);
	put_word (srca,dst);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* NOT.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4668_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(dst)) == 0);
	SET_NFLG   (((uae_s16)(dst)) < 0);
	put_word (srca,dst);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NOT.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4670_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(dst)) == 0);
	SET_NFLG   (((uae_s16)(dst)) < 0);
	put_word (srca,dst);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* NOT.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4678_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(dst)) == 0);
	SET_NFLG   (((uae_s16)(dst)) < 0);
	put_word (srca,dst);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NOT.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4679_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(dst)) == 0);
	SET_NFLG   (((uae_s16)(dst)) < 0);
	put_word (srca,dst);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* NOT.L Dn */
unsigned long REGPARAM2 CPUFUNC(op_4680_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(dst)) == 0);
	SET_NFLG   (((uae_s32)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (dst);
}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* NOT.L (An) */
unsigned long REGPARAM2 CPUFUNC(op_4690_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(dst)) == 0);
	SET_NFLG   (((uae_s32)(dst)) < 0);
	put_long (srca,dst);
}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* NOT.L (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4698_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(dst)) == 0);
	SET_NFLG   (((uae_s32)(dst)) < 0);
	put_long (srca,dst);
}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* NOT.L -(An) */
unsigned long REGPARAM2 CPUFUNC(op_46a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(dst)) == 0);
	SET_NFLG   (((uae_s32)(dst)) < 0);
	put_long (srca,dst);
}}}}}	m68k_incpc (2);
return 22 * CYCLE_UNIT / 2;
}

/* NOT.L (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_46a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(dst)) == 0);
	SET_NFLG   (((uae_s32)(dst)) < 0);
	put_long (srca,dst);
}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* NOT.L (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_46b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(dst)) == 0);
	SET_NFLG   (((uae_s32)(dst)) < 0);
	put_long (srca,dst);
}}}}}	m68k_incpc (4);
return 26 * CYCLE_UNIT / 2;
}

/* NOT.L (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_46b8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(dst)) == 0);
	SET_NFLG   (((uae_s32)(dst)) < 0);
	put_long (srca,dst);
}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* NOT.L (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_46b9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(dst)) == 0);
	SET_NFLG   (((uae_s32)(dst)) < 0);
	put_long (srca,dst);
}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* MV2SR.W Dn */
unsigned long REGPARAM2 CPUFUNC(op_46c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	regs.sr = src;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_46d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.sr = src;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
}}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* MV2SR.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_46d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
	regs.sr = src;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
}}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* MV2SR.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_46e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.sr = src;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
}}}}}	m68k_incpc (2);
return 18 * CYCLE_UNIT / 2;
}

/* MV2SR.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_46e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.sr = src;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* MV2SR.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_46f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.sr = src;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}}	m68k_incpc (4);
return 22 * CYCLE_UNIT / 2;
}

/* MV2SR.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_46f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.sr = src;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* MV2SR.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_46f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.sr = src;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}}	m68k_incpc (6);
return 24 * CYCLE_UNIT / 2;
}

/* MV2SR.W (d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_46fa_11)(uae_u32 opcode, struct regstruct &regs)
{
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.sr = src;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* MV2SR.W (d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_46fb_11)(uae_u32 opcode, struct regstruct &regs)
{
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.sr = src;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}}	m68k_incpc (4);
return 22 * CYCLE_UNIT / 2;
}

/* MV2SR.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_46fc_11)(uae_u32 opcode, struct regstruct &regs)
{
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uae_s16 src = get_word_prefetch (regs, 4);
	regs.sr = src;
	MakeFromSR (regs);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NBCD.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_4800_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((newv) & 0xff);
}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* NBCD.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_4810_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NBCD.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4818_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* NBCD.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4820_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* NBCD.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4828_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NBCD.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4830_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* NBCD.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4838_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* NBCD.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4839_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (srca,newv);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* SWAP.W Dn */
unsigned long REGPARAM2 CPUFUNC(op_4840_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = ((src >> 16)&0xFFFF) | ((src&0xFFFF)<<16);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(dst)) == 0);
	SET_NFLG   (((uae_s32)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (dst);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* PEA.L (An) */
unsigned long REGPARAM2 CPUFUNC(op_4850_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, 7) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_long (dsta,srca);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* PEA.L (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4868_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, 7) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,srca);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* PEA.L (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4870_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, 7) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,srca);
}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* PEA.L (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4878_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, 7) = dsta;
	put_long (dsta,srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* PEA.L (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4879_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	if (dsta & 1) {
	m68k_incpc (4);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, 7) = dsta;
	put_long (dsta,srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* PEA.L (d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_487a_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, 7) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,srca);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* PEA.L (d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_487b_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	if (dsta & 1) {
	m68k_incpc (2);
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, 7) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,srca);
}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* EXT.W Dn */
unsigned long REGPARAM2 CPUFUNC(op_4880_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 dst = (uae_s16)(uae_s8)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(dst)) == 0);
	SET_NFLG   (((uae_s16)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((dst) & 0xffff);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_4890_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca = m68k_areg (regs, dstreg);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_word (srca, m68k_dreg (regs, movem_index1[dmask])); srca += 2; dmask = movem_next[dmask]; writecycles += 4; }
	while (amask) { put_word (srca, m68k_areg (regs, movem_index1[amask])); srca += 2; amask = movem_next[amask]; writecycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return (writecycles + 8) * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_48a0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) - 0;
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 amask = mask & 0xff, dmask = (mask >> 8) & 0xff;
	int type = get_cpu_model () >= 68020;
	while (amask) {
		srca -= 2;
		if (type) m68k_areg (regs, dstreg) = srca;
		put_word (srca, m68k_areg (regs, movem_index2[amask]));
		amask = movem_next[amask];
		writecycles += 4;
	}
	while (dmask) { srca -= 2; put_word (srca, m68k_dreg (regs, movem_index2[dmask])); dmask = movem_next[dmask]; writecycles += 4; }
	m68k_areg (regs, dstreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return (writecycles + 8) * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_48a8_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_word (srca, m68k_dreg (regs, movem_index1[dmask])); srca += 2; dmask = movem_next[dmask]; writecycles += 4; }
	while (amask) { put_word (srca, m68k_areg (regs, movem_index1[amask])); srca += 2; amask = movem_next[amask]; writecycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (writecycles + 12) * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_48b0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_word (srca, m68k_dreg (regs, movem_index1[dmask])); srca += 2; dmask = movem_next[dmask]; writecycles += 4; }
	while (amask) { put_word (srca, m68k_areg (regs, movem_index1[amask])); srca += 2; amask = movem_next[amask]; writecycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (writecycles + 14) * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_48b8_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_word (srca, m68k_dreg (regs, movem_index1[dmask])); srca += 2; dmask = movem_next[dmask]; writecycles += 4; }
	while (amask) { put_word (srca, m68k_areg (regs, movem_index1[amask])); srca += 2; amask = movem_next[amask]; writecycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (writecycles + 12) * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_48b9_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca = get_long_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_word (srca, m68k_dreg (regs, movem_index1[dmask])); srca += 2; dmask = movem_next[dmask]; writecycles += 4; }
	while (amask) { put_word (srca, m68k_areg (regs, movem_index1[amask])); srca += 2; amask = movem_next[amask]; writecycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
}}}}	m68k_incpc (8);
return (writecycles + 16) * CYCLE_UNIT / 2;
}

/* EXT.L Dn */
unsigned long REGPARAM2 CPUFUNC(op_48c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 dst = (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(dst)) == 0);
	SET_NFLG   (((uae_s32)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (dst);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_48d0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca = m68k_areg (regs, dstreg);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_long (srca, m68k_dreg (regs, movem_index1[dmask])); srca += 4; dmask = movem_next[dmask]; writecycles += 8; }
	while (amask) { put_long (srca, m68k_areg (regs, movem_index1[amask])); srca += 4; amask = movem_next[amask]; writecycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return (writecycles + 8) * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_48e0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) - 0;
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 amask = mask & 0xff, dmask = (mask >> 8) & 0xff;
	int type = get_cpu_model () >= 68020;
	while (amask) {
		srca -= 4;
		if (type) m68k_areg (regs, dstreg) = srca;
		put_long (srca, m68k_areg (regs, movem_index2[amask]));
		amask = movem_next[amask];
		writecycles += 8;
	}
	while (dmask) { srca -= 4; put_long (srca, m68k_dreg (regs, movem_index2[dmask])); dmask = movem_next[dmask]; writecycles += 8; }
	m68k_areg (regs, dstreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return (writecycles + 10) * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_48e8_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_long (srca, m68k_dreg (regs, movem_index1[dmask])); srca += 4; dmask = movem_next[dmask]; writecycles += 8; }
	while (amask) { put_long (srca, m68k_areg (regs, movem_index1[amask])); srca += 4; amask = movem_next[amask]; writecycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (writecycles + 12) * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_48f0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_long (srca, m68k_dreg (regs, movem_index1[dmask])); srca += 4; dmask = movem_next[dmask]; writecycles += 8; }
	while (amask) { put_long (srca, m68k_areg (regs, movem_index1[amask])); srca += 4; amask = movem_next[amask]; writecycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (writecycles + 14) * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_48f8_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_long (srca, m68k_dreg (regs, movem_index1[dmask])); srca += 4; dmask = movem_next[dmask]; writecycles += 8; }
	while (amask) { put_long (srca, m68k_areg (regs, movem_index1[amask])); srca += 4; amask = movem_next[amask]; writecycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (writecycles + 12) * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_48f9_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 writecycles = 0;
{	uae_u16 mask = get_word_prefetch (regs, 4);
{	uaecptr srca = get_long_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_long (srca, m68k_dreg (regs, movem_index1[dmask])); srca += 4; dmask = movem_next[dmask]; writecycles += 8; }
	while (amask) { put_long (srca, m68k_areg (regs, movem_index1[amask])); srca += 4; amask = movem_next[amask]; writecycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
}}}}	m68k_incpc (8);
return (writecycles + 16) * CYCLE_UNIT / 2;
}

/* TST.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_4a00_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* TST.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_4a10_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* TST.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4a18_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* TST.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4a20_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* TST.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4a28_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* TST.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4a30_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* TST.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4a38_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* TST.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4a39_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* TST.W Dn */
unsigned long REGPARAM2 CPUFUNC(op_4a40_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* TST.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_4a50_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* TST.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4a58_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* TST.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4a60_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* TST.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4a68_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* TST.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4a70_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* TST.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4a78_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* TST.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4a79_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* TST.L Dn */
unsigned long REGPARAM2 CPUFUNC(op_4a80_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* TST.L (An) */
unsigned long REGPARAM2 CPUFUNC(op_4a90_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* TST.L (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4a98_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* TST.L -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4aa0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* TST.L (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4aa8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* TST.L (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4ab0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* TST.L (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4ab8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* TST.L (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4ab9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* TAS.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_4ac0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	src |= 0x80;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((src) & 0xff);
}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* TAS.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_4ad0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	src |= 0x80;
	put_byte (srca,src);
}}}	m68k_incpc (2);
return 18 * CYCLE_UNIT / 2;
}

/* TAS.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4ad8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	src |= 0x80;
	put_byte (srca,src);
}}}	m68k_incpc (2);
return 18 * CYCLE_UNIT / 2;
}

/* TAS.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_4ae0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	src |= 0x80;
	put_byte (srca,src);
}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* TAS.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4ae8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	src |= 0x80;
	put_byte (srca,src);
}}}	m68k_incpc (4);
return 22 * CYCLE_UNIT / 2;
}

/* TAS.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4af0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	src |= 0x80;
	put_byte (srca,src);
}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* TAS.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4af8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	src |= 0x80;
	put_byte (srca,src);
}}}	m68k_incpc (4);
return 22 * CYCLE_UNIT / 2;
}

/* TAS.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4af9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	src |= 0x80;
	put_byte (srca,src);
}}}	m68k_incpc (6);
return 26 * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_4c90_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg (regs, dstreg);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; dmask = movem_next[dmask]; readcycles += 4; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; amask = movem_next[amask]; readcycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return (readcycles + 12) * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4c98_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg (regs, dstreg);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; dmask = movem_next[dmask]; readcycles += 4; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; amask = movem_next[amask]; readcycles += 4; }
	m68k_areg (regs, dstreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return (readcycles + 12) * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4ca8_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; dmask = movem_next[dmask]; readcycles += 4; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; amask = movem_next[amask]; readcycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (readcycles + 16) * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4cb0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; dmask = movem_next[dmask]; readcycles += 4; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; amask = movem_next[amask]; readcycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (readcycles + 18) * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4cb8_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; dmask = movem_next[dmask]; readcycles += 4; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; amask = movem_next[amask]; readcycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (readcycles + 16) * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4cb9_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = get_long_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; dmask = movem_next[dmask]; readcycles += 4; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; amask = movem_next[amask]; readcycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
}}}}	m68k_incpc (8);
return (readcycles + 20) * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_4cba_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = 2;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_getpc (regs) + 4;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; dmask = movem_next[dmask]; readcycles += 4; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; amask = movem_next[amask]; readcycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (readcycles + 16) * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4cbb_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = 3;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 4;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 6));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; dmask = movem_next[dmask]; readcycles += 4; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word (srca); srca += 2; amask = movem_next[amask]; readcycles += 4; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (readcycles + 18) * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(An) */
unsigned long REGPARAM2 CPUFUNC(op_4cd0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg (regs, dstreg);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = get_long (srca); srca += 4; dmask = movem_next[dmask]; readcycles += 8; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = get_long (srca); srca += 4; amask = movem_next[amask]; readcycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return (readcycles + 12) * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_4cd8_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg (regs, dstreg);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = get_long (srca); srca += 4; dmask = movem_next[dmask]; readcycles += 8; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = get_long (srca); srca += 4; amask = movem_next[amask]; readcycles += 8; }
	m68k_areg (regs, dstreg) = srca;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}	m68k_incpc (4);
return (readcycles + 12) * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4ce8_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = get_long (srca); srca += 4; dmask = movem_next[dmask]; readcycles += 8; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = get_long (srca); srca += 4; amask = movem_next[amask]; readcycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (readcycles + 16) * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4cf0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 6));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = get_long (srca); srca += 4; dmask = movem_next[dmask]; readcycles += 8; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = get_long (srca); srca += 4; amask = movem_next[amask]; readcycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (readcycles + 18) * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4cf8_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = get_long (srca); srca += 4; dmask = movem_next[dmask]; readcycles += 8; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = get_long (srca); srca += 4; amask = movem_next[amask]; readcycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (readcycles + 16) * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4cf9_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = get_long_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = get_long (srca); srca += 4; dmask = movem_next[dmask]; readcycles += 8; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = get_long (srca); srca += 4; amask = movem_next[amask]; readcycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 10);
}}}}	m68k_incpc (8);
return (readcycles + 20) * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_4cfa_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = 2;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_getpc (regs) + 4;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 6);
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = get_long (srca); srca += 4; dmask = movem_next[dmask]; readcycles += 8; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = get_long (srca); srca += 4; amask = movem_next[amask]; readcycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (readcycles + 16) * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4cfb_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 readcycles = 0;
	uae_u32 dstreg = 3;
{	uae_u16 mask = get_word_prefetch (regs, 4);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 4;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 6));
	if (srca & 1) {
	m68k_incpc (2);
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	while (dmask) { m68k_dreg (regs, movem_index1[dmask]) = get_long (srca); srca += 4; dmask = movem_next[dmask]; readcycles += 8; }
	while (amask) { m68k_areg (regs, movem_index1[amask]) = get_long (srca); srca += 4; amask = movem_next[amask]; readcycles += 8; }
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
}}}}	m68k_incpc (6);
return (readcycles + 18) * CYCLE_UNIT / 2;
}

/* TRAPQ.L #<data> */
unsigned long REGPARAM2 CPUFUNC(op_4e40_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 15);
{{	uae_u32 src = srcreg;
	m68k_incpc (2);
	Exception (src + 32, regs);
}}return 34 * CYCLE_UNIT / 2;
}

/* LINK.W An,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_4e50_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr olda;
	olda = m68k_areg (regs, 7) - 4;
	if (olda & 1) {
		exception3 (opcode, olda);
		return 50 * CYCLE_UNIT / 2;
	}
{	m68k_areg (regs, 7) = olda;
{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s16 offs = get_word_prefetch (regs, 4);
	put_long (olda,src);
	m68k_areg (regs, srcreg) = (m68k_areg (regs, 7));
	m68k_areg (regs, 7) += offs;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* UNLK.L An */
unsigned long REGPARAM2 CPUFUNC(op_4e58_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_areg (regs, srcreg);
	m68k_areg (regs, 7) = src;
{	uaecptr olda = m68k_areg (regs, 7);
	if (olda & 1) {
		exception3 (opcode, olda);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 old = get_long (olda);
	m68k_areg (regs, 7) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_areg (regs, srcreg) = (old);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* MVR2USP.L An */
unsigned long REGPARAM2 CPUFUNC(op_4e60_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uae_s32 src = m68k_areg (regs, srcreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	regs.usp = src;
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* MVUSP2R.L An */
unsigned long REGPARAM2 CPUFUNC(op_4e68_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_areg (regs, srcreg) = (regs.usp);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* RESET.L  */
unsigned long REGPARAM2 CPUFUNC(op_4e70_11)(uae_u32 opcode, struct regstruct &regs)
{
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	cpureset ();
	m68k_incpc (2);
	regs.irc = get_wordi (m68k_getpc(regs) + 4);
}}return 132 * CYCLE_UNIT / 2;
}

/* NOP.L  */
unsigned long REGPARAM2 CPUFUNC(op_4e71_11)(uae_u32 opcode, struct regstruct &regs)
{
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* STOP.L #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_4e72_11)(uae_u32 opcode, struct regstruct &regs)
{
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{	regs.sr = regs.irc;
	MakeFromSR (regs);
	m68k_setstopped ();
	m68k_incpc (4);
}}return 8 * CYCLE_UNIT / 2;
}

/* RTE.L  */
unsigned long REGPARAM2 CPUFUNC(op_4e73_11)(uae_u32 opcode, struct regstruct &regs)
{
{if (!regs.s) { Exception (8, regs); return 34 * CYCLE_UNIT / 2; }
{{	uaecptr sra = m68k_areg (regs, 7);
	if (sra & 1) {
		exception3 (opcode, sra);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 sr = get_word (sra);
	m68k_areg (regs, 7) += 2;
{	uaecptr pca = m68k_areg (regs, 7);
	if (pca & 1) {
		exception3 (opcode, pca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 pc = get_long (pca);
	m68k_areg (regs, 7) += 4;
	regs.sr = sr;
	m68k_setpc (regs, pc);
	MakeFromSR (regs);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* RTD.L #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_4e74_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr pca = m68k_areg (regs, 7);
	if (pca & 1) {
		exception3 (opcode, pca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 pc = get_long (pca);
	m68k_areg (regs, 7) += 4;
{	uae_s16 offs = get_word_prefetch (regs, 4);
	m68k_areg (regs, 7) += offs;
	if (pc & 1) {
		exception3i (0x4E74, pc);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, pc);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}
return 14 * CYCLE_UNIT / 2;
}

/* RTS.L  */
unsigned long REGPARAM2 CPUFUNC(op_4e75_11)(uae_u32 opcode, struct regstruct &regs)
{
{	uaecptr pc = m68k_getpc (regs);
	m68k_do_rts (regs);
	if (m68k_getpc (regs) & 1) {
		uaecptr faultpc = m68k_getpc (regs);
		m68k_setpc (regs, pc);
		exception3i (0x4E75, faultpc);
	  return 50 * CYCLE_UNIT / 2;
	}
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}return 20 * CYCLE_UNIT / 2;
}

/* TRAPV.L  */
unsigned long REGPARAM2 CPUFUNC(op_4e76_11)(uae_u32 opcode, struct regstruct &regs)
{
{	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	if (GET_VFLG ()) {
		Exception (7, regs);
		return 34 * CYCLE_UNIT / 2;
	}
}
return 4 * CYCLE_UNIT / 2;
}

/* RTR.L  */
unsigned long REGPARAM2 CPUFUNC(op_4e77_11)(uae_u32 opcode, struct regstruct &regs)
{
{	uaecptr oldpc = m68k_getpc (regs);
	MakeSR (regs);
{	uaecptr sra = m68k_areg (regs, 7);
	if (sra & 1) {
		exception3 (opcode, sra);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 sr = get_word (sra);
	m68k_areg (regs, 7) += 2;
{	uaecptr pca = m68k_areg (regs, 7);
	if (pca & 1) {
		exception3 (opcode, pca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 pc = get_long (pca);
	m68k_areg (regs, 7) += 4;
	regs.sr &= 0xFF00; sr &= 0xFF;
	regs.sr |= sr;
	m68k_setpc (regs, pc);
	MakeFromSR (regs);
	if (m68k_getpc (regs) & 1) {
		uaecptr faultpc = m68k_getpc (regs);
		m68k_setpc (regs, oldpc);
		exception3i (0x4E77, faultpc);
	  return 50 * CYCLE_UNIT / 2;
	}
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* JSR.L (An) */
unsigned long REGPARAM2 CPUFUNC(op_4e90_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uaecptr oldpc = m68k_getpc (regs) + 2;
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	m68k_areg (regs, 7) -= 4;
	put_long (m68k_areg (regs, 7), oldpc);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 20 * CYCLE_UNIT / 2;
}

/* JSR.L (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4ea8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)regs.irc;
{	uaecptr oldpc = m68k_getpc (regs) + 4;
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	m68k_areg (regs, 7) -= 4;
	put_long (m68k_areg (regs, 7), oldpc);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 18 * CYCLE_UNIT / 2;
}

/* JSR.L (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4eb0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), regs.irc);
{	uaecptr oldpc = m68k_getpc (regs) + 4;
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	m68k_areg (regs, 7) -= 4;
	put_long (m68k_areg (regs, 7), oldpc);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 22 * CYCLE_UNIT / 2;
}

/* JSR.L (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4eb8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)regs.irc;
{	uaecptr oldpc = m68k_getpc (regs) + 4;
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	m68k_areg (regs, 7) -= 4;
	put_long (m68k_areg (regs, 7), oldpc);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 18 * CYCLE_UNIT / 2;
}

/* JSR.L (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4eb9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca;
	srca = get_word_prefetch (regs, 4) << 16;
	srca |= regs.irc;
{	uaecptr oldpc = m68k_getpc (regs) + 6;
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	m68k_areg (regs, 7) -= 4;
	put_long (m68k_areg (regs, 7), oldpc);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 20 * CYCLE_UNIT / 2;
}

/* JSR.L (d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_4eba_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)regs.irc;
{	uaecptr oldpc = m68k_getpc (regs) + 4;
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	m68k_areg (regs, 7) -= 4;
	put_long (m68k_areg (regs, 7), oldpc);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 18 * CYCLE_UNIT / 2;
}

/* JSR.L (d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4ebb_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, regs.irc);
{	uaecptr oldpc = m68k_getpc (regs) + 4;
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	m68k_areg (regs, 7) -= 4;
	put_long (m68k_areg (regs, 7), oldpc);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 22 * CYCLE_UNIT / 2;
}

/* JMP.L (An) */
unsigned long REGPARAM2 CPUFUNC(op_4ed0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* JMP.L (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_4ee8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)regs.irc;
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 10 * CYCLE_UNIT / 2;
}

/* JMP.L (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4ef0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 14 * CYCLE_UNIT / 2;
}

/* JMP.L (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_4ef8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)regs.irc;
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 10 * CYCLE_UNIT / 2;
}

/* JMP.L (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_4ef9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca;
	srca = get_word_prefetch (regs, 4) << 16;
	srca |= regs.irc;
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* JMP.L (d16,PC) */
unsigned long REGPARAM2 CPUFUNC(op_4efa_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)regs.irc;
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 10 * CYCLE_UNIT / 2;
}

/* JMP.L (d8,PC,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_4efb_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3i (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_setpc (regs, srca);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 14 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_5000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(An) */
unsigned long REGPARAM2 CPUFUNC(op_5010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_5020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_5028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_5030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_5038_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_5039_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_long_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_5040_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDAQ.W #<data>,An */
unsigned long REGPARAM2 CPUFUNC(op_5048_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,(An) */
unsigned long REGPARAM2 CPUFUNC(op_5050_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5058_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_5060_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_5
/* ADDQ.W #<data>,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_5068_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_5070_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_5078_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_5079_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_5080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADDAQ.L #<data>,An */
unsigned long REGPARAM2 CPUFUNC(op_5088_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,(An) */
unsigned long REGPARAM2 CPUFUNC(op_5090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_50a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 22 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_50a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_50b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 26 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_50b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_50b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_50c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 0) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_50c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 0)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_50d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 0) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_50d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 0) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_50e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 0) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_50e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 0) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_50f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 0) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_50f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 0) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_50f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 0) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_5100_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(An) */
unsigned long REGPARAM2 CPUFUNC(op_5110_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5118_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_5120_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_5128_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_5130_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_5138_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_5139_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_long_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_5140_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBAQ.W #<data>,An */
unsigned long REGPARAM2 CPUFUNC(op_5148_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(An) */
unsigned long REGPARAM2 CPUFUNC(op_5150_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5158_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_5160_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_5168_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_5170_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_5178_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_5179_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_5180_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUBAQ.L #<data>,An */
unsigned long REGPARAM2 CPUFUNC(op_5188_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(An) */
unsigned long REGPARAM2 CPUFUNC(op_5190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_51a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 22 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_51a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_51b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 26 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_51b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_51b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_51c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 1) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_51c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 1)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_51d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 1) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_51d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 1) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_51e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 1) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_51e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 1) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_51f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 1) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_51f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 1) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_51f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 1) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_52c0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 2) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_52c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 2)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_52d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 2) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_52d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 2) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_52e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 2) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_52e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 2) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_52f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 2) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_52f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 2) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_52f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 2) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_53c0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 3) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_53c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 3)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_53d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 3) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_53d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 3) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_53e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 3) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_53e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 3) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_53f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 3) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_53f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 3) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_53f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 3) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_54c0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 4) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_54c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 4)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_54d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 4) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_54d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 4) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_54e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 4) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_54e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 4) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_54f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 4) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_54f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 4) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_54f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 4) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_55c0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 5) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_55c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 5)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_55d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 5) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_55d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 5) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_55e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 5) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_55e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 5) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_55f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 5) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_55f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 5) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_55f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 5) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_56c0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 6) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_56c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 6)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_56d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 6) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_56d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 6) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_56e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 6) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_56e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 6) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_56f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 6) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_56f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 6) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_56f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 6) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_57c0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 7) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_57c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 7)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_57d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 7) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_57d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 7) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_57e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 7) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_57e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 7) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_57f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 7) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_57f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 7) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_57f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 7) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_58c0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 8) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_58c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 8)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_58d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 8) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_58d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 8) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_58e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 8) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_58e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 8) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_58f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 8) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_58f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 8) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_58f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 8) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_59c0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 9) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_59c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 9)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_59d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 9) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_59d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 9) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_59e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 9) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_59e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 9) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_59f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 9) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_59f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 9) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_59f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 9) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_5ac0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 10) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_5ac8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 10)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_5ad0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 10) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5ad8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 10) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_5ae0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 10) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_5ae8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 10) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_5af0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 10) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_5af8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 10) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_5af9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 10) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_5bc0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 11) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_5bc8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 11)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_5bd0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 11) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5bd8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 11) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_5be0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 11) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_5be8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 11) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_5bf0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 11) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_5bf8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 11) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_5bf9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 11) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_5cc0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 12) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_5cc8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 12)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_5cd0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 12) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5cd8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 12) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_5ce0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 12) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_5ce8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 12) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_5cf0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 12) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_5cf8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 12) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_5cf9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 12) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_5dc0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 13) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_5dc8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 13)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_5dd0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 13) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5dd8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 13) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_5de0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 13) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_5de8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 13) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_5df0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 13) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_5df8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 13) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_5df9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 13) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_5ec0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 14) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_5ec8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 14)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_5ed0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 14) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5ed8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 14) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_5ee0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 14) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_5ee8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 14) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_5ef0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 14) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_5ef8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 14) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_5ef9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 14) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Scc.B Dn */
unsigned long REGPARAM2 CPUFUNC(op_5fc0_11)(uae_u32 opcode, struct regstruct &regs)
{
  uae_u32 cyc = 4;
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 15) ? 0xff : 0;
  if(val) cyc = 6;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpc (2);
return cyc * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_5fc8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = regs.irc;
	uaecptr oldpc = m68k_getpc (regs);
	if (!cctrue (regs.ccrflags, 15)) {
	m68k_incpc ((uae_s32)offs + 2);
		get_word_prefetch (regs, 0);
		m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)offs + 2);
				return 50 * CYCLE_UNIT / 2;
			}
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
			return 10 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpc (regs, oldpc + 4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (An) */
unsigned long REGPARAM2 CPUFUNC(op_5fd0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 15) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_5fd8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 15) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) */
unsigned long REGPARAM2 CPUFUNC(op_5fe0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	int val = cctrue (regs.ccrflags, 15) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_5fe8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 15) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_5ff0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 15) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_5ff8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	int val = cctrue (regs.ccrflags, 15) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_5ff9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	int val = cctrue (regs.ccrflags, 15) ? 0xff : 0;
	put_byte (srca,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6000_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 0)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6001_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 0)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* BSR.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6100_11)(uae_u32 opcode, struct regstruct &regs)
{
{	uae_s32 s;
{	uae_s16 src = regs.irc;
	s = (uae_s32)src + 2;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + s);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_do_bsr (regs, m68k_getpc (regs) + 4, s);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 18 * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_6
/* BSRQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6101_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{	uae_s32 s;
{	uae_u32 src = srcreg;
	s = (uae_s32)src + 2;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + s);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_do_bsr (regs, m68k_getpc (regs) + 2, s);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 18 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6200_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 2)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6201_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 2)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6300_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 3)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6301_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 3)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6400_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 4)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6401_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 4)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6500_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 5)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6501_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 5)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6600_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 6)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6601_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 6)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6700_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 7)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6701_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 7)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6800_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 8)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6801_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 8)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6900_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 9)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6901_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 9)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6a00_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 10)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6a01_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 10)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6b00_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 11)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6b01_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 11)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6c00_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 12)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6c01_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 12)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6d00_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 13)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6d01_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 13)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6e00_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 14)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6e01_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 14)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W */
unsigned long REGPARAM2 CPUFUNC(op_6f00_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uae_s16 src = regs.irc;
	if (!cctrue (regs.ccrflags, 15)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (4);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> */
unsigned long REGPARAM2 CPUFUNC(op_6f01_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (regs.ccrflags, 15)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpc (regs) + 2 + (uae_s32)src);
		return 50 * CYCLE_UNIT / 2;
	}
	m68k_incpc ((uae_s32)src + 2);
	get_word_prefetch (regs, 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}
return 8 * CYCLE_UNIT / 2;
}

/* MOVEQ.L #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_7000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_u32 src = srcreg;
{	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpc (2);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* OR.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_8000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* OR.B (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_8010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* OR.B (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_8018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* OR.B -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_8020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* OR.B (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_8028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.B (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_8030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* OR.B (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_8038_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.B (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_8039_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* OR.B (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_803a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.B (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_803b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_803c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* OR.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_8040_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* OR.W (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_8050_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* OR.W (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_8058_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* OR.W -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_8060_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* OR.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_8068_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.W (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_8070_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* OR.W (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_8078_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.W (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_8079_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* OR.W (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_807a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.W (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_807b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_807c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* OR.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_8080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* OR.L (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_8090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* OR.L (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_8098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* OR.L -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_80a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* OR.L (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_80a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* OR.L (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_80b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* OR.L (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_80b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* OR.L (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_80b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* OR.L (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_80ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* OR.L (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_80bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_80bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* DIVU.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_80c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uae_s16 src = m68k_dreg (regs, srcreg);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (2);
		Exception (5, regs);
		return 38 * CYCLE_UNIT / 2;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (2);
	}
return getDivu68kCycles(dst, src) * CYCLE_UNIT / 2;
}

/* DIVU.W (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_80d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (2);
		Exception (5, regs);
		return 42 * CYCLE_UNIT / 2;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (2);
	}
return (getDivu68kCycles(dst, src) + 4) * CYCLE_UNIT / 2;
}

/* DIVU.W (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_80d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (2);
		Exception (5, regs);
		return 42 * CYCLE_UNIT / 2;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (2);
	}
return (getDivu68kCycles(dst, src) + 4) * CYCLE_UNIT / 2;
}

/* DIVU.W -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_80e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (2);
		Exception (5, regs);
		return 44 * CYCLE_UNIT / 2;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (2);
	}
return (getDivu68kCycles(dst, src) + 6) * CYCLE_UNIT / 2;
}

/* DIVU.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_80e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 46 * CYCLE_UNIT / 2;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivu68kCycles(dst, src) + 8) * CYCLE_UNIT / 2;
}

/* DIVU.W (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_80f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 48 * CYCLE_UNIT / 2;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivu68kCycles(dst, src) + 10) * CYCLE_UNIT / 2;
}

/* DIVU.W (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_80f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 46 * CYCLE_UNIT / 2;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivu68kCycles(dst, src) + 8) * CYCLE_UNIT / 2;
}

/* DIVU.W (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_80f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (6);
		Exception (5, regs);
		return 50 * CYCLE_UNIT / 2;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (6);
	}
return (getDivu68kCycles(dst, src) + 12) * CYCLE_UNIT / 2;
}

/* DIVU.W (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_80fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 50 * CYCLE_UNIT / 2;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivu68kCycles(dst, src) + 8) * CYCLE_UNIT / 2;
}

/* DIVU.W (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_80fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 52 * CYCLE_UNIT / 2;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivu68kCycles(dst, src) + 10) * CYCLE_UNIT / 2;
}

/* DIVU.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_80fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uae_s16 src = get_word_prefetch (regs, 4);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 42 * CYCLE_UNIT / 2;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivu68kCycles(dst, src) + 4) * CYCLE_UNIT / 2;
}

/* SBCD.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_8100_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 newv_lo = (dst & 0xF) - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = (dst & 0xF0) - (src & 0xF0);
	uae_u16 newv, tmp_newv;
	int bcd = 0;
	newv = tmp_newv = newv_hi + newv_lo;
	if (newv_lo & 0xF0) { newv -= 6; bcd = 6; };
	if ((((dst & 0xFF) - (src & 0xFF) - (GET_XFLG () ? 1 : 0)) & 0x100) > 0xFF) { newv -= 0x60; }
	SET_CFLG ((((dst & 0xFF) - (src & 0xFF) - bcd - (GET_XFLG () ? 1 : 0)) & 0x300) > 0xFF);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	SET_VFLG ((tmp_newv & 0x80) != 0 && (newv & 0x80) == 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* SBCD.B -(An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_8108_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 newv_lo = (dst & 0xF) - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = (dst & 0xF0) - (src & 0xF0);
	uae_u16 newv, tmp_newv;
	int bcd = 0;
	newv = tmp_newv = newv_hi + newv_lo;
	if (newv_lo & 0xF0) { newv -= 6; bcd = 6; };
	if ((((dst & 0xFF) - (src & 0xFF) - (GET_XFLG () ? 1 : 0)) & 0x100) > 0xFF) { newv -= 0x60; }
	SET_CFLG ((((dst & 0xFF) - (src & 0xFF) - bcd - (GET_XFLG () ? 1 : 0)) & 0x300) > 0xFF);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	SET_VFLG ((tmp_newv & 0x80) != 0 && (newv & 0x80) == 0);
	put_byte (dsta,newv);
}}}}}}	m68k_incpc (2);
return 18 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_8110_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_byte (dsta,src);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_8118_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_byte (dsta,src);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* OR.B Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_8120_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_byte (dsta,src);
}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_8128_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_8130_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
{	uae_s8 dst = get_byte (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_8138_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_8139_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* OR.W Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_8150_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_word (dsta,src);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* OR.W Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_8158_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_word (dsta,src);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* OR.W Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_8160_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_word (dsta,src);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* OR.W Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_8168_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.W Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_8170_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* OR.W Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_8178_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.W Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_8179_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* OR.L Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_8190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_long (dsta,src);
}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* OR.L Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_8198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_long (dsta,src);
}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* OR.L Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_81a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_long (dsta,src);
}}}}}	m68k_incpc (2);
return 22 * CYCLE_UNIT / 2;
}

/* OR.L Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_81a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,src);
}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* OR.L Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_81b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,src);
}}}}}	m68k_incpc (4);
return 26 * CYCLE_UNIT / 2;
}

/* OR.L Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_81b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,src);
}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* OR.L Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_81b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* DIVS.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_81c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uae_s16 src = m68k_dreg (regs, srcreg);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (2);
		Exception (5, regs);
		return 38 * CYCLE_UNIT / 2;
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (2);
	}
return (getDivs68kCycles(dst, src) + 0) * CYCLE_UNIT / 2;
}

/* DIVS.W (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_81d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (2);
		Exception (5, regs);
		return 46 * CYCLE_UNIT / 2;
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (2);
	}
return (getDivs68kCycles(dst, src) + 4) * CYCLE_UNIT / 2;
}

/* DIVS.W (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_81d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (2);
		Exception (5, regs);
		return 46 * CYCLE_UNIT / 2;
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (2);
	}
return (getDivs68kCycles(dst, src) + 4) * CYCLE_UNIT / 2;
}

/* DIVS.W -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_81e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (2);
		Exception (5, regs);
		return 48 * CYCLE_UNIT / 2;
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (2);
	}
return (getDivs68kCycles(dst, src) + 6) * CYCLE_UNIT / 2;
}

/* DIVS.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_81e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 50 * CYCLE_UNIT / 2;
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivs68kCycles(dst, src) + 8) * CYCLE_UNIT / 2;
}

/* DIVS.W (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_81f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 52 * CYCLE_UNIT / 2;
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivs68kCycles(dst, src) + 10) * CYCLE_UNIT / 2;
}

/* DIVS.W (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_81f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 50 * CYCLE_UNIT / 2;
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivs68kCycles(dst, src) + 8) * CYCLE_UNIT / 2;
}

/* DIVS.W (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_81f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (6);
		Exception (5, regs);
		return 54 * CYCLE_UNIT / 2;
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (6);
	}
return (getDivs68kCycles(dst, src) + 12) * CYCLE_UNIT / 2;
}

/* DIVS.W (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_81fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 50 * CYCLE_UNIT / 2;
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivs68kCycles(dst, src) + 8) * CYCLE_UNIT / 2;
}

/* DIVS.W (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_81fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 52 * CYCLE_UNIT / 2;
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivs68kCycles(dst, src) + 10) * CYCLE_UNIT / 2;
}

/* DIVS.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_81fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uae_s16 src = get_word_prefetch (regs, 4);
	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
	m68k_incpc (4);
		Exception (5, regs);
		return 42 * CYCLE_UNIT / 2;
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(newv)) == 0);
	SET_NFLG   (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpc (4);
	}
return (getDivs68kCycles(dst, src) + 4) * CYCLE_UNIT / 2;
}

/* SUB.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUB.B (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_9010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.B (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.B -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_9020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* SUB.B (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_9028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.B (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_9030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* SUB.B (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9038_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.B (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9039_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.B (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_903a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.B (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_903b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_903c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9040_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUB.W An,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9048_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUB.W (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_9050_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.W (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9058_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.W -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_9060_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* SUB.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_9068_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.W (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_9070_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* SUB.W (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9078_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.W (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9079_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.W (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_907a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.W (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_907b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_907c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.L An,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9088_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.L (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_9090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* SUB.L (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* SUB.L -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_90a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.L (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_90a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUB.L (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_90b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.L (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_90b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUB.L (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_90b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* SUB.L (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_90ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUB.L (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_90bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_90bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* SUBA.W Dn,An */
unsigned long REGPARAM2 CPUFUNC(op_90c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUBA.W An,An */
unsigned long REGPARAM2 CPUFUNC(op_90c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUBA.W (An),An */
unsigned long REGPARAM2 CPUFUNC(op_90d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUBA.W (An)+,An */
unsigned long REGPARAM2 CPUFUNC(op_90d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUBA.W -(An),An */
unsigned long REGPARAM2 CPUFUNC(op_90e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* SUBA.W (d16,An),An */
unsigned long REGPARAM2 CPUFUNC(op_90e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBA.W (d8,An,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_90f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUBA.W (xxx).W,An */
unsigned long REGPARAM2 CPUFUNC(op_90f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBA.W (xxx).L,An */
unsigned long REGPARAM2 CPUFUNC(op_90f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUBA.W (d16,PC),An */
unsigned long REGPARAM2 CPUFUNC(op_90fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBA.W (d8,PC,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_90fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUBA.W #<data>.W,An */
unsigned long REGPARAM2 CPUFUNC(op_90fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUBX.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9100_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBX.B -(An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_9108_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 18 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_9110_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_9118_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_9120_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_9128_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_9130_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_9138_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_9139_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUBX.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9140_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBX.W -(An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_9148_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_word (dsta,newv);
}}}}}}}}}	m68k_incpc (2);
return 18 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_9150_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_9158_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_9160_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_9168_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_9170_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_9178_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_9179_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUBX.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_9180_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUBX.L -(An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_9188_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_long (dsta,newv);
}}}}}}}}}	m68k_incpc (2);
return 30 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_9190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_9198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_91a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 22 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_91a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_91b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 26 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_91b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_91b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* SUBA.L Dn,An */
unsigned long REGPARAM2 CPUFUNC(op_91c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUBA.L An,An */
unsigned long REGPARAM2 CPUFUNC(op_91c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUBA.L (An),An */
unsigned long REGPARAM2 CPUFUNC(op_91d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* SUBA.L (An)+,An */
unsigned long REGPARAM2 CPUFUNC(op_91d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* SUBA.L -(An),An */
unsigned long REGPARAM2 CPUFUNC(op_91e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* SUBA.L (d16,An),An */
unsigned long REGPARAM2 CPUFUNC(op_91e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUBA.L (d8,An,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_91f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* SUBA.L (xxx).W,An */
unsigned long REGPARAM2 CPUFUNC(op_91f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUBA.L (xxx).L,An */
unsigned long REGPARAM2 CPUFUNC(op_91f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* SUBA.L (d16,PC),An */
unsigned long REGPARAM2 CPUFUNC(op_91fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* SUBA.L (d8,PC,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_91fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* SUBA.L #<data>.L,An */
unsigned long REGPARAM2 CPUFUNC(op_91fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMP.B (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.B (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.B -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* CMP.B (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.B (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* CMP.B (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b038_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.B (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b039_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.B (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b03a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.B (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b03b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b03c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b040_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMP.W An,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b048_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMP.W (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b050_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.W (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b058_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.W -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b060_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* CMP.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b068_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.W (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b070_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* CMP.W (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b078_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.W (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b079_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.W (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b07a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.W (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b07b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_7
/* CMP.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b07c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* CMP.L An,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b088_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* CMP.L (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* CMP.L (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* CMP.L -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b0a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.L (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b0a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* CMP.L (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b0b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* CMP.L (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b0b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* CMP.L (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b0b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* CMP.L (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b0ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* CMP.L (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_b0bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b0bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (6);
return 14 * CYCLE_UNIT / 2;
}

/* CMPA.W Dn,An */
unsigned long REGPARAM2 CPUFUNC(op_b0c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* CMPA.W An,An */
unsigned long REGPARAM2 CPUFUNC(op_b0c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* CMPA.W (An),An */
unsigned long REGPARAM2 CPUFUNC(op_b0d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* CMPA.W (An)+,An */
unsigned long REGPARAM2 CPUFUNC(op_b0d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* CMPA.W -(An),An */
unsigned long REGPARAM2 CPUFUNC(op_b0e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* CMPA.W (d16,An),An */
unsigned long REGPARAM2 CPUFUNC(op_b0e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* CMPA.W (d8,An,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_b0f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* CMPA.W (xxx).W,An */
unsigned long REGPARAM2 CPUFUNC(op_b0f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* CMPA.W (xxx).L,An */
unsigned long REGPARAM2 CPUFUNC(op_b0f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (6);
return 18 * CYCLE_UNIT / 2;
}

/* CMPA.W (d16,PC),An */
unsigned long REGPARAM2 CPUFUNC(op_b0fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* CMPA.W (d8,PC,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_b0fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* CMPA.W #<data>.W,An */
unsigned long REGPARAM2 CPUFUNC(op_b0fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (4);
return 10 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b100_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMPM.B (An)+,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_b108_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_b110_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_byte (dsta,src);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_b118_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_byte (dsta,src);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_b120_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_byte (dsta,src);
}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_b128_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_b130_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
{	uae_s8 dst = get_byte (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_b138_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_b139_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b140_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMPM.W (An)+,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_b148_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_b150_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_word (dsta,src);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_b158_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_word (dsta,src);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_b160_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_word (dsta,src);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_b168_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_b170_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_b178_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_b179_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_b180_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* CMPM.L (An)+,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_b188_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_b190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_long (dsta,src);
}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_b198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_long (dsta,src);
}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_b1a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_long (dsta,src);
}}}}}	m68k_incpc (2);
return 22 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_b1a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,src);
}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_b1b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,src);
}}}}}	m68k_incpc (4);
return 26 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_b1b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,src);
}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_b1b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* CMPA.L Dn,An */
unsigned long REGPARAM2 CPUFUNC(op_b1c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* CMPA.L An,An */
unsigned long REGPARAM2 CPUFUNC(op_b1c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* CMPA.L (An),An */
unsigned long REGPARAM2 CPUFUNC(op_b1d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* CMPA.L (An)+,An */
unsigned long REGPARAM2 CPUFUNC(op_b1d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* CMPA.L -(An),An */
unsigned long REGPARAM2 CPUFUNC(op_b1e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* CMPA.L (d16,An),An */
unsigned long REGPARAM2 CPUFUNC(op_b1e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* CMPA.L (d8,An,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_b1f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* CMPA.L (xxx).W,An */
unsigned long REGPARAM2 CPUFUNC(op_b1f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* CMPA.L (xxx).L,An */
unsigned long REGPARAM2 CPUFUNC(op_b1f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* CMPA.L (d16,PC),An */
unsigned long REGPARAM2 CPUFUNC(op_b1fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* CMPA.L (d8,PC,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_b1fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* CMPA.L #<data>.L,An */
unsigned long REGPARAM2 CPUFUNC(op_b1fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpc (6);
return 14 * CYCLE_UNIT / 2;
}

/* AND.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* AND.B (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* AND.B (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* AND.B -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* AND.B (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.B (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* AND.B (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c038_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.B (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c039_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* AND.B (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c03a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.B (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c03b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c03c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* AND.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c040_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* AND.W (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c050_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* AND.W (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c058_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* AND.W -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c060_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* AND.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c068_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.W (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c070_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* AND.W (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c078_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.W (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c079_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* AND.W (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c07a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.W (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c07b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c07c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* AND.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* AND.L (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* AND.L (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* AND.L -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* AND.L (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* AND.L (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* AND.L (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* AND.L (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* AND.L (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* AND.L (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	m68k_dreg (regs, dstreg) = (src);
}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* MULU.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpc (2);
}}return (38 + bitset_count(src & 0xFFFF) * 2) * CYCLE_UNIT / 2;
}

/* MULU.W (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpc (2);
}}
return (42 + bitset_count(src & 0xFFFF) * 2) * CYCLE_UNIT / 2;
}

/* MULU.W (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpc (2);
}}
return (42 + bitset_count(src & 0xFFFF) * 2) * CYCLE_UNIT / 2;
}

/* MULU.W -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpc (2);
}}
return (44 + bitset_count(src & 0xFFFF) * 2) * CYCLE_UNIT / 2;
}

/* MULU.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpc (4);
}}
return (46 + bitset_count(src & 0xFFFF) * 2) * CYCLE_UNIT / 2;
}

/* MULU.W (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpc (4);
}}
return (48 + bitset_count(src & 0xFFFF) * 2) * CYCLE_UNIT / 2;
}

/* MULU.W (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpc (4);
}}
return (46 + bitset_count(src & 0xFFFF) * 2) * CYCLE_UNIT / 2;
}

/* MULU.W (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpc (6);
}}
return (50 + bitset_count(src & 0xFFFF) * 2) * CYCLE_UNIT / 2;
}

/* MULU.W (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpc (4);
}}
return (46 + bitset_count(src & 0xFFFF) * 2) * CYCLE_UNIT / 2;
}

/* MULU.W (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpc (4);
}}
return (48 + bitset_count(src & 0xFFFF) * 2) * CYCLE_UNIT / 2;
}

/* MULU.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c0fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpc (4);
}}return (42 + bitset_count(src & 0xFFFF) * 2) * CYCLE_UNIT / 2;
}

/* ABCD.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c100_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 newv_lo = (src & 0xF) + (dst & 0xF) + (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = (src & 0xF0) + (dst & 0xF0);
	uae_u16 newv, tmp_newv;
	int cflg;
	newv = tmp_newv = newv_hi + newv_lo;
	if (newv_lo > 9) { newv += 6; }
	cflg = (newv & 0x3F0) > 0x90;
	if (cflg) newv += 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	SET_VFLG ((tmp_newv & 0x80) == 0 && (newv & 0x80) != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* ABCD.B -(An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_c108_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 newv_lo = (src & 0xF) + (dst & 0xF) + (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = (src & 0xF0) + (dst & 0xF0);
	uae_u16 newv, tmp_newv;
	int cflg;
	newv = tmp_newv = newv_hi + newv_lo;
	if (newv_lo > 9) { newv += 6; }
	cflg = (newv & 0x3F0) > 0x90;
	if (cflg) newv += 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	SET_VFLG ((tmp_newv & 0x80) == 0 && (newv & 0x80) != 0);
	put_byte (dsta,newv);
}}}}}}	m68k_incpc (2);
return 18 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_c110_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_byte (dsta,src);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_c118_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_byte (dsta,src);
}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* AND.B Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_c120_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_byte (dsta,src);
}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_c128_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_c130_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
{	uae_s8 dst = get_byte (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_c138_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_byte (dsta,src);
}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_c139_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s8)(src)) == 0);
	SET_NFLG   (((uae_s8)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_byte (dsta,src);
}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* EXG.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c140_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, srcreg) = (dst);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* EXG.L An,An */
unsigned long REGPARAM2 CPUFUNC(op_c148_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_areg (regs, srcreg) = (dst);
	m68k_areg (regs, dstreg) = (src);
}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_c150_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_word (dsta,src);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_c158_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_word (dsta,src);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* AND.W Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_c160_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_word (dsta,src);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_c168_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_c170_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_c178_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_word (dsta,src);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_c179_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(src)) == 0);
	SET_NFLG   (((uae_s16)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_word (dsta,src);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* EXG.L Dn,An */
unsigned long REGPARAM2 CPUFUNC(op_c188_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	m68k_dreg (regs, srcreg) = (dst);
	m68k_areg (regs, dstreg) = (src);
}}}	m68k_incpc (2);
return 6 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_c190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_long (dsta,src);
}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_c198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_long (dsta,src);
}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* AND.L Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_c1a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
	put_long (dsta,src);
}}}}}	m68k_incpc (2);
return 22 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_c1a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,src);
}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_c1b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,src);
}}}}}	m68k_incpc (4);
return 26 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_c1b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
	put_long (dsta,src);
}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_c1b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(src)) == 0);
	SET_NFLG   (((uae_s32)(src)) < 0);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
	put_long (dsta,src);
}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* MULS.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c1c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}	m68k_incpc (2);
return (38 + bitset_count(src ^ (src << 1)) * 2) * CYCLE_UNIT / 2;
}

/* MULS.W (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c1d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}	m68k_incpc (2);
return (42 + bitset_count(src ^ (src << 1)) * 2) * CYCLE_UNIT / 2;
}

/* MULS.W (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c1d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}	m68k_incpc (2);
return (42 + bitset_count(src ^ (src << 1)) * 2) * CYCLE_UNIT / 2;
}

/* MULS.W -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c1e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}	m68k_incpc (2);
return (44 + bitset_count(src ^ (src << 1)) * 2) * CYCLE_UNIT / 2;
}

/* MULS.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c1e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}	m68k_incpc (4);
return (46 + bitset_count(src ^ (src << 1)) * 2) * CYCLE_UNIT / 2;
}

/* MULS.W (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c1f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}	m68k_incpc (4);
return (48 + bitset_count(src ^ (src << 1)) * 2) * CYCLE_UNIT / 2;
}

/* MULS.W (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c1f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}	m68k_incpc (4);
return (46 + bitset_count(src ^ (src << 1)) * 2) * CYCLE_UNIT / 2;
}

/* MULS.W (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c1f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}	m68k_incpc (6);
return (50 + bitset_count(src ^ (src << 1)) * 2) * CYCLE_UNIT / 2;
}

/* MULS.W (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c1fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}	m68k_incpc (4);
return (46 + bitset_count(src ^ (src << 1)) * 2) * CYCLE_UNIT / 2;
}

/* MULS.W (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_c1fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}	m68k_incpc (4);
return (48 + bitset_count(src ^ (src << 1)) * 2) * CYCLE_UNIT / 2;
}

/* MULS.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_c1fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s32)(newv)) == 0);
	SET_NFLG   (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}	m68k_incpc (4);
return (42 + bitset_count(src ^ (src << 1)) * 2) * CYCLE_UNIT / 2;
}

/* ADD.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADD.B (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.B (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.B -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* ADD.B (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.B (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* ADD.B (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d038_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.B (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d039_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.B (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d03a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.B (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d03b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
{	uae_s8 src = get_byte (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d03c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = (uae_u8)get_word_prefetch (regs, 4);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d040_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADD.W An,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d048_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADD.W (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d050_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.W (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d058_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.W -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d060_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (2);
return 10 * CYCLE_UNIT / 2;
}

/* ADD.W (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d068_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.W (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d070_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* ADD.W (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d078_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.W (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d079_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.W (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d07a_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.W (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d07b_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}	m68k_incpc (4);
return 14 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d07c_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpc (4);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.L An,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d088_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.L (An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ADD.L (An)+,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ADD.L -(An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d0a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.L (d16,An),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d0a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADD.L (d8,An,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d0b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.L (xxx).W,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d0b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADD.L (xxx).L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d0b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* ADD.L (d16,PC),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d0ba_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADD.L (d8,PC,Xn),Dn */
unsigned long REGPARAM2 CPUFUNC(op_d0bb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d0bc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* ADDA.W Dn,An */
unsigned long REGPARAM2 CPUFUNC(op_d0c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADDA.W An,An */
unsigned long REGPARAM2 CPUFUNC(op_d0c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADDA.W (An),An */
unsigned long REGPARAM2 CPUFUNC(op_d0d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADDA.W (An)+,An */
unsigned long REGPARAM2 CPUFUNC(op_d0d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) += 2;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADDA.W -(An),An */
unsigned long REGPARAM2 CPUFUNC(op_d0e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ADDA.W (d16,An),An */
unsigned long REGPARAM2 CPUFUNC(op_d0e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDA.W (d8,An,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_d0f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADDA.W (xxx).W,An */
unsigned long REGPARAM2 CPUFUNC(op_d0f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDA.W (xxx).L,An */
unsigned long REGPARAM2 CPUFUNC(op_d0f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADDA.W (d16,PC),An */
unsigned long REGPARAM2 CPUFUNC(op_d0fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDA.W (d8,PC,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_d0fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADDA.W #<data>.W,An */
unsigned long REGPARAM2 CPUFUNC(op_d0fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_word_prefetch (regs, 4);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADDX.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d100_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDX.B -(An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_d108_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 18 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_d110_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_d118_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_d120_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_d128_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_d130_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_d138_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_d139_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
{	uae_s8 dst = get_byte (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_byte (dsta,newv);
}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADDX.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d140_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}	m68k_incpc (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDX.W -(An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_d148_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 src = get_word (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_word (dsta,newv);
}}}}}}}}}	m68k_incpc (2);
return 18 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_d150_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_d158_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_d160_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_d168_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_d170_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_d178_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_d179_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 dst = get_word (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_word (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADDX.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_d180_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADDX.L -(An),-(An) */
unsigned long REGPARAM2 CPUFUNC(op_d188_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_long (dsta,newv);
}}}}}}}}}	m68k_incpc (2);
return 30 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(An) */
unsigned long REGPARAM2 CPUFUNC(op_d190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(An)+ */
unsigned long REGPARAM2 CPUFUNC(op_d198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) += 4;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,-(An) */
unsigned long REGPARAM2 CPUFUNC(op_d1a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	m68k_areg (regs, dstreg) = dsta;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (2);
return 22 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_d1a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_d1b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_disp_ea_000 (regs, m68k_areg (regs, dstreg), get_word_prefetch (regs, 4));
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 26 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_d1b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (4);
return 24 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_d1b9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta = get_long_prefetch (regs, 4);
	if (dsta & 1) {
		exception3 (opcode, dsta);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 dst = get_long (dsta);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_long (dsta,newv);
}}}}}}}}	m68k_incpc (6);
return 28 * CYCLE_UNIT / 2;
}

/* ADDA.L Dn,An */
unsigned long REGPARAM2 CPUFUNC(op_d1c0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADDA.L An,An */
unsigned long REGPARAM2 CPUFUNC(op_d1c8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADDA.L (An),An */
unsigned long REGPARAM2 CPUFUNC(op_d1d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ADDA.L (An)+,An */
unsigned long REGPARAM2 CPUFUNC(op_d1d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ADDA.L -(An),An */
unsigned long REGPARAM2 CPUFUNC(op_d1e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (2);
return 16 * CYCLE_UNIT / 2;
}

/* ADDA.L (d16,An),An */
unsigned long REGPARAM2 CPUFUNC(op_d1e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADDA.L (d8,An,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_d1f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* ADDA.L (xxx).W,An */
unsigned long REGPARAM2 CPUFUNC(op_d1f8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADDA.L (xxx).L,An */
unsigned long REGPARAM2 CPUFUNC(op_d1f9_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_long_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (6);
return 22 * CYCLE_UNIT / 2;
}

/* ADDA.L (d16,PC),An */
unsigned long REGPARAM2 CPUFUNC(op_d1fa_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc (regs) + 2;
	srca += (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ADDA.L (d8,PC,Xn),An */
unsigned long REGPARAM2 CPUFUNC(op_d1fb_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	tmppc = m68k_getpc (regs) + 2;
	srca = get_disp_ea_000 (regs, tmppc, get_word_prefetch (regs, 4));
	if (srca & 1) {
		exception3 (opcode, srca);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s32 src = get_long (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}	m68k_incpc (4);
return 20 * CYCLE_UNIT / 2;
}

/* ADDA.L #<data>.L,An */
unsigned long REGPARAM2 CPUFUNC(op_d1fc_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_long_prefetch (regs, 4);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpc (6);
return 16 * CYCLE_UNIT / 2;
}

/* ASRQ.B #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e000_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	uae_u32 sign = (0x80 & val) >> 7;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		val = 0xff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xff << (8 - cnt)) & (uae_u32)-sign;
		val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSRQ.B #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e008_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_CFLG ((cnt == 8) & (val >> 7));
		COPY_CARRY ();
		val = 0;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXRQ.B #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e010_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (7 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* RORQ.B #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e018_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 hival;
	cnt &= 7;
	hival = val << (8 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xff;
	SET_CFLG ((val & 0x80) >> 7);
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_8
/* ASR.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e020_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	uae_u32 sign = (0x80 & val) >> 7;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		val = 0xff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xff << (8 - cnt)) & (uae_u32)-sign;
		val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSR.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e028_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_CFLG ((cnt == 8) & (val >> 7));
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXR.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e030_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 36) cnt -= 36;
	if (cnt >= 18) cnt -= 18;
	if (cnt >= 9) cnt -= 9;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (7 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROR.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e038_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {	uae_u32 hival;
	cnt &= 7;
	hival = val << (8 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xff;
	SET_CFLG ((val & 0x80) >> 7);
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ASRQ.W #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e040_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = (0x8000 & val) >> 15;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		val = 0xffff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xffff << (16 - cnt)) & (uae_u32)-sign;
		val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSRQ.W #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e048_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_CFLG ((cnt == 16) & (val >> 15));
		COPY_CARRY ();
		val = 0;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXRQ.W #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e050_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (15 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* RORQ.W #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e058_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 hival;
	cnt &= 15;
	hival = val << (16 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffff;
	SET_CFLG ((val & 0x8000) >> 15);
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ASR.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e060_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = (0x8000 & val) >> 15;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		val = 0xffff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xffff << (16 - cnt)) & (uae_u32)-sign;
		val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSR.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e068_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_CFLG ((cnt == 16) & (val >> 15));
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXR.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e070_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 34) cnt -= 34;
	if (cnt >= 17) cnt -= 17;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (15 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROR.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e078_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {	uae_u32 hival;
	cnt &= 15;
	hival = val << (16 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffff;
	SET_CFLG ((val & 0x8000) >> 15);
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ASRQ.L #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e080_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	uae_u32 sign = (0x80000000 & val) >> 31;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		val = 0xffffffff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xffffffff << (32 - cnt)) & (uae_u32)-sign;
		val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSRQ.L #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e088_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_CFLG ((cnt == 32) & (val >> 31));
		COPY_CARRY ();
		val = 0;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXRQ.L #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e090_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (31 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* RORQ.L #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e098_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 hival;
	cnt &= 31;
	hival = val << (32 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffffffff;
	SET_CFLG ((val & 0x80000000) >> 31);
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ASR.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e0a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	uae_u32 sign = (0x80000000 & val) >> 31;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		val = 0xffffffff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xffffffff << (32 - cnt)) & (uae_u32)-sign;
		val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSR.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e0a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_CFLG ((cnt == 32) & (val >> 31));
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXR.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e0b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 33) cnt -= 33;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (31 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROR.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e0b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {	uae_u32 hival;
	cnt &= 31;
	hival = val << (32 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffffffff;
	SET_CFLG ((val & 0x80000000) >> 31);
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ASRW.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_e0d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ASRW.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_e0d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ASRW.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_e0e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) = dataa;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ASRW.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_e0e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ASRW.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_e0f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ASRW.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_e0f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ASRW.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_e0f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = get_long_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ASLQ.B #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e100_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 8 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		uae_u32 mask = (0xff << (7 - cnt)) & 0xff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80) >> 7);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSLQ.B #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e108_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_CFLG (cnt == 8 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80) >> 7);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXLQ.B #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e110_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (7 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROLQ.B #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e118_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 loval;
	cnt &= 7;
	loval = val >> (8 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ASL.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e120_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 8 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		uae_u32 mask = (0xff << (7 - cnt)) & 0xff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80) >> 7);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSL.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e128_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_CFLG (cnt == 8 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80) >> 7);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXL.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e130_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 36) cnt -= 36;
	if (cnt >= 18) cnt -= 18;
	if (cnt >= 9) cnt -= 9;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (7 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROL.B Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e138_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {
	uae_u32 loval;
	cnt &= 7;
	loval = val >> (8 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ASLQ.W #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e140_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 16 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		uae_u32 mask = (0xffff << (15 - cnt)) & 0xffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x8000) >> 15);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSLQ.W #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e148_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_CFLG (cnt == 16 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x8000) >> 15);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXLQ.W #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e150_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (15 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROLQ.W #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e158_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 loval;
	cnt &= 15;
	loval = val >> (16 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ASL.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e160_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 16 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		uae_u32 mask = (0xffff << (15 - cnt)) & 0xffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x8000) >> 15);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSL.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e168_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_CFLG (cnt == 16 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x8000) >> 15);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXL.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e170_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 34) cnt -= 34;
	if (cnt >= 17) cnt -= 17;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (15 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROL.W Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e178_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {
	uae_u32 loval;
	cnt &= 15;
	loval = val >> (16 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpc (2);
return (6 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ASLQ.L #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e180_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 32 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		uae_u32 mask = (0xffffffff << (31 - cnt)) & 0xffffffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80000000) >> 31);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSLQ.L #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e188_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_CFLG (cnt == 32 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80000000) >> 31);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXLQ.L #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e190_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (31 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROLQ.L #<data>,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e198_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 loval;
	cnt &= 31;
	loval = val >> (32 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffffffff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ASL.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e1a0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 32 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		uae_u32 mask = (0xffffffff << (31 - cnt)) & 0xffffffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80000000) >> 31);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* LSL.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e1a8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_CFLG (cnt == 32 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80000000) >> 31);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROXL.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e1b0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 33) cnt -= 33;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (31 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ROL.L Dn,Dn */
unsigned long REGPARAM2 CPUFUNC(op_e1b8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {
	uae_u32 loval;
	cnt &= 31;
	loval = val >> (32 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffffffff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpc (2);
return (8 + cnt * 2) * CYCLE_UNIT / 2;
}

/* ASLW.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_e1d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ASLW.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_e1d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ASLW.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_e1e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) = dataa;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ASLW.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_e1e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ASLW.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_e1f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ASLW.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_e1f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ASLW.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_e1f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = get_long_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_word (dataa,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* LSRW.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_e2d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* LSRW.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_e2d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* LSRW.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_e2e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) = dataa;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* LSRW.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_e2e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* LSRW.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_e2f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* LSRW.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_e2f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* LSRW.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_e2f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = get_long_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* LSLW.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_e3d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* LSLW.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_e3d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* LSLW.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_e3e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) = dataa;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* LSLW.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_e3e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* LSLW.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_e3f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* LSLW.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_e3f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* LSLW.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_e3f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = get_long_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ROXRW.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_e4d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ROXRW.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_e4d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ROXRW.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_e4e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) = dataa;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ROXRW.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_e4e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROXRW.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_e4f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ROXRW.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_e4f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROXRW.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_e4f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = get_long_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ROXLW.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_e5d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ROXLW.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_e5d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ROXLW.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_e5e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) = dataa;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ROXLW.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_e5e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROXLW.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_e5f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ROXLW.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_e5f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROXLW.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_e5f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = get_long_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_word (dataa,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* RORW.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_e6d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* RORW.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_e6d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* RORW.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_e6e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) = dataa;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* RORW.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_e6e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* RORW.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_e6f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* RORW.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_e6f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* RORW.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_e6f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = get_long_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_word (dataa,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

/* ROLW.W (An) */
unsigned long REGPARAM2 CPUFUNC(op_e7d0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ROLW.W (An)+ */
unsigned long REGPARAM2 CPUFUNC(op_e7d8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) += 2;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 12 * CYCLE_UNIT / 2;
}

/* ROLW.W -(An) */
unsigned long REGPARAM2 CPUFUNC(op_e7e0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	m68k_areg (regs, srcreg) = dataa;
	regs.ir = regs.irc;
	get_word_prefetch (regs, 4);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_word (dataa,val);
}}}}}	m68k_incpc (2);
return 14 * CYCLE_UNIT / 2;
}

/* ROLW.W (d16,An) */
unsigned long REGPARAM2 CPUFUNC(op_e7e8_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROLW.W (d8,An,Xn) */
unsigned long REGPARAM2 CPUFUNC(op_e7f0_11)(uae_u32 opcode, struct regstruct &regs)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = get_disp_ea_000 (regs, m68k_areg (regs, srcreg), get_word_prefetch (regs, 4));
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 18 * CYCLE_UNIT / 2;
}

/* ROLW.W (xxx).W */
unsigned long REGPARAM2 CPUFUNC(op_e7f8_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = (uae_s32)(uae_s16)get_word_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 6);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_word (dataa,val);
}}}}}	m68k_incpc (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROLW.W (xxx).L */
unsigned long REGPARAM2 CPUFUNC(op_e7f9_11)(uae_u32 opcode, struct regstruct &regs)
{
{{	uaecptr dataa = get_long_prefetch (regs, 4);
	if (dataa & 1) {
		exception3 (opcode, dataa);
		return 50 * CYCLE_UNIT / 2;
	}
{{	uae_s16 data = get_word (dataa);
	regs.ir = regs.irc;
	get_word_prefetch (regs, 8);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG   (((uae_s16)(val)) == 0);
	SET_NFLG   (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_word (dataa,val);
}}}}}	m68k_incpc (6);
return 20 * CYCLE_UNIT / 2;
}

#endif

