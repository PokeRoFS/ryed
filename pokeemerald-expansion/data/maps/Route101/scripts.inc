.set LOCALID_BIRCH, 2
.set LOCALID_ZIGZAGOON, 4

Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	.byte 0

Route101_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	call ProfBirch_EventScript_AddLocation
	end

Route101_EventScript_StartBirchRescue::
	lockall
	playbgm MUS_HELP, TRUE
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_BIRCH, 0, 15
	setobjectxy LOCALID_ZIGZAGOON, 0, 16
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunAway1
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_BIRCH, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth:
	walk_up
	step_end

Route101_Movement_PreventExitWest:
	walk_right
	step_end

Route101_Movement_PreventExitNorth:
	walk_down
	step_end

Route101_Movement_ZigzagoonChaseInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_ZigzagoonChase1:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_ZigzagoonFaceBirch:
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	step_end

Route101_Movement_BirchRunInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFaceZigzagoon:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1:
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2:
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ZIGZAGOON
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Text_HelpMe:
	.string "H-help me!$"

Route101_Text_PleaseHelp:
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"

Route101_Text_DontLeaveMe:
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_Text_YouSavedMe:
	.string "HARSHBARGER: Whew…\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my lab later, okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter:
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route101_Text_WildPokemonInTallGrass:
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign:
	.string "ROUTE 101\n"
	.string "{UP_ARROW} OLDALE TOWN$"

Route101_EventScript_TalkToBirchDown0::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, MOVE_TO_BIRCH_RIGHT
	waitmovement 0
	goto Talk_To_Birch_Up
	end


Route101_EventScript_TalkToBirchDown1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, WALK_LEFT
	waitmovement 0
	goto Route101_EventScript_TalkToBirchDown0
	end


Route101_EventScript_TalkToBirch2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, WALK_UP
	waitmovement 0
	goto Route101_EventScript_TalkToBirchRight
	end


Route101_EventScript_TalkToBirch1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, WALK_UP
	waitmovement 0
	goto Route101_EventScript_TalkToBirch2
	end


Route101_EventScript_TalkToBirch0::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, WALK_UP
	waitmovement 0
	goto Route101_EventScript_TalkToBirch1
	end


Route101_EventScript_TalkToBirchRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, FACE_RIGHT
	waitmovement 0
	goto Talk_To_Birch_Right
	end


Route101_EventScript_TalkToBirchUp::
	lockall
	applymovement 2, FACE_DOWN
	waitmovement 0
	goto Talk_To_Birch_Up
	end


WALK_LEFT:
	walk_left
	step_end

WALK_UP:
	walk_up
	step_end

MOVE_TO_BIRCH_RIGHT:
	walk_down
	walk_left
	walk_left
	face_up
	step_end

Route101_EventScript_TalkToBirchRight0::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, WALK_LEFT
	waitmovement 0
	goto Talk_To_Birch_Up
	end


Talk_To_Birch_Up::
	applymovement OBJ_EVENT_ID_PLAYER, FACE_UP
	applymovement 2, FACE_DOWN
	waitmovement 0
	setflag Summon_Zigzagoon
	msgbox Talk_To_Birch_Up_Text_0
	msgbox Talk_To_Birch_Up_Text_1
	msgbox Talk_To_Birch_Up_Text_2
	addobject LOCALID_ZIGZAGOON
	applymovement LOCALID_ZIGZAGOON, MOVE_ZIG_TO_BIRCH
	applymovement 2, FACE_UP
	waitmovement 0
	msgbox Talk_To_Birch_Up_Text_3
	msgbox Talk_To_Birch_Up_Text_4
	applymovement OBJ_EVENT_ID_PLAYER, GET_TO_BAG_BELOW
	waitmovement 0
	goto OBJ_EVENT_GFX_BIRCHS_BAG
	return


Talk_To_Birch_Right::
	waitmovement 0
	setflag Summon_Zigzagoon
	msgbox Talk_To_Birch_Up_Text_0
	msgbox Talk_To_Birch_Up_Text_1
	msgbox Talk_To_Birch_Up_Text_2
	addobject LOCALID_ZIGZAGOON
	applymovement LOCALID_ZIGZAGOON, MOVE_ZIG_TO_BIRCH
	applymovement 2, FACE_UP
	waitmovement 0
	msgbox Talk_To_Birch_Up_Text_3
	msgbox Talk_To_Birch_Up_Text_4
	applymovement OBJ_EVENT_ID_PLAYER, GET_TO_BAG_LEFT
	waitmovement 0
	goto OBJ_EVENT_GFX_BIRCHS_BAG
	return


FACE_UP:
	face_up
	step_end

FACE_DOWN:
	face_down
	step_end

MOVE_ZIG_TO_BIRCH:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

GET_TO_BAG_LEFT:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	face_up
	step_end

GET_TO_BAG_BELOW:
	walk_fast_right
	face_up
	step_end

ProfBirch_EventScript_AddLocation::
	call_if_eq VAR_ROUTE101_STATE, 0, ADD_BIRCH
	return


ADD_BIRCH::
	addobject 2
	addobject 3
	return


Talk_To_Birch_Up_Text_0:
	.string "Harshbarger: {PLAYER}{KUN}!\n$"

Talk_To_Birch_Up_Text_1:
	.string "Now with Pokemon in the world\pthere should be Pokemon\plurking around.\n$"

Talk_To_Birch_Up_Text_2:
	.string "Let's see!\n$"

Talk_To_Birch_Up_Text_3:
	.string "Oh shit!\n$"

Talk_To_Birch_Up_Text_4:
	.string "Quick {PLAYER}{KUN}! Get a Pokemon\pfrom my bag!\n$"
