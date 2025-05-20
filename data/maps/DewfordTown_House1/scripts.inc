DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_DEFORWD_EVIOLITE, DewfordTown_House1_EventScript_Woman_Given_Treasure
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	giveitem ITEM_EVIOLITE
	setflag FLAG_DEFORWD_EVIOLITE
	release
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "There's a lot to be said for living on\n"
	.string "a small island like this in harmony with\l"
	.string "POKéMON and the family.\l"
	.string "The combee in the meadow are my favourite.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "I left the major port of SLATEPORT\n"
	.string "CITY when I married my husband here.\p"
	.string "Life goes by slowly on this little\n"
	.string "island. But being surrounded by the\l"
	.string "beautiful sea--that's happiness, too.\p"
	.string "Here, take this treasure i found\n"
	.string "after my first few years of being here.\p"
	.string "I hope it brings the same fortune\n"
	.string "I've found.$"

DewfordTown_House1_EventScript_Woman_Given_Treasure:
	msgbox DewfordTown_House1_EventScript_Woman_Given_Treasure_Text MSGBOX_DEFAULT
	release
	end

DewfordTown_House1_EventScript_Woman_Given_Treasure_Text:
	.string "I left the major port of SLATEPORT\n"
	.string "CITY when I married my husband here.\p"
	.string "Life goes by slowly on this little\n"
	.string "island. But being surrounded by the\l"
	.string "beautiful sea--that's happiness, too.\p"
	.string "I hope my little treasure is bringing\n"
	.string "you happiness and good fortune.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguuh!$"

