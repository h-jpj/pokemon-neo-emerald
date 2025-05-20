EventScript_UseSurf::
	checkpartycanlearnmove MOVE_SURF
	goto_if_ne VAR_RESULT, PARTY_SIZE, EventScript_UseSurfWithMon
	lockall
	msgbox gText_CantSurf, MSGBOX_DEFAULT
	goto EventScript_ReleaseUseSurf

EventScript_UseSurfWithMon::
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end
