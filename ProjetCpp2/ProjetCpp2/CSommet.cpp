#include "CSommet.h"

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

