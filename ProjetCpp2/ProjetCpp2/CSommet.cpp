#include "CSommet.h"
#include "CException.h"

#define ERROR_ARC_EXIST "L'arc existe deja"
#define ERROR_ARC_NOT_EXIST "L'arc n'existe pas"

CSommet::CSommet() {
	uiSOMNumero = -1;
	uiSOMNbArrivants = 0;
	uiSOMNbPartants = 0;
	ppArcSomArrivants = (CArc**) malloc(sizeof(CArc*) * 0);
	ppArcSomPartants = (CArc**)malloc(sizeof(CArc*) * 0);
}


CSommet::CSommet(unsigned int uiArg){
	uiSOMNumero = uiArg;
	uiSOMNbArrivants = 0;
	uiSOMNbPartants = 0;
	ppArcSomArrivants = (CArc**)malloc(sizeof(CArc*) * 0);
	ppArcSomPartants = (CArc**)malloc(sizeof(CArc*) * 0);
	std::cout << "test 20" << std::endl;
	std::cout << SOMGetNumero();
}


CSommet::CSommet(CSommet* SOMarg){
	uiSOMNumero = SOMarg->SOMGetNumero();
	uiSOMNbPartants = SOMarg->SOMGetNbPartants();
	uiSOMNbArrivants = SOMarg->SOMGetNbArrivants();

	// Allocation des tableaux
	ppArcSomArrivants = (CArc**)malloc(sizeof(CArc*) * uiSOMNbArrivants);
	ppArcSomPartants = (CArc**)malloc(sizeof(CArc*) * uiSOMNbPartants);

	// Recopie tableau arrivants
	for (unsigned int uiBoucleCopie = 0; uiBoucleCopie < uiSOMNbArrivants; uiBoucleCopie++) {
		// ppArcSomArrivants[uiBoucleCopie] = ... (à compléter)
	}

	// Recopie tableau partants
	for (unsigned int uiBoucleCopie = 0; uiBoucleCopie < uiSOMNbPartants; uiBoucleCopie++) {
		// ppArcSomPartants[uiBoucleCopie] = ... (à compléter)
	}
}


CSommet::~CSommet(){
	 for (unsigned int uiBoucleDel = 0; uiBoucleDel < uiSOMNbArrivants; uiBoucleDel++) {
		 delete ppArcSomArrivants[uiBoucleDel];
	 }
	 for (unsigned int uiBoucleDel = 0; uiBoucleDel < uiSOMNbPartants; uiBoucleDel++) {
		 delete ppArcSomPartants[uiBoucleDel];
	 }
	 free(ppArcSomArrivants);
	 free(ppArcSomPartants);
}


CArc** CSommet::SOMCopieTabArcs(CArc** ppArcArg, unsigned int uiArgNbNew, unsigned int uiArgNbOld) {
	CArc** newTab = (CArc**) malloc(sizeof(CArc*) * uiArgNbNew);

	unsigned int uiMinNb = uiArgNbNew;
	if (uiMinNb > uiArgNbOld) uiMinNb = uiArgNbOld;

	// On suppose qu'il n'y aura pas de copie de dimensions plus faible
	for (unsigned int uiBoucleCopie = 0; uiBoucleCopie < uiMinNb; uiBoucleCopie++) {
		newTab[uiBoucleCopie] = ppArcArg[uiBoucleCopie];
	}

	return newTab;
}


bool CSommet::SOMIsArcExist(CSommet * pArgDestination)
{
	//TODO : le code
	return false;
}


void CSommet::SOMAjouterArc(CSommet* pArgDestination) {
	std::cout << "testAjoutArc - en cours..." << std::endl;

	try {
		if (SOMIsArcExist(pArgDestination)) {
			throw new CException((char*)ERROR_ARC_EXIST);
		}
		//TODO : reste du code
		pArgDestination->uiSOMNbArrivants++;
		realloc(pArgDestination->ppArcSomArrivants, pArgDestination->uiSOMNbArrivants);
		pArgDestination->ppArcSomArrivants[uiSOMNbArrivants] = new CArc(this->uiSOMNumero);

		uiSOMNbPartants++;
		realloc(ppArcSomPartants, uiSOMNbPartants);
		ppArcSomPartants[uiSOMNbPartants] = new CArc(pArgDestination->uiSOMNumero);
		std::cout << "testAjoutArc - fait" << std::endl;
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur();
	}
}

void CSommet::SOMSupprimerArc(CSommet * pArgDestination)
{
	try {
		if (!SOMIsArcExist(pArgDestination)) {
			throw new CException((char*)ERROR_ARC_NOT_EXIST);
		}
		//TODO : reste du code
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur();
	}
}


