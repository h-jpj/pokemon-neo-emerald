LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_SelfInsert::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_REMATCH_HARVEY, LilycoveCity_CoveLilyMotel_2F_EventScript_HarveyDefeated
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImHarvey, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_CoveLilyMotel_2F_EventScript_SelfInsertNo
	message LilycoveCity_CoveLilyMotel_2F_Text_SelfInsertBattle
	waitmessage
	trainerbattle_no_intro TRAINER_HARVEY, LilycoveCity_CoveLilyMotel_2F_Text_HarveyDefeat
	setflag FLAG_DAILY_REMATCH_HARVEY

LilycoveCity_CoveLilyMotel_2F_EventScript_HarveyDefeated::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ThanksAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_SelfInsertNo::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SelfInsertNo, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_SelfInsertNo:
	.string "Some other time, then?$"

LilycoveCity_CoveLilyMotel_2F_Text_ImHarvey:
	.string "Hey {PLAYER}!\p"
	.string "I'm Harvey-Jay, the creator of this\n"
	.string "mod (or ROM hack).\p"
	.string "Thanks for playing!\p"
	.string "I hope you had fun on your journey,\n"
	.string "and didn't run in to too many bugs!\p"
	.string "Now that you're the Champion, how about\n"
	.string "we have a friendly battle?\p"
	.string "Don't worry - I haven't given myself\n"
	.string "any unfair advantages!\p"
	.string "So, are you ready?$"

LilycoveCity_CoveLilyMotel_2F_Text_SelfInsertBattle:
	.string "Great! let's see what you can do!$"

LilycoveCity_CoveLilyMotel_2F_Text_HarveyDefeat:
	.string "Well done, {PLAYER}!$"

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "I'm the GAME DESIGNER.\p"
	.string "Oh, is that right?\n"
	.string "You're working on a POKéDEX?\p"
	.string "It's tough trying to complete it,\n"
	.string "but don't give up.\p"
	.string "If you do complete it, please come\n"
	.string "show me.$"

LilycoveCity_CoveLilyMotel_2F_Text_ThanksAgain:
	.string "Thanks again for playing!\p"
	.string "If you want a rematch, come back\n"
	.string "tomorrow!$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wow! That's awesome!\n"
	.string "Yep, it's totally awesome!\p"
	.string "This POKéDEX is completely filled!\n"
	.string "You really must love POKéMON!\p"
	.string "I'm so impressed!\p"
	.string "Let me give you something in\n"
	.string "recognition of your feat!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Me? You're talking to me?\n"
	.string "I'm the PROGRAMMER.\p"
	.string "I wonder what the SLOTS are\n"
	.string "like here.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
	.string "POKéMON of HOENN interesting?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "The girl TUBERS, they're cute, hey?\n"
	.string "To battle against a cute TUBER…\p"
	.string "Whoop, it's so awesome!\p"
	.string "And the TWINS! Aren't they cute?\n"
	.string "A 2-on-2 battle with TWINS…\p"
	.string "Whoop, it's unbearably fun!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "The sea breeze tickles my heart.\n"
	.string "It feels wonderful here!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "You never know when and where\n"
	.string "people will challenge you.\p"
	.string "That's why I never leave home without\n"
	.string "my GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Huh?!\n"
	.string "Oh, sorry, sorry! I was snoozing!\p"
	.string "I came to check out this POKéMON\n"
	.string "CONTEST thing.\p"
	.string "I have to admit, it does look quite\n"
	.string "entertaining, but…\p"
	.string "Consider me a purist--I prefer\n"
	.string "battles and tough TRAINERS.\p"
	.string "But that's just me.\p"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
	.string "the whole works!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: I think it does take strategy\n"
	.string "to win a CONTEST.\p"
	.string "Devising CONTEST strategies is one way\n"
	.string "of becoming a better TRAINER, I'd say.$"

