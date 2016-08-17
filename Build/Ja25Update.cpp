#ifdef PRECOMPILEDHEADERS
#include "Tactical All.h"
#else
#include "BuildDefines.h"
#include <wchar.h>
#include <stdio.h>
#include <string.h>
#include "Render Fun.h"
#include "stdlib.h"
#include "Debug.h"
#include "MemMan.h"
#include "Overhead Types.h"
//#include "Soldier Control.h"
#include "Animation Cache.h"
#include "Animation Data.h"
#include "Animation Control.h"
#include "Container.h"
#include <math.h>
#include "PathAI.h"
#include "Random.h"
#include "Isometric Utils.h"
#include "RenderWorld.h"
#include "Video.h"
#include "Weapons.h"
#include "VObject_blitters.h"
#include "Handle UI.h"
#include "Event Pump.h"
#include "AI.h"
#include "Interface.h"
#include "Lighting.h"
#include "Faces.h"
#include "Soldier Profile.h"
#include "Soldier Macros.h"
#include "English.h"
#include "Squads.h"

#ifdef NETWORKED
#include "Networking.h"
#include "NetworkEvent.h"
#endif
#include "Items.h"
#include "SoundMan.h"
#include "Utilities.h"
#include "Strategic.h"
#include "Soldier Tile.h"
#include "Smell.h"
#include "Keys.h"
#include "Dialogue Control.h"
#include "Soldier Functions.h"
#include "Exit Grids.h"
#include "Quests.h"
#include "Message.h"
#include "SkillCheck.h"
#include "Interface Dialogue.h"
#include	"GameSettings.h"
#include "ShopKeeper Interface.h"
#include "Vehicles.h"
#include "StrategicMap.h"
#include "Morale.h"
#include "Drugs And Alcohol.h"
#include "SkillCheck.h"
#include "Map Information.h"
#include "Buildings.h"
#include "Text.h"
#include "Campaign Types.h"
#include "Strategic Status.h"
#include "Civ Quotes.h"
#include "Debug Control.h"
#endif

#ifdef JA2UB

#include "Ja25_Tactical.h"
#include "Ja25 Strategic Ai.h"

INT16 JA2_5_START_SECTOR_X;
INT16 JA2_5_START_SECTOR_Y;

//** Defines *******************************************************************

//Starting money
#define JA2_5_STARTING_MONEY_EASY			40000
#define JA2_5_STARTING_MONEY_MEDIUM		35000
#define JA2_5_STARTING_MONEY_HARD			30000


#define	JA2SAVE_CONV_FILENAME		"..\\SavedGames\\Ja2.dts"

typedef struct
{
	INT8		bMercID;
	INT8		bPercentStatIncrease;
} STAT_CHANGE;

#define	NUM_MERCS_TO_USE_IN_PERCENT_STAT_INCREASE			6

#define	MAX_STAT_INCREASE	30

#endif

//******************************************************************************
