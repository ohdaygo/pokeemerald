MeteorFalls_StevensCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MeteorFalls_StevensCave_OnTransition
	.byte 0

MeteorFalls_StevensCave_OnTransition::
	call_if_set FLAG_DEFEATED_METEOR_FALLS_LEAF, MeteorFalls_StevensCave_EventScript_HideLeaf
	end

MeteorFalls_StevensCave_EventScript_HideLeaf::
	removeobject LOCALID_METEOR_FALLS_LEAF
	end

MeteorFalls_StevensCave_EventScript_Leaf::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_LEAF, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_LEAF, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_LEAF, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_LEAF, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_DialogueStart, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEAF_SUPERBOSS, MeteorFalls_StevensCave_Text_LeafDefeat
	msgbox MeteorFalls_StevensCave_Text_DialogueEnd, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_LEAF
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_METEOR_FALLS_LEAF
	fadescreen FADE_FROM_BLACK
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_LEAF, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_DialogueEnd, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_DialogueStart:
	.string "………………\n"
	.string "………………$"

MeteorFalls_StevensCave_Text_LeafDefeat:
	.string "…!$"

MeteorFalls_StevensCave_Text_DialogueEnd:
	.string "………………\n"
	.string "………………$"
