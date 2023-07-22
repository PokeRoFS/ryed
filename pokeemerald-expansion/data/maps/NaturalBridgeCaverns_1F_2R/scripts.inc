NaturalBridgeCaverns_1F_2R_MapScripts::
	.byte 0

EventScript_NaturalBridgeCaverns_1F_2R_Sign::
	lockall
	msgbox EventScript_NaturalBridgeCaverns_1F_2R_Sign_Text_0
	releaseall
	return


EventScript_NaturalBridgeCaverns_1F_2R_Sign_Text_0:
	.string "Where the crystals lie,\lDiancie comes to life.\n$"
