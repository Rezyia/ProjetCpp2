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

CGraphe::~CGraphe() {
	for (unsigned int uiDealloc = 0; uiDealloc < uiGPHNbSommets; uiDealloc++) {

	}
}

void CGraphe::GPHAjouterArc(CSommet* pArgSommetSource, CSommet* pArgSommetDestination) {
	pArgSommetSource->SOMAjouterPartant(pArgSommetSource);
	pArgSommetDestination->SOMAjouterArrivant(pArgSommetDestination);
}

void CGraphe::GPHAjouterSommet(CSommet * pArgSommet)
{
	try {
		if (GPHSommetExists(pArgSommet)) {
			throw new CException((char*)ERROR_SOMMET_EXIST);
		}

		//GPHDispSommets();

		CSommet** ppNewSommets = (CSommet**) malloc(sizeof(CSommet*) * uiGPHNbSommets + 1);
		for (unsigned int uiIndice = 0; uiIndice < uiGPHNbSommets + 1; uiIndice++) { // Ajout nouvel element -> +1
			ppNewSommets[uiIndice] = (CSommet*) malloc(sizeof(CSommet));
		}

		if (ppSomGPHSommets != NULL) {
			for (unsigned int uiIndice = 0; uiIndice < uiGPHNbSommets; uiIndice++) {
				ppNewSommets[uiIndice] = ppSomGPHSommets[uiIndice];
			}
		}
		

		ppNewSommets[uiGPHNbSommets] = pArgSommet;

		//GPHFreeSommets();
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