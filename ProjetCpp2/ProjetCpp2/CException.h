#pragma once
#include <cstring>

class CException
{
private:
	char* pcErreur;
public:
	CException(char* pcArgErr){
		//strcpy_s(pcErreur, sizeof(pcArgErr), pcArgErr);
		pcErreur[strlen(pcArgErr) + 1];
		strcpy_s(pcErreur, sizeof pcErreur, pcArgErr);
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
};

