#pragma once
#include <cstring>

class CException
{
private:
	char* pcErreur;
public:
	CException(char* pcArgErr){
		strcpy_s(pcErreur, sizeof(pcArgErr), pcArgErr);
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

