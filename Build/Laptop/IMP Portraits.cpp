#ifdef PRECOMPILEDHEADERS
	#include "Laptop All.h"
#else
	#include "CharProfile.h"
	#include "IMP Portraits.h"
	#include "IMP MainPage.h"
	#include "IMPVideoObjects.h"
	#include "Utilities.h"
	#include "WCheck.h"
	#include "Input.h"
	#include "Isometric Utils.h"
	#include "Debug.h"
	#include "WordWrap.h"
	#include "Encrypted File.h"
	#include "Cursors.h"
	#include "Laptop.h"
	#include "IMP Text System.h"
#endif

#include "IMP Confirm.h"

//current and last pages
INT32 iCurrentPortrait = 0;
INT32 iLastPicture = 7;

INT32 iLastPictureF;
INT32 iLastPictureM;

// buttons needed for the IMP portrait screen
INT32 giIMPPortraitButton[ 3 ];
INT32 giIMPPortraitButtonImage[ 3 ];

// redraw protrait screen
BOOLEAN fReDrawPortraitScreenFlag = FALSE;

// face index
INT32 iPortraitNumber = 0;


// function definitions

void IncrementPictureIndex( void );
void DecrementPicture( void );
void CreateIMPPortraitButtons( void );
void DestroyIMPPortraitButtons( void );
BOOLEAN CameBackToPortraitsPageButNotFinished();

// callbacks
void BtnIMPPortraitNextCallback(GUI_BUTTON *btn,INT32 reason);
void BtnIMPPortraitPreviousCallback(GUI_BUTTON *btn,INT32 reason);
void BtnIMPPortraitDoneCallback(GUI_BUTTON *btn,INT32 reason);

void EnterIMPPortraits( void )
{

	iCurrentPortrait = 0;
		// create buttons
	CreateIMPPortraitButtons( );

	// render background
	RenderIMPPortraits( );


	return;
}


void RenderIMPPortraits( void )
{


	// render background
	RenderProfileBackGround( );

		// the Voices frame
	RenderPortraitFrame( 191, 167 );

	// render the current portrait
	RenderPortrait( 200, 176 );

	// indent for the text
	RenderAttrib1IndentFrame( 128, 65);

	// text
	PrintImpText( );

	return;
}


void ExitIMPPortraits( void )
{
	// destroy buttons for IMP portrait page
	DestroyIMPPortraitButtons( );

	return;
}

void HandleIMPPortraits( void )
{

	// do we need to re write screen
	if ( fReDrawPortraitScreenFlag == TRUE )
	{
	RenderIMPPortraits( );

		// reset redraw flag
		fReDrawPortraitScreenFlag = FALSE;
	}
	return;
}


BOOLEAN RenderPortrait( INT16 sX, INT16 sY )
{
	// render the portrait of the current picture
	VOBJECT_DESC	VObjectDesc;
	HVOBJECT hHandle;
	UINT32 uiGraphicHandle;

	if( fCharacterIsMale	)
	{

		// load it
	VObjectDesc.fCreateFlags=VOBJECT_CREATE_FROMFILE;


		if (  gIMPMaleValues[ iCurrentPortrait ].Enabled == 1 )
		{
			///sprintf( VObjectDesc.ImageFile, "Faces\\BigFaces\\%02d.sti", gIMPMaleValues[ iCurrentPortrait ].PortraitId );
			sprintf( VObjectDesc.ImageFile, "IMPFaces\\BigFaces\\%02d.sti", gIMPMaleValues[ iCurrentPortrait ].PortraitId );
		}


	//FilenameForBPP( pPlayerSelectedBigFaceFileNames[ iCurrentPortrait ] , VObjectDesc.ImageFile);
	CHECKF(AddVideoObject(&VObjectDesc, &uiGraphicHandle));

	// show it
	GetVideoObject(&hHandle, uiGraphicHandle);
	BltVideoObject(FRAME_BUFFER, hHandle, 0, LAPTOP_SCREEN_UL_X + sX, LAPTOP_SCREEN_WEB_UL_Y + sY , VO_BLT_SRCTRANSPARENCY,NULL);


	// and kick it's sorry ..umm never mind, outta here
	DeleteVideoObjectFromIndex( uiGraphicHandle );


	}
	else
	{
		// load it
	VObjectDesc.fCreateFlags=VOBJECT_CREATE_FROMFILE;

	//FilenameForBPP( pPlayerSelectedBigFaceFileNames[ iCurrentPortrait + 8 ] , VObjectDesc.ImageFile);

		if (  gIMPFemaleValues[ iCurrentPortrait ].Enabled == 1 )
		{
		//	sprintf( VObjectDesc.ImageFile, "Faces\\BigFaces\\%02d.sti", gIMPFemaleValues[ iCurrentPortrait ].PortraitId );
			sprintf( VObjectDesc.ImageFile, "IMPFaces\\BigFaces\\%02d.sti", gIMPFemaleValues[ iCurrentPortrait ].PortraitId );
		}


	CHECKF(AddVideoObject(&VObjectDesc, &uiGraphicHandle));

	// show it
	GetVideoObject(&hHandle, uiGraphicHandle);
	BltVideoObject(FRAME_BUFFER, hHandle, 0, LAPTOP_SCREEN_UL_X + sX, LAPTOP_SCREEN_WEB_UL_Y + sY , VO_BLT_SRCTRANSPARENCY,NULL);


	// and kick it's sorry ..umm never mind, outta here
	DeleteVideoObjectFromIndex( uiGraphicHandle );

	}

	return ( TRUE );
}

