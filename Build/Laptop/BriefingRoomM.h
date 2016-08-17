#ifndef __BRIEFINGROOMM_H
#define __BRIEFINGROOMM_H

#include "Cursors.h"
#include "Soldier Profile Type.h"

void GameInitBriefingRoomEnter();
BOOLEAN EnterBriefingRoomEnter();
void ExitBriefingRoomEnter();
void HandleBriefingRoomEnter();
void RenderBriefingRoomEnter();

BOOLEAN RemoveBriefingRoomEnterDefaults();
BOOLEAN InitBriefingRoomEnterDefaults();
BOOLEAN DrawBriefingRoomEnterDefaults();

BOOLEAN DisplayBriefingRoomEnterSlogan();
BOOLEAN DisplayBriefingRoomEnterCopyright();

#endif
