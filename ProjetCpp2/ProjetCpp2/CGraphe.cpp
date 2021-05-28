#include "CGraphe.h"
#include "CException.h"

#define ERROR_SOMMET_EXIST "Le sommet existe deja"
#define ERROR_SOMMET_NOT_EXIST "Le sommet n'existe pas"


/* Constructeur par défaut
*/
CGraphe::CGraphe()
{
	ppSomGPHSommets = (CSommet**) malloc(sizeof(CSommet*));
	uiGPHNbSommets = 0;
}


/* Constructeur de recopie
		Entrée :
			- GPHarg : Autre CGraphe à recopier
*/
CGraphe::CGraphe(CGraphe * GPHarg)
{
	unsigned int uiBoucle = 0;
	//Ajout des Sommets
	for (uiBoucle; uiBoucle < GPHarg->uiGPHNbSommets; uiBoucle++) {
		GPHAjouterSommet(new CSommet(GPHarg->ppSomGPHSommets[uiBoucle]->SOMGetNumero()));
	}
	//Ajout des Arcs
	for (uiBoucle = 0; uiBoucle < GPHarg->uiGPHNbSommets; uiBoucle++) {
		unsigned int uiBoucleArc = 0;
		CSommet * SomOriginal = GPHarg->ppSomGPHSommets[uiBoucle];
		CSommet * SomDepart = ppSomGPHSommets[uiBoucle];
		for (uiBoucleArc; uiBoucleArc < SomOriginal->SOMGetNbPartants(); uiBoucleArc++) {
			unsigned int uiNumDest = SomOriginal->SOMGetArcPartant(uiBoucleArc)->ARCGetNumero();
			unsigned int uiPosDest = GPHIsSommetExists(GPHarg->GPHGetSommet(uiNumDest));
			CSommet * SomDestination = ppSomGPHSommets[uiPosDest];
			GPHAjouterArc(SomDepart, SomDestination);
		}
	}
}


/* Destructeur
*/
CGraphe::~CGraphe() { // a corriger
	
	for (unsigned int uiDealloc = 0; uiDealloc < uiGPHNbSommets; uiDealloc++) {
		delete ppSomGPHSommets[uiDealloc];
	}
	//free(ppSomGPHSommets);
	ppSomGPHSommets = nullptr;
}


/* Fonction d'ajout d'arc
		Entrée :
			- pArgSommetSource : Pointeur vers le CSommet source de l'arc à ajouter
			- pArgSommetDestination : Pointeur vers le CSommet destination de l'arc à ajouter
*/
void CGraphe::GPHAjouterArc(CSommet* pArgSommetSource, CSommet* pArgSommetDestination) {
	pArgSommetSource->SOMAjouterArcPartant(pArgSommetDestination);
	pArgSommetDestination->SOMAjouterArcArrivant(pArgSommetSource);
}


/* Fonction d'ajout de sommet
		Entrée :
			- pArgSommet : Pointeur vers le CSommet à ajouter
*/
void CGraphe::GPHAjouterSommet(CSommet * pArgSommet)
{
	try {
		if (GPHIsSommetExists(pArgSommet) != -1) {
			throw new CException((char*)ERROR_SOMMET_EXIST);
		}

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

		ppSomGPHSommets = ppNewSommets;
		uiGPHNbSommets++;
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur();
	}
}

/* Fonction de suppression de sommet
		Entrée :
			- pArgSommet : Pointeur vers le CSommet à supprimer
*/
void CGraphe::GPHSupprimerSommet(CSommet * pArgSommet)
{
	try {
		int iPosSommet = GPHIsSommetExists(pArgSommet);
		if (iPosSommet == -1) {
			throw new CException((char*)ERROR_SOMMET_NOT_EXIST);
		}
		unsigned int uiBoucle;
		for (uiBoucle = iPosSommet; uiBoucle < uiGPHNbSommets - 1; uiBoucle++) {
			ppSomGPHSommets[uiBoucle] = ppSomGPHSommets[uiBoucle+1];
		}
		uiGPHNbSommets--;
		realloc(ppSomGPHSommets, uiGPHNbSommets * sizeof(CSommet*));
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur();
	}
}

/* Fonction d'ajout d'arc
		Entrée :
			- pArgSommet : Pointeur vers le CSommet source de l'arc à ajouter
*/
int CGraphe::GPHIsSommetExists(CSommet * pArgSommet)
{
	bool bTrouve = false;
	unsigned int uiBoucle = 0;
	while (!bTrouve && uiBoucle != uiGPHNbSommets) {
		if (ppSomGPHSommets[uiBoucle]->SOMGetNumero() == pArgSommet->SOMGetNumero()) {
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


/* Fonction pour afficher le graphe
*/
void CGraphe::GPHAfficher()
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiGPHNbSommets; uiBoucle++) {
		ppSomGPHSommets[uiBoucle]->SOMAfficher();
		std::cout << std::endl;
	}
}


// Getter : retourne le pointeur CSommet d'indice uiIndice
CSommet* CGraphe::GPHGetSommet(unsigned int uiIndice) {
	try {
		unsigned int uiBoucle = 0;
		for (uiBoucle; uiBoucle < uiGPHNbSommets; uiBoucle++) {
			if (ppSomGPHSommets[uiBoucle]->SOMGetNumero() == uiIndice) {
				return ppSomGPHSommets[uiBoucle];
			}
		}
		throw new CException((char*)ERROR_SOMMET_NOT_EXIST);
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur();
	}
	return nullptr;
}