BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	waitse
	playse SE_PIN
	applymovement LOCALID_BREEDER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BREEDER, Common_Movement_Delay48
	waitmovement 0
	delay 10
	return
	end

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederCheckIVs, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "For 70 years I have raised POKéMON!\n"
	.string "I am the man they revere as the\l"
	.string "legendary top POKéMON BREEDER!\p"
	.string "If you ever become as seasoned as me,\n"
	.string "you'll see the statistics of POKéMON\l"
	.string "at a glance.$"

BattleFrontier_Lounge1_Text_PokemonBreederCheckIVs::
	.string "TRAINER, the way I see it you have the\n"
	.string "same gift!\p"
	.string "When viewing a POKéMON's SUMMARY,\n"
	.string "press the A Button on the POKéMON\l"
	.string "SKILLS tab to see IVs and EVs!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "Ah, youngster! Do your POKéMON's\n"
	.string "abilities intrigue you?\p"
	.string "Here, here!\n"
	.string "Let's have a look at your POKéMON!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "He said my POKéMON is outstanding!\n"
	.string "I'm glad I raised it carefully!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "He said my POKéMON is outstanding!\n"
	.string "But I didn't do anything special\l"
	.string "raising it…$"