void IncrementPictureIndex( void )
{

iCurrentPortrait++;
if( fCharacterIsMale )
{
	if( gIMPMaleValues[iCurrentPortrait].uiIndex == iCurrentPortrait && gIMPMaleValues[iCurrentPortrait].PortraitId !=0 )
	{
		iCurrentPortrait = gIMPMaleValues[iCurrentPortrait].uiIndex;
	}
	else
	{
		iCurrentPortrait = 0;
	}
}
else
{
	if( gIMPFemaleValues[iCurrentPortrait].uiIndex == iCurrentPortrait && gIMPFemaleValues[iCurrentPortrait].PortraitId !=0 )
	{
		iCurrentPortrait = gIMPFemaleValues[iCurrentPortrait].uiIndex;
	}
	else
	{
		iCurrentPortrait = 0;
	}

}
	// cycle to next picture
/*
	iCurrentPortrait++;

	// gone too far?
	if( iCurrentPortrait > iLastPicture )
	{
		iCurrentPortrait = 0;
	}

*/
	return;
}

void DecrementPicture( void )
{
UINT32 cnt;
UINT32 idPort = 0;


if( fCharacterIsMale )
{
	for ( cnt = 0; cnt < MAX_NEW_IMP_PORTRAITS; cnt++ )
		{
			if ( gIMPMaleValues[cnt].uiIndex == cnt && gIMPMaleValues[cnt].PortraitId !=0 )
				{
					iLastPictureM = gIMPMaleValues[cnt].uiIndex;
				}
		}

		iLastPicture = iLastPictureM;
}
else
{
	for ( cnt = 0; cnt < MAX_NEW_IMP_PORTRAITS; cnt++ )
		{
			if ( gIMPFemaleValues[cnt].uiIndex == cnt && gIMPFemaleValues[cnt].PortraitId !=0 )
				{
					iLastPictureF = gIMPFemaleValues[cnt].uiIndex;
				}
		}

		iLastPicture = iLastPictureF;
}

iCurrentPortrait--;
if( fCharacterIsMale )
{
	if( iCurrentPortrait < 0 )
	{
		iCurrentPortrait = iLastPicture;
	}
}
else
{
	if( iCurrentPortrait < 0 )
	{
		iCurrentPortrait = iLastPicture;
	}

}
/*
	// gone too far?
	if( iCurrentPortrait < 0 )
	{
		iCurrentPortrait = iLastPicture;
	}
*/
	return;
}


