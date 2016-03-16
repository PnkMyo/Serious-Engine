/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

#ifndef SE_INCL_MENU_STUFF_H
#define SE_INCL_MENU_STUFF_H
#ifdef PRAGMA_ONCE
  #pragma once
#endif

#include "FileInfo.h"

#define TRIGGER_MG(mg, y, up, down, text, astr) \
	mg.mg_pmgUp = &up; \
	mg.mg_pmgDown = &down; \
	mg.mg_boxOnScreen = BoxMediumRow(y); \
	gm_lhGadgets.AddTail(mg.mg_lnNode); \
	mg.mg_astrTexts = astr; \
	mg.mg_ctTexts = sizeof(astr) / sizeof(astr[0]); \
	mg.mg_iSelected = 0; \
	mg.mg_strLabel = text; \
	mg.mg_strValue = astr[0];


extern INDEX ctGameTypeRadioTexts;

extern CTString astrNoYes[2];
extern CTString astrWeapon[4];
extern CTString astrComputerInvoke[2];
extern CTString astrCrosshair[8];
extern CTString astrMaxPlayersRadioTexts[15];
extern CTString astrGameTypeRadioTexts[20];
extern CTString astrDifficultyRadioTexts[6];
extern CTString astrSplitScreenRadioTexts[4];
extern CTString astrDisplayPrefsRadioTexts[4];
extern CTString astrDisplayAPIRadioTexts[2];
extern CTString astrBitsPerPixelRadioTexts[3];
extern CTString astrFrequencyRadioTexts[4];
extern CTString astrSoundAPIRadioTexts[3];

ULONG GetSpawnFlagsForGameType(INDEX iGameType);
BOOL IsMenuEnabled(const CTString &strMenuName);
void InitGameTypes(void);

int qsort_CompareFileInfos_NameUp(const void *elem1, const void *elem2);
int qsort_CompareFileInfos_NameDn(const void *elem1, const void *elem2);
int qsort_CompareFileInfos_FileUp(const void *elem1, const void *elem2);
int qsort_CompareFileInfos_FileDn(const void *elem1, const void *elem2);

#endif  /* include-once check. */