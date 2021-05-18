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
	ppArcSomArrivants = NULL;
	ppArcSomPartants = NULL;
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


int CSommet::SOMIsArcPartantExist(CSommet * pArgDestination)
{
	bool bTrouve = false;
	unsigned int uiBoucle = 0;
	while (!bTrouve && uiBoucle != uiSOMNbPartants) {
		if (ppArcSomPartants[uiBoucle]->ARCGetNumero() == pArgDestination->SOMGetNumero()) {
			bTrouve = true;
		}
		else {
			uiBoucle++;
		}
	}
	if (!bTrouve) {
		return -1;
	}
	return uiBoucle;
}

int CSommet::SOMIsArcArrivantExist(CSommet * pArgDepart)
{
	bool bTrouve = false;
	unsigned int uiBoucle = 0;
	while (!bTrouve && uiBoucle != uiSOMNbArrivants) {
		if (ppArcSomArrivants[uiBoucle]->ARCGetNumero() == pArgDepart->SOMGetNumero()) {
			bTrouve = true;
		}
		else {
			uiBoucle++;
		}
	}
	if (!bTrouve) {
		return -1;
	}
	return uiBoucle;
}

void CSommet::SOMAjouterArc(CSommet* pArgDestination) {
	std::cout << "testAjoutArc - en cours..." << std::endl;

	try {
		if (SOMIsArcPartantExist(pArgDestination)!=-1) {
			throw new CException((char*)ERROR_ARC_EXIST);
		}

		//TODO : reste du code
		//pArgDestination->uiSOMNbArrivants++;
		pArgDestination->SOMIncrementNbArrivants();

		//realloc(pArgDestination->ppArcSomArrivants, pArgDestination->uiSOMNbArrivants);
		realloc(pArgDestination->SOMGetArrivants(), pArgDestination->SOMGetNbArrivants() * sizeof(CArc*));
		//pArgDestination->ppArcSomArrivants[pArgDestination->uiSOMNbArrivants] = new CArc(uiSOMNumero);
		pArgDestination->SOMSetArrivant(pArgDestination->SOMGetNbArrivants(), new CArc(uiSOMNumero));

		uiSOMNbPartants++;
		realloc(ppArcSomPartants, uiSOMNbPartants * sizeof(CArc*));
		ppArcSomPartants[uiSOMNbPartants] = new CArc(pArgDestination->uiSOMNumero);
		std::cout << "testAjoutArc - fait" << std::endl;
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur();
	}
}

void CSommet::SOMSupprimerArcPartant(CSommet * pArgDestination)
{
	std::cout << "testSupprArc - en cours..." << std::endl;
	try {
		int iPosArc = SOMIsArcPartantExist(pArgDestination);
		if (iPosArc==-1) {
			throw new CException((char*)ERROR_ARC_NOT_EXIST);
		}
		//Suppresion dans ppArcSomPartant
		unsigned int uiBoucle;
		for (uiBoucle = iPosArc; uiBoucle < uiSOMNbPartants-1; uiBoucle++) {
			ppArcSomPartants[uiBoucle] = ppArcSomPartants[uiBoucle + 1];
		}
		uiSOMNbPartants--;
		realloc(ppArcSomPartants, uiSOMNbPartants*sizeof(CArc*));

		std::cout << "testSupprArc - fait" << std::endl;
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur() << std::endl;
	}
}

void CSommet::SOMSupprimerArcArrivant(CSommet * pArgDepart)
{
	std::cout << "testSupprArc - en cours..." << std::endl;
	try {
		int iPosArc = SOMIsArcArrivantExist(pArgDepart);
		if (iPosArc == -1) {
			throw new CException((char*)ERROR_ARC_NOT_EXIST);
		}
		//Suppresion dans ppArcSomPartant
		unsigned int uiBoucle;
		for (uiBoucle = iPosArc; uiBoucle < uiSOMNbArrivants - 1; uiBoucle++) {
			ppArcSomArrivants[uiBoucle] = ppArcSomArrivants[uiBoucle + 1];
		}
		uiSOMNbArrivants--;
		realloc(ppArcSomArrivants, uiSOMNbArrivants * sizeof(CArc*));

		std::cout << "testSupprArc - fait" << std::endl;
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur() << std::endl;
	}
}


