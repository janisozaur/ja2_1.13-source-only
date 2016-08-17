#ifndef _OPTIONS_SCREEN__H_
#define _OPTIONS_SCREEN__H_

#include "MessageBoxScreen.h"

#define		OPT_BUTTON_FONT												FONT14ARIAL
#define		OPT_BUTTON_FONT2											FONT10ARIAL //smaller button on options screen
#define		OPT_BUTTON_ON_COLOR										73//FONT_MCOLOR_WHITE
#define		OPT_BUTTON_OFF_COLOR									73//FONT_MCOLOR_WHITE



//Record the previous screen the user was in.
extern UINT32		guiPreviousOptionScreen;



UINT32	OptionsScreenShutdown( void );
UINT32	OptionsScreenHandle( void );
UINT32	OptionsScreenInit( void );



void SetOptionsScreenToggleBoxes();
void GetOptionsScreenToggleBoxes();
// OJW - moved this here so can exit options screen on client disconnect
void			SetOptionsExitScreen( UINT32 uiExitScreen );


BOOLEAN		DoOptionsMessageBox( UINT8 ubStyle, STR16 zString, UINT32 uiExitScreen, UINT16 usFlags, MSGBOX_CALLBACK ReturnCallback );


#endif
