AncientCityBase_MapScripts::
	.byte 0

SUMMON_POKEMON::
	lockall
	goto_if_unset SPAWNED_POKEMON, SUMMON_POKEMON_2
SUMMON_POKEMON_1:
	releaseall
	return

SUMMON_POKEMON_2:
	msgbox SUMMON_POKEMON_Text_0
	msgbox SUMMON_POKEMON_Text_1
	msgbox SUMMON_POKEMON_Text_2
	msgbox SUMMON_POKEMON_Text_3
	msgbox SUMMON_POKEMON_Text_4
	fadescreen FADE_TO_BLACK
	playmoncry SPECIES_ARCEUS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag SPAWNED_POKEMON
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 2, 14
	fadescreen FADE_FROM_BLACK
	goto SUMMON_POKEMON_1


SUMMON_POKEMON_Text_0:
	.string "Finally, I have been awakened...\n$"

SUMMON_POKEMON_Text_1:
	.string "It seems that you are the one\p who was chosen to change the world.\n$"

SUMMON_POKEMON_Text_2:
	.string "With the introduction of pokemon,\p the world will change.\n$"

SUMMON_POKEMON_Text_3:
	.string "However, I know that people\p will abuse the power of pokemon.\n$"

SUMMON_POKEMON_Text_4:
	.string "You must be the one to stop these people.\pGood luck.\n$"