void CreateIMPPortraitButtons( void )
{
	// will create buttons need for the IMP portrait screen

	// next button
	giIMPPortraitButtonImage[0]=	LoadButtonImage( "LAPTOP\\voicearrows.sti" ,-1,1,-1,3,-1 );
	/*giIMPPortraitButton[0] = QuickCreateButton( giIMPPortraitButtonImage[0], LAPTOP_SCREEN_UL_X +	( 18 ), LAPTOP_SCREEN_WEB_UL_Y + ( 184 ),
										BUTTON_TOGGLE, MSYS_PRIORITY_HIGHEST - 1,
										BtnGenericMouseMoveButtonCallback, (GUI_CALLBACK)BtnIMPPortraitNextCallback );
	*/
	giIMPPortraitButton[0] = CreateIconAndTextButton( giIMPPortraitButtonImage[0], pImpButtonText[ 13 ], FONT12ARIAL,
														FONT_WHITE, DEFAULT_SHADOW,
														FONT_WHITE, DEFAULT_SHADOW,
														TEXT_CJUSTIFIED,
														LAPTOP_SCREEN_UL_X +	( 343 ), LAPTOP_SCREEN_WEB_UL_Y + ( 205 ),BUTTON_TOGGLE, MSYS_PRIORITY_HIGH,
															BtnGenericMouseMoveButtonCallback, (GUI_CALLBACK)BtnIMPPortraitNextCallback);


	// previous button
	giIMPPortraitButtonImage[ 1 ]=	LoadButtonImage( "LAPTOP\\voicearrows.sti" ,-1,0,-1,2,-1 );
/*	giIMPPortraitButton[ 1 ] = QuickCreateButton( giIMPPortraitButtonImage[ 1 ], LAPTOP_SCREEN_UL_X +	( 18 ), LAPTOP_SCREEN_WEB_UL_Y + ( 254 ),
										BUTTON_TOGGLE, MSYS_PRIORITY_HIGHEST - 1,
										BtnGenericMouseMoveButtonCallback, (GUI_CALLBACK)BtnIMPPortraitPreviousCallback );
	*/
	giIMPPortraitButton[ 1 ] = CreateIconAndTextButton( giIMPPortraitButtonImage[ 1 ], pImpButtonText[ 12 ], FONT12ARIAL,
														FONT_WHITE, DEFAULT_SHADOW,
														FONT_WHITE, DEFAULT_SHADOW,
														TEXT_CJUSTIFIED,
														LAPTOP_SCREEN_UL_X +	( 93), LAPTOP_SCREEN_WEB_UL_Y + ( 205 ), BUTTON_TOGGLE, MSYS_PRIORITY_HIGH,
															BtnGenericMouseMoveButtonCallback, (GUI_CALLBACK)BtnIMPPortraitPreviousCallback);


	// done button
	giIMPPortraitButtonImage[ 2 ]=	LoadButtonImage( "LAPTOP\\button_5.sti" ,-1,0,-1,1,-1 );
	/* giIMPPortraitButton[ 2 ] = QuickCreateButton( giIMPPortraitButtonImage[ 1 ], LAPTOP_SCREEN_UL_X +	( 349 ), LAPTOP_SCREEN_WEB_UL_Y + ( 220 ),
										BUTTON_TOGGLE, MSYS_PRIORITY_HIGHEST - 1,
										BtnGenericMouseMoveButtonCallback, (GUI_CALLBACK)BtnIMPPortraitDoneCallback );
	*/
	giIMPPortraitButton[ 2 ] = CreateIconAndTextButton( giIMPPortraitButtonImage[ 2 ], pImpButtonText[ 13 ], FONT12ARIAL,	// changed text on button to [13]("Next") - SANDRO
														FONT_WHITE, DEFAULT_SHADOW,
														FONT_WHITE, DEFAULT_SHADOW,
														TEXT_CJUSTIFIED,
														LAPTOP_SCREEN_UL_X +	( 187 ), LAPTOP_SCREEN_WEB_UL_Y + ( 330 ), BUTTON_TOGGLE, MSYS_PRIORITY_HIGH,
															BtnGenericMouseMoveButtonCallback, (GUI_CALLBACK)BtnIMPPortraitDoneCallback);



	SetButtonCursor(giIMPPortraitButton[0], CURSOR_WWW);
	SetButtonCursor(giIMPPortraitButton[1], CURSOR_WWW);
	SetButtonCursor(giIMPPortraitButton[2], CURSOR_WWW);
}



