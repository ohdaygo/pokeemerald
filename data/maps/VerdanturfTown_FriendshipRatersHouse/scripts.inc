VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	goto_if_set FLAG_LIGHT_BALL, VerdanturfTown_FriendshipRatersHouse_EventScript_PikachuDone
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_PikachuChecking, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_PikachuUnimpressed
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_PikachuUnimpressed
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_PikachuUnimpressed
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_PikachuUnimpressed
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_PikachuReassured
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_PikachuReassured
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_PikachuReassured
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_PikachuDone::
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_PikachuUnimpressed::
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_PikachuUnimpressed, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_PikachuReassured::
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_PikachuReassured, MSGBOX_DEFAULT
	giveitem ITEM_LIGHT_BALL, 1
	setflag FLAG_LIGHT_BALL
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Let me see your POKéMON.\n"
	.string "I'll check to see how much it likes you.\p"
	.string "Oh.\n"
	.string "Your POKéMON…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "It adores you.\n"
	.string "It can't possibly love you any more.\l"
	.string "I even feel happy seeing it.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "It seems to be very happy.\n"
	.string "It obviously likes you a whole lot.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "It likes you quite a lot.\n"
	.string "It seems to want to be babied a little.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "It's getting used to you.\n"
	.string "It seems to believe in you.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "It's not very used to you yet.\n"
	.string "It neither loves nor hates you.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "It's very wary.\n"
	.string "It has scary viciousness in its eyes.\l"
	.string "It doesn't like you much at all.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "This is a little hard for me to say…\p"
	.string "Your POKéMON simply detests you.\n"
	.string "Doesn't that make you uncomfortable?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pika pika!$"

VerdanturfTown_FriendshipRatersHouse_Text_PikachuChecking:
	.string "PIKACHU: …?\p"
	.string "PIKACHU is evaluating your POKéMON…$"

VerdanturfTown_FriendshipRatersHouse_Text_PikachuUnimpressed:
	.string "PIKACHU: Pika…\p"
	.string "PIKACHU isn't impressed.$"

VerdanturfTown_FriendshipRatersHouse_Text_PikachuReassured:
	.string "PIKACHU: Pika pii, pika!\p"
	.string "PIKACHU is reassured by the bond of\n"
	.string "you and your POKéMON!$"

