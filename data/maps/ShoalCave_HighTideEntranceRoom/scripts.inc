ShoalCave_HighTideEntranceRoom_MapScripts::
	.byte 0

ShoalCave_HighTideEntranceRoom_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, ShoalCave_HighTideEntranceRoom_EventScript_ReceivedEgg
	msgbox ShoalCave_HighTideEntranceRoom_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShoalCave_HighTideEntranceRoom_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, ShoalCave_HighTideEntranceRoom_EventScript_NoRoomForEgg
	msgbox ShoalCave_HighTideEntranceRoom_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message ShoalCave_HighTideEntranceRoom_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_SNOVER
	release
	end

ShoalCave_HighTideEntranceRoom_EventScript_ReceivedEgg::
	msgbox ShoalCave_HighTideEntranceRoom_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

ShoalCave_HighTideEntranceRoom_EventScript_NoRoomForEgg::
	msgbox ShoalCave_HighTideEntranceRoom_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

ShoalCave_HighTideEntranceRoom_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

ShoalCave_HighTideEntranceRoom_Text_HaveEggWillYouTakeIt:
	.string "I have here an EGG.\p"
	.string "I'd hoped  it'd of hatched by the\n"
	.string "time i got to this region.\l"
	.string "But that doesn't seem to be the case…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with POKéMON and\l"
	.string "carried about.\p"
	.string "You are a TRAINER, yes?\n"
	.string "And your POKéMON are taken care of?\p"
	.string "So, how about it?\n"
	.string "Will you take this EGG to hatch?$"

ShoalCave_HighTideEntranceRoom_Text_HopeYoullWalkPlentyWithEgg:
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here EGG! I think only Glacia\p"
	.string "has the species. You'll be the talk\n"
	.string "of the town! Take care of it.$"

ShoalCave_HighTideEntranceRoom_Text_ReceivedTheEgg:
	.string "{PLAYER} received the EGG.$"

ShoalCave_HighTideEntranceRoom_Text_NoRoomForThisEgg:
	.string "Oh? You've too many POKéMON.\n"
	.string "There's no room for this EGG…$"

ShoalCave_HighTideEntranceRoom_Text_AsYouWishThen:
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this EGG, I will be here.$"

ShoalCave_HighTideEntranceRoom_Text_EverySoOftenEggFoundAtDayCare:
	.string "Every so often, an EGG will be found at\n"
	.string "the POKéMON DAY CARE.\p"
	.string "That's what people say. I just don't\n"
	.string "I just dont think they understand\p"
	.string "basic biology... This region is strang.$"


