.set LOCALID_RIVAL, 2
DreamWorld1_MapScripts::
	.byte 0

InitContinued_Confusion::
	lockall
	msgbox InitContinued_Confusion_Text_0
	setvar VAR_TEMP_0, 1
	releaseall
	return


InitConfused_Ball::
	lockall
	msgbox InitConfused_Ball_Text_0
	call Rival_Movement
	return


Rival_Surprised::
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	return


Rival_Movement::
	call Rival_Surprised
	waitmovement 0
	call Hide_Ball
	setflag FLAG_HIDE_DREAM_POKEBALL
	applymovement LOCALID_RIVAL, Rival_Movement_Data1
	waitmovement 0
	msgbox Rival_Movement_Text_0
	applymovement LOCALID_RIVAL, Rival_Movement_Data2
	waitmovement 0
	removeobject 2
	call Final_Confusion
	return


Hide_Ball::
	removeobject 1
	return


Rival_Movement_Data1:
	walk_left
	step_end

Rival_Movement_Data2:
	walk_right
	step_end

Final_Confusion::
	msgbox Final_Confusion_Text_0
	setdynamicwarp MAP_LITTLEROOT_TOWN_SIBLING_ROOM2, 0, 2
	releaseall
	return


InitContinued_Confusion_Text_0:
	.string "Endless hallways... What's the point?$"

InitConfused_Ball_Text_0:
	.string "A pokeball?\lThis is cool I wish they were real...\n$"

Rival_Movement_Text_0:
	.string "{PLAYER}! Sorry I left my pokeball out!\n$"

Final_Confusion_Text_0:
	.string "What the fuck?\lWhen did Sheyenne get a pokeball?\n$"
