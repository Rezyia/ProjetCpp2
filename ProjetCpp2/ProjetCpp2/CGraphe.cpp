#include "CGraphe.h"
#include "CException.h"

#define ERROR_SOMMET_EXIST "Le sommet existe deja"
#define ERROR_SOMMET_NOT_EXIST "Le sommet n'existe pas"

CGraphe::CGraphe()
{
	ppSomGPHSommets = (CSommet**) malloc(sizeof(CSommet*));
	uiGPHNbSommets = 0;
}

CGraphe::CGraphe(CGraphe * GPHarg)
{
}

void CGraphe::GPHAjouterSommet(CSommet * pArgSommet)
{
	try {
		if (GPHSommetExists(pArgSommet)) {
			throw new CException((char*)ERROR_SOMMET_EXIST);
		}
		//TODO : reste du code

		GPHDispSommets();

		std::cout << "test 10" << std::endl;
		CSommet** ppNewSommets = (CSommet**)malloc(sizeof(CSommet*));
		for (unsigned int uiIndice = 0; uiIndice < uiGPHNbSommets + 1; uiIndice++) { // Ajout nouvel element -> +1
			ppNewSommets[uiIndice] = (CSommet*) malloc(sizeof(CSommet));
		}

		std::cout << "test 11" << std::endl;
		for (unsigned int uiIndice = 0; uiIndice < uiGPHNbSommets; uiIndice++) {
			ppNewSommets[uiIndice] = ppSomGPHSommets[uiIndice];
		}

		std::cout << "test 12" << std::endl;
		ppNewSommets[uiGPHNbSommets + 1] = pArgSommet;

		std::cout << "test 13" << std::endl;
		ppSomGPHSommets = ppNewSommets;
		uiGPHNbSommets++;
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur();
	}
}

void CGraphe::GPHSupprimerSommet(CSommet * pArgSommet)
{
	try {
		if (!GPHSommetExists(pArgSommet)) {
			throw new CException((char*)ERROR_SOMMET_NOT_EXIST);
		}
		//TODO : reste du code
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur();
	}
}

bool CGraphe::GPHSommetExists(CSommet * pArgSommet)
{
	return false;
}

void CGraphe::GPHAfficher()
{
}



void CGraphe::GPHFreeSommets() {
	for (unsigned int uiIndice = 0; uiIndice < uiGPHNbSommets; uiIndice++) {
		free(ppSomGPHSommets[uiIndice]);
	}
}

void CGraphe::GPHDispSommets() {
	std::cout << "Sommets : " << std::endl;
	for (unsigned int uiIndice = 0; uiIndice < uiGPHNbSommets; uiIndice++) {
		std::cout << " - Sommet : " << ppSomGPHSommets[uiIndice]->SOMGetNumero() << std::endl;
	}
}