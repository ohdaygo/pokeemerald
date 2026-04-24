Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_StartBirchRescue::
	lockall
	playbgm MUS_HELP, TRUE
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_ROUTE101_BIRCH, 0, 15
	setobjectxy LOCALID_ROUTE101_ZIGZAGOON, 0, 16
	applymovement LOCALID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunAway1
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	waitmovement 0
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_ROUTE101_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth:
	walk_up
	step_end

Route101_Movement_PreventExitWest:
	walk_right
	step_end

Route101_Movement_PreventExitNorth:
	walk_down
	step_end

Route101_Movement_ZigzagoonChaseInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_ZigzagoonChase1:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_ZigzagoonFaceBirch:
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	step_end

Route101_Movement_BirchRunInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFaceZigzagoon:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1:
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2:
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_GiftStarter::
	lock
	faceplayer
	goto_if_set FLAG_STARTERS_CLAIMED, Route101_EventScript_GiftStarterNoMore
	msgbox Route101_Text_GiftStarter, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, Route101_EventScript_GiftStarterNo
	case FRIENDSHIP_1_TO_49, Route101_EventScript_GiftStarterNo
	case FRIENDSHIP_50_TO_99, Route101_EventScript_GiftStarterNo
	case FRIENDSHIP_100_TO_149, Route101_EventScript_GiftStarterNo
	case FRIENDSHIP_150_TO_199, Route101_EventScript_GiftStarterNo
	case FRIENDSHIP_200_TO_254, Route101_EventScript_GiftStarterCheck
	case FRIENDSHIP_MAX, Route101_EventScript_GiftStarterCheck
	release
	end

Route101_EventScript_GiftStarterCheck::
	switch VAR_STARTER_MON
	case 0, Route101_EventScript_StartedWTreecko
	case 1, Route101_EventScript_StartedWTorchic
	case 2, Route101_EventScript_StartedWMudkip
	end

Route101_EventScript_GiftStarterNo::
	msgbox Route101_Text_GiftStarterNo, MSGBOX_DEFAULT
	release
	end

Route101_EventScript_GiftStarterNoMore::
	msgbox Route101_Text_GiftStarterNoMore, MSGBOX_DEFAULT
	release
	end

Route101_EventScript_StartedWMudkip::
	goto_if_set FLAG_ONE_CLAIMED, Route101_EventScript_Starter4	
	setflag FLAG_ONE_CLAIMED
	msgbox Route101_Text_GiftStarterYes, MSGBOX_DEFAULT		
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORCHIC
	givemon SPECIES_TORCHIC, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route101_EventScript_ReceiveStarter
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route101_EventScript_ReceiveStarterPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route101_EventScript_StartedWTreecko::
	goto_if_set FLAG_ONE_CLAIMED, Route101_EventScript_Starter5	
	setflag FLAG_ONE_CLAIMED
	msgbox Route101_Text_GiftStarterYes, MSGBOX_DEFAULT		
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MUDKIP
	givemon SPECIES_MUDKIP, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route101_EventScript_ReceiveStarter
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route101_EventScript_ReceiveStarterPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route101_EventScript_StartedWTorchic::	
	goto_if_set FLAG_ONE_CLAIMED, Route101_EventScript_Starter6	
	setflag FLAG_ONE_CLAIMED
	msgbox Route101_Text_GiftStarterYes, MSGBOX_DEFAULT		
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TREECKO
	givemon SPECIES_TREECKO, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route101_EventScript_ReceiveStarter
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route101_EventScript_ReceiveStarterPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route101_EventScript_Starter4::
	goto_if_unset FLAG_DEFEATED_PETALBURG_GYM, Route101_EventScript_GiftStarterCBL
	setflag FLAG_STARTERS_CLAIMED
	msgbox Route101_Text_GiftStarterYes, MSGBOX_DEFAULT		
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TREECKO
	givemon SPECIES_TREECKO, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route101_EventScript_ReceiveStarter
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route101_EventScript_ReceiveStarterPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route101_EventScript_Starter5::
	goto_if_unset FLAG_DEFEATED_PETALBURG_GYM, Route101_EventScript_GiftStarterCBL
	setflag FLAG_STARTERS_CLAIMED
	msgbox Route101_Text_GiftStarterYes, MSGBOX_DEFAULT		
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORCHIC
	givemon SPECIES_TORCHIC, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route101_EventScript_ReceiveStarter
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route101_EventScript_ReceiveStarterPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route101_EventScript_Starter6::
	goto_if_unset FLAG_DEFEATED_PETALBURG_GYM, Route101_EventScript_GiftStarterCBL
	setflag FLAG_STARTERS_CLAIMED
	msgbox Route101_Text_GiftStarterYes, MSGBOX_DEFAULT		
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MUDKIP
	givemon SPECIES_MUDKIP, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route101_EventScript_ReceiveStarter
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route101_EventScript_ReceiveStarterPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route101_EventScript_ReceiveStarter::
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox Route101_Text_NicknameYN, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route101_EventScript_GL
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	release
	end

