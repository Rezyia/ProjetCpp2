#include "CSommet.h"
#include "CException.h"

#define ERROR_ARC_EXIST "L'arc existe deja"
#define ERROR_ARC_NOT_EXIST "L'arc n'existe pas"


/* Constructeur par défaut :
*/
CSommet::CSommet() {
	uiSOMNumero = -1;
	uiSOMNbArrivants = 0;
	uiSOMNbPartants = 0;
	ppArcSomArrivants = nullptr;
	ppArcSomPartants = nullptr;
}


/* Constructeur de confort :
		Entrée :
			- uiArg : Numéro du sommet
*/
CSommet::CSommet(unsigned int uiArg){
	uiSOMNumero = uiArg;
	uiSOMNbArrivants = 0;
	uiSOMNbPartants = 0;
	ppArcSomArrivants = nullptr;
	ppArcSomPartants = nullptr;
}


/* Constructeur de recopie
		Entrée :
			- SOMarg : pointeur du CSommet à recopier
*/
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


/* Destructeur
*/
CSommet::~CSommet(){
	
	 for (unsigned int uiBoucleDel = 0; uiBoucleDel < uiSOMNbArrivants; uiBoucleDel++) {
		 delete ppArcSomArrivants[uiBoucleDel];
	 }
	 for (unsigned int uiBoucleDel = 0; uiBoucleDel < uiSOMNbPartants; uiBoucleDel++) {
		 delete ppArcSomPartants[uiBoucleDel];
	 }
	 
	 free(ppArcSomArrivants);
	 free(ppArcSomPartants);
	 ppArcSomArrivants = nullptr;
	 ppArcSomPartants = nullptr;
}


/* Fonction d'affichage d'un sommet 
*/
void CSommet::SOMAfficher()
{
	std::cout << "Sommet numero " << SOMGetNumero() << ":" << std::endl;
	if (SOMGetNbPartants() == 0) {
		std::cout << "Pas d'arc partant" << std::endl;
	}
	else {
		std::cout << "Arc partant depuis ce sommet :" << std::endl;
		for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNbPartants; uiBoucle++) {
			ppArcSomPartants[uiBoucle]->ARCAfficher();
		}
	}
	
}


/* Fonction de vérification de doublons d'arc partant
		Entrée :
			- pArgDestination : Pointeur vers le CSommet de l'arc à vérifier
*/
int CSommet::SOMIsArcPartantExist(CSommet * pArgDestination)
{
	bool bTrouve = false;
	unsigned int uiBoucle = 0;
	while (!bTrouve && uiBoucle < uiSOMNbPartants) {
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


/* Fonction de vérification de doublons d'arc arrivant
		Entrée :
			- pArgDepart : Pointeur vers le CSommet de l'arc à vérifier
*/
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


/* Fonction d'ajout d'arc partant
		Entrée :
			- pArgDestination : Pointeur vers le CSommet de l'arc à ajouter
*/
void CSommet::SOMAjouterArcPartant(CSommet* pArgDestination) {
	try {
		// Si l'arc existe deja :
		if (SOMIsArcPartantExist(pArgDestination) != -1) {
			throw new CException((char*)ERROR_ARC_EXIST);
		}

		// Si ppArcSomPartants est vide (nullptr) -> malloc
		if (SOMIsEmptyPartants()) {
			ppArcSomPartants = (CArc**)malloc(sizeof(CArc*));
		}
		// Sinon -> realloc
		else {
			ppArcSomPartants = (CArc**)realloc(ppArcSomPartants, (uiSOMNbPartants + 1) * sizeof(CArc*));
		}
		ppArcSomPartants[uiSOMNbPartants] = new CArc(pArgDestination->SOMGetNumero());
		uiSOMNbPartants++;
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur() << std::endl;
	}
}


/* Fonction d'ajout d'arc arrivant
		Entrée :
			- pArgDepart : Pointeur vers le CSommet de l'arc à ajouter
*/
void CSommet::SOMAjouterArcArrivant(CSommet* pArgDepart) {
	try {
		if (SOMIsArcArrivantExist(pArgDepart) != -1) {
			throw new CException((char*)ERROR_ARC_EXIST);
		}
		if (SOMIsEmptyArrivants()) {
			ppArcSomArrivants= (CArc**)malloc(sizeof(CArc*));
		}
		else {
			ppArcSomArrivants = (CArc**)realloc(ppArcSomArrivants, (uiSOMNbArrivants + 1) * sizeof(CArc*));
		}
		ppArcSomArrivants[uiSOMNbArrivants] = new CArc(uiSOMNumero);
		uiSOMNbArrivants++;
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur() << std::endl;
	}
}


/* Fonction de suppression d'arc partant
		Entrée :
			- pArgDestination : Pointeur vers le CSommet de l'arc à supprimer
*/
void CSommet::SOMSupprimerArcPartant(CSommet * pArgDestination)
{
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
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur() << std::endl;
	}
}


/* Fonction de suppression d'arc arrivant
		Entrée :
			- pArgDepart : Pointeur vers le CSommet de l'arc à supprimer
*/
void CSommet::SOMSupprimerArcArrivant(CSommet * pArgDepart)
{
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
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur() << std::endl;
	}
}