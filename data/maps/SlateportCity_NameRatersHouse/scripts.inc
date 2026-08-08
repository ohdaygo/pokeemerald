SlateportCity_NameRatersHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_NameRatersHouse_OnTransition
	.byte 0

SlateportCity_NameRatersHouse_OnTransition::
	call_if_set FLAG_HIDE_DRAKE, SlateportCity_NameRatersHouse_EventScript_HideDrake
	end

SlateportCity_NameRatersHouse_EventScript_HideDrake::
	removeobject LOCALID_SLATEPORT_DRAKE
	end

SlateportCity_NameRatersHouse_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_NameRatersHouse_EventScript_DrakeMetStern
	msgbox SlateportCity_NameRatersHouse_Text_Drake, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_DrakeMetStern::
	goto_if_set FLAG_DRAGON_FANG, SlateportCity_NameRatersHouse_EventScript_DrakeSawBagon
	msgbox SlateportCity_NameRatersHouse_Text_DrakeMetStern, MSGBOX_DEFAULT	
	closemessage
	applymovement LOCALID_SLATEPORT_DRAKE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
 	delay 15
	applymovement LOCALID_SLATEPORT_DRAKE, Common_Movement_FacePlayer
	waitmovement 0
	delay 15
	showmonpic SPECIES_BAGON, 10, 3
	waitse
	playmoncry SPECIES_BAGON, CRY_MODE_NORMAL
	waitmoncry
	waitbuttonpress
	hidemonpic
	setseenmon SPECIES_BAGON
	msgbox SlateportCity_NameRatersHouse_Text_DrakeGiveFang, MSGBOX_DEFAULT
	giveitem ITEM_DRAGON_FANG
	setflag FLAG_DRAGON_FANG
	goto SlateportCity_NameRatersHouse_EventScript_DrakeSawBagon

SlateportCity_NameRatersHouse_EventScript_DrakeSawBagon::
	msgbox SlateportCity_NameRatersHouse_Text_DrakeSawBagon, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_Drake:
	.string "Ahoy, TRAINER.\p"
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "Ah, ol' BRINEY brought you to find\n"
	.string "STERN!\p"
	.string "{COLOR GREEN}You'll find him by his SHIPYARD or the\n"
	.string "MUSEUM{COLOR DARK_GRAY}.\p"
	.string "After your errand, TRAINER, visit me\n"
	.string "again.\p"
	.string "Sally forth!$"
	
SlateportCity_NameRatersHouse_Text_DrakeMetStern:
	.string "A long, long time ago, POKéMON saved\n"
	.string "my life.\p"
	.string "I fell overboard and was about to drown\n"
	.string "when a wild DRAGON-type rescued me.\p"
	.string "I felt I needed to repay that majestic\n"
	.string "POKéMON in some way, so I vowed to\l"
	.string "become a TRAINER.\p"
	.string "Everything that I am as a TRAINER I've\n"
	.string "poured into my SALAMENCE.\p"
	.string "SALAMENCE, a POKéMON, hoped and wished\n"
	.string "he could fly for a long time until he\l"
	.string "finally got his wings.\p"
	.string "SALAMENCE is living proof that you can\n"
	.string "reach your goals if you keep believing\l"
	.string "in yourself.\p"
	.string "Ol' SALAMENCE and I have been training\n"
	.string "together since he was just a BAGON!\p"
	.string "Here, I'll put the entry for BAGON in\n"
	.string "your POKéDEX.$"

SlateportCity_NameRatersHouse_Text_DrakeGiveFang:
	.string "Like a ship that stays the course\n"
	.string "through a storm, no matter what\l"
	.string "difficulties I may encounter, I'll\l"
	.string	"continue on the path that I've chosen.\p"
	.string "It's up to us adults to serve as a\n"
	.string "lighthouse, guiding you as you make\l"
	.string "your way.$"

SlateportCity_NameRatersHouse_Text_DrakeSawBagon:
	.string "{PLAYER}{KUN}, I want you to achieve a\n"
	.string "goal similar to my own.\p"
	.string "Become the greatest TRAINER of them\n"
	.string "all.\p"
	.string "Keep believing in yourself and reach\n"
	.string "your goals.\p"
	.string "Maybe then, we may do battle!$"