Route101_EventScript_ReceiveStarterPC::
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox Route101_Text_NicknameYN, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route101_EventScript_SendStarterToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route101_EventScript_SendStarterToPC
	end

Route101_EventScript_SendStarterToPC::
	call Common_EventScript_TransferredToPC
	msgbox Route101_Text_GL, MSGBOX_DEFAULT
	release
	end

Route101_EventScript_GiftStarterCBL::
	call_if_set FLAG_STARTERS_CLAIMED, Route101_Text_GiftStarterNoMore
	msgbox Route101_Text_GiftStarterCBL, MSGBOX_DEFAULT
	release
	end

Route101_EventScript_GL::
	msgbox Route101_Text_GL, MSGBOX_DEFAULT
	release
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROUTE101_ZIGZAGOON
	setobjectxy LOCALID_PLAYER, 6, 13
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer:
	walk_right
	step_end

Route101_Text_HelpMe:
	.string "H-help me!$"

Route101_Text_PleaseHelp:
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"

Route101_Text_DontLeaveMe:
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_Text_YouSavedMe:
	.string "PROF. BIRCH: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my POKéMON LAB later, okay?$"

Route101_Text_WildPokemonInTallGrass:
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign:
	.string "ROUTE 101\n"
	.string "{UP_ARROW} OLDALE TOWN$"

Route101_Text_GiftStarter:
	.string "Hi!\p"
	.string "Remember me? I'm PROF. BIRCH'S AIDE!\p"
	.string "If you're a trustworthy trainer, I'm\n"
	.string "supposed to give you a PARTNER\l"
	.string "POKéMON.\p"
	.string "So, {PLAYER}{KUN}, allow me to check your\n"
	.string "POKéMON.$"

Route101_Text_GiftStarterYes:
	.string "Your POKéMON is very comfortable with\n"
	.string "you! Please take this PARTNER POKéMON\l"
	.string "on your journey!$"

Route101_Text_GiftStarterNo:
	.string "Your POKéMON don't seem as\n"
	.string "enthusiastic to travel with you as\l"
	.string "we'd prefer.\p"
	.string "Come back another time.$" 

Route101_Text_GiftStarterNoMore:
	.string "It seems you have all three HOENN\n"
	.string "PARTNER POKéMON.\p"
	.string "Good luck on the rest of your journey!$"
	
Route101_Text_GiftStarterCBL:
	.string "{PLAYER}{KUN}, PROF. BIRCH only\n"
	.string "authorized I give you one PARTNER\l"
	.string "POKéMON.\p"
	.string "Come back later.$"

Route101_Text_GL::
	.string "Good luck on your journey!$"

Route101_Text_NicknameYN::
.string "Would you like to give this PARTNER\n"
.string "POKéMON a nickname?$"
