#ifndef __SYSTEM_UTILS
#define __SYSTEM_UTILS

#include "Font.h"
#include "Isometric Utils.h"
#include "Interface.h"

// Global variables for video objects
extern UINT32					guiBOTTOMPANEL;
extern UINT32					guiRIGHTPANEL;
extern UINT32					guiRENDERBUFFER;
extern UINT32					guiSAVEBUFFER;
extern UINT32					guiEXTRABUFFER;

extern BOOLEAN gfExtraBuffer;

BOOLEAN	InitializeSystemVideoObjects( );
BOOLEAN	InitializeGameVideoObjects( );


#endif