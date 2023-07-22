Ancient_City_B2F_MapScripts::
	.byte 0

EventScript_Ancient_City_B2F_Sign::
	lockall
	playmoncry SPECIES_ARCEUS, CRY_MODE_NORMAL
	waitmoncry
	msgbox EventScript_Ancient_City_B2F_Sign_Text_0
	msgbox EventScript_Ancient_City_B2F_Sign_Text_1
	msgbox EventScript_Ancient_City_B2F_Sign_Text_2
	msgbox EventScript_Ancient_City_B2F_Sign_Text_3
	msgbox EventScript_Ancient_City_B2F_Sign_Text_4
	msgbox EventScript_Ancient_City_B2F_Sign_Text_5
	fadescreen FADE_TO_BLACK
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 2, 15
	fadescreen FADE_FROM_BLACK
	setflag SPAWNED_POKEMON
	releaseall
	end


EventScript_Ancient_City_B2F_Sign_Text_0:
	.string "Ryan... It seems you have\lfound the stone to evolve creatures\p$"

EventScript_Ancient_City_B2F_Sign_Text_1:
	.string "from a distant land.\n$"

EventScript_Ancient_City_B2F_Sign_Text_2:
	.string "However, by securing this stone\lit is your destiny to grow\p$"

EventScript_Ancient_City_B2F_Sign_Text_3:
	.string "with POKéMON.\n$"

EventScript_Ancient_City_B2F_Sign_Text_4:
	.string "I see many challenges ahead of\lyou.\n$"

EventScript_Ancient_City_B2F_Sign_Text_5:
	.string "Good luck!\n$"
