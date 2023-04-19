LittlerootTown_SiblingRoom2_MapScripts::
	.byte 0

CHECKING_TIME::
	lockall
	msgbox CHECKING_TIME_Text_0
	msgbox CHECKING_TIME_Text_1
	goto_if_unset CHECKED_TIME, CHECKING_TIME_2
CHECKING_TIME_1:
	releaseall
	return

CHECKING_TIME_2:
	finditem ITEM_JOLTEONITE
	finditem ITEM_MEGA_RING
	finditem ITEM_THUNDER_STONE
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
	releaseall
	return

Dreaming_2:
	msgbox Dreaming_Text_0
	msgbox Dreaming_Text_1
	applymovement OBJ_EVENT_ID_PLAYER, MOVE_PLAYER
	waitmovement 0
	goto Dreaming_1


MOVE_PLAYER:
	walk_left
	step_end

CHECKING_TIME_Text_0:
	.string "Oh wow it's already 5:00\p Time to go!$"

CHECKING_TIME_Text_1:
	.string "Can't forget my lucky items!\n$"

Dreaming_Text_0:
	.string "I must've fallen asleep while\p working...\n$"

Dreaming_Text_1:
	.string "I should check the time on my computer!\n$"
