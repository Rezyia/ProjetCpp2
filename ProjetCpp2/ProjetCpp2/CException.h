#pragma once
#include <cstring>
#include <stdlib.h>

#define __STDC_WANT_LIB_EXT1__ 1

class CException
{
private:
	char* pcErreur;
public:
	CException(char* pcArgErr){
		//strcpy_s(pcErreur, sizeof(pcArgErr), pcArgErr);
<<<<<<< HEAD
		//strcpy_s(pcErreur, sizeof(pcErreur), pcArgErr);
		EXCCopyString(pcArgErr);
=======
		pcErreur[strlen(pcArgErr) + 1];
		strcpy_s(pcErreur, sizeof(pcErreur), pcArgErr);
>>>>>>> 9d58b6f336a8758ca703177034fd43e90847ae78
	}

	CException(CException* EXCcopie) {
		strcpy_s(pcErreur, sizeof(EXCcopie->EXCLireErreur()), EXCcopie->EXCLireErreur());
	}

	char* EXCLireErreur() {
		return pcErreur;
	}

	void EXCModifierErreur(char* pcArgErr) {
		strcpy_s(pcErreur, sizeof(pcArgErr), pcArgErr);
	}

	void EXCCopyString(char* pcArg) {
		pcErreur = (char*)malloc(sizeof(char) * (strlen(pcArg) + 1));

		for (unsigned int uiCopy = 0; uiCopy < strlen(pcArg); uiCopy++) {
			pcErreur[uiCopy] = pcArg[uiCopy];
		}

		pcErreur[strlen(pcArg) + 1] = '\0';
	}
};