void DestroyIMPPortraitButtons( void )
{

	// will destroy buttons created for IMP Portrait screen

	// the next button
	RemoveButton(giIMPPortraitButton[ 0 ] );
	UnloadButtonImage(giIMPPortraitButtonImage[ 0 ] );

	// the previous button
	RemoveButton(giIMPPortraitButton[ 1 ] );
	UnloadButtonImage(giIMPPortraitButtonImage[ 1 ] );

	// the done button
	RemoveButton(giIMPPortraitButton[ 2 ] );
	UnloadButtonImage(giIMPPortraitButtonImage[ 2 ] );

	return;
}


void BtnIMPPortraitNextCallback(GUI_BUTTON *btn,INT32 reason)
{

	// btn callback for IMP attrbite begin button
	if (!(btn->uiFlags & BUTTON_ENABLED))
		return;

	if(reason & MSYS_CALLBACK_REASON_LBUTTON_DWN )
	{
		btn->uiFlags|=(BUTTON_CLICKED_ON);
	}
	else if(reason & MSYS_CALLBACK_REASON_LBUTTON_UP )
	{
		if (btn->uiFlags & BUTTON_CLICKED_ON)
		{
		btn->uiFlags&=~(BUTTON_CLICKED_ON);

			// next picture!!
			IncrementPictureIndex( );

			fReDrawPortraitScreenFlag = TRUE;
		}
	}
}

void BtnIMPPortraitPreviousCallback(GUI_BUTTON *btn,INT32 reason)
{

	// btn callback for IMP attrbite begin button
	if (!(btn->uiFlags & BUTTON_ENABLED))
		return;

	if(reason & MSYS_CALLBACK_REASON_LBUTTON_DWN )
	{
		btn->uiFlags|=(BUTTON_CLICKED_ON);
	}
	else if(reason & MSYS_CALLBACK_REASON_LBUTTON_UP )
	{
		if (btn->uiFlags & BUTTON_CLICKED_ON)
		{
		btn->uiFlags&=~(BUTTON_CLICKED_ON);

			// previous picture, please!!!
			DecrementPicture( );

			fReDrawPortraitScreenFlag = TRUE;
		}
	}
}

void BtnIMPPortraitDoneCallback(GUI_BUTTON *btn,INT32 reason)
{

	// btn callback for IMP attrbite begin button
	if (!(btn->uiFlags & BUTTON_ENABLED))
		return;

	if(reason & MSYS_CALLBACK_REASON_LBUTTON_DWN )
	{
		btn->uiFlags|=(BUTTON_CLICKED_ON);
	}
	else if(reason & MSYS_CALLBACK_REASON_LBUTTON_UP )
	{
		if (btn->uiFlags & BUTTON_CLICKED_ON)
		{
		btn->uiFlags&=~(BUTTON_CLICKED_ON);


		// Changed to go to voice selection after portrait selection - SANDRO
		iCurrentImpPage = IMP_VOICE;
		// Following part has been cut out

			// go to main page
			//iCurrentImpPage = IMP_MAIN_PAGE;
/*
			// current mode now is voice
		if( iCurrentProfileMode < IMP__VOICE )
			{
		iCurrentProfileMode = IMP__VOICE;
			}
*/
			// if we are already done, leave
	/* if( iCurrentProfileMode == IMP__FINISH )
			{
		iCurrentImpPage = IMP_FINISH;
			}
			else
			{
				if( CameBackToPortraitsPageButNotFinished() )
				{
//					iCurrentProfileMode = IMP__VOICE;
			iCurrentImpPage = IMP_MAIN_PAGE;
				}
				else
				{
					iCurrentProfileMode = IMP__VOICE;
				}
			}*/

			// grab picture number



			if( fCharacterIsMale	)
			{
				// male
				iPortraitNumber = gIMPMaleValues[ iCurrentPortrait ].uiIndex; //iCurrentPortrait
			}
			else
			{
				// female
				iPortraitNumber = gIMPFemaleValues[ iCurrentPortrait ].uiIndex; //iCurrentPortrait ;//+ ( 8 );
			}

			fButtonPendingFlag = TRUE;
		}
	}
}


BOOLEAN CameBackToPortraitsPageButNotFinished()
{
	//if we are in a page that comes after this one
	if( iCurrentProfileMode == IMP__PERSONALITY ||
			iCurrentProfileMode == IMP__ATTRIBUTES ||
			iCurrentProfileMode == IMP__VOICE )
	{
		return( TRUE );
	}
	else
	{
		return( FALSE );
	}
}
