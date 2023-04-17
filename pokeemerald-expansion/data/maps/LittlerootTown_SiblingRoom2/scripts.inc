LittlerootTown_SiblingRoom2_MapScripts::
	.byte 0

CHECKING_TIME::
	lockall
	msgbox CHECKING_TIME_Text_0
	setvar VAR_TEMP_0, 1
	releaseall
	return


Dreaming::
	lockall
	setvar VAR_TEMP_0, 0
	msgbox Dreaming_Text_0
	msgbox Dreaming_Text_1
	compare VAR_TEMP_0, 1
	goto_if_lt Dreaming_2
Dreaming_1:
	releaseall
	return

Dreaming_2:
	applymovement OBJ_EVENT_ID_PLAYER, MOVE_PLAYER
	waitmovement 0
	goto Dreaming_1


MOVE_PLAYER:
	walk_down
	step_end

CHECKING_TIME_Text_0:
	.string "Oh wow it's already 5:00\p Time to go!$"

Dreaming_Text_0:
	.string "I must've fallen asleep while\p working...\n$"

Dreaming_Text_1:
	.string "I should check the time on my computer!\n$"
