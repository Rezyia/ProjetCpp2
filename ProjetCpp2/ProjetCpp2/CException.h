#pragma once
#include <cstring>
#include <stdlib.h>

class CException
{
private:
	char* pcErreur;
public:
	CException(char* pcArgErr){
		//strcpy_s(pcErreur, sizeof(pcArgErr), pcArgErr);
		EXCCopyString(pcArgErr);
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

