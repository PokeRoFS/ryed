

LittlerootTown_SiblingRoom2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_SiblingRoom2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_SiblingRoom2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, SET_CURR_ENVIRONMENT
	.2byte 0


SET_CURR_ENVIRONMENT::
	goto_if_unset CHECKED_TIME, SET_CURR_ENVIRONMENT_1
	setvar VAR_TEMP_0, 1
	return

SET_CURR_ENVIRONMENT_1:
	goto Dreaming
	return


CHECKING_TIME::
	msgbox CHECKING_TIME_Text_0
	goto_if_unset CHECKED_TIME, CHECKING_TIME_2
CHECKING_TIME_1:
	setvar VAR_TEMP_0, 1
	releaseall
	end

CHECKING_TIME_2:
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setflag FLAG_SET_WALL_CLOCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	setflag CHECKED_TIME
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	goto CHECKING_TIME_1


Dreaming::
	lockall
	goto_if_unset CHECKED_TIME, Dreaming_2
Dreaming_1:
	end

Dreaming_2:
	msgbox Dreaming_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, LOOK_UP
	waitmovement 0
	goto CHECKING_TIME
	goto Dreaming_1


LOOK_UP:
	face_up
	step_end

CHECKING_TIME_Text_0:
	.string "Oh wow it's already 5:00\l Time to go!\pGotta take the trash cans out...\n$"

Dreaming_Text_0:
	.string "I must've fallen asleep while\lworking...\pI should check the time on my computer!\n$"
