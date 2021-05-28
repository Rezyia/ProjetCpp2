#include "CGraphe.h"
#include "CException.h"
#include <fstream>
#include <stdio.h>
#include <cstring>


#define ERROR_SOMMET_EXIST "Le sommet existe deja"
#define ERROR_SOMMET_NOT_EXIST "Le sommet n'existe pas"

#define NBRE_MAX_LIGNES_FICHIER 255
#define NBRE_MAX_CHAMPS_FICHIER 32

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

/* Fonction pour obtenir la valeur suivante
	Entrée : 
		- pcLine : pointeur vers la ligne à "analyser"
	Sortie : 
		- char* de la valeur obtenue
*/
char* getLineValue(char* pcLine) {
	char* pcValue = (char*)malloc((NBRE_MAX_LIGNES_FICHIER - NBRE_MAX_CHAMPS_FICHIER) * sizeof(char));
	int indiceCourrant = 0;
	int indiceValeurCourrante = 0;


	// On passe jusqu'aux '=' :
	while (pcLine[indiceCourrant] != '=' && indiceCourrant < NBRE_MAX_LIGNES_FICHIER) {
		if (pcLine[indiceCourrant] == '\0' || pcLine[indiceCourrant] == '\n') // 
			std::cout << "Erreur : fin de ligne imprévue\n";
		indiceCourrant++;
	}
	indiceCourrant++; // Pour passer le '='


	// Analyse de la valeur :
	while (pcLine[indiceCourrant] != '\0' && pcLine[indiceCourrant] != '\n' && pcLine[indiceCourrant] != ',' && indiceCourrant < NBRE_MAX_LIGNES_FICHIER) {
		pcValue[indiceValeurCourrante] = pcLine[indiceCourrant];

		indiceValeurCourrante++;
		indiceCourrant++;
	}
	pcValue[indiceValeurCourrante] = '\0';

	return pcValue;
}


/* Constructeur par fichier
	Entrée :
		- pcNomFichier : nom du fichier 
*/
CGraphe::CGraphe(char* pcNomFichier) {
	// Ouverture du fichier :
	std::ifstream ifsFichier(pcNomFichier);

	if (!ifsFichier.is_open()) {
		std::cout << "Le fichier n'a pas pu être ouvert\n";
	}
	// Si fichier ouvert correctement :
	else {
		unsigned int uiNbArcs = 0;
		int iNumChamps = 0;
		char cLigne[NBRE_MAX_LIGNES_FICHIER];

		// Récupère la première ligne du fichier :
		ifsFichier >> cLigne;

		int indiceCourrant = 0;
		int indiceValeurCourrante = 0;
		char* valeurCourrante = (char*)malloc((NBRE_MAX_LIGNES_FICHIER - NBRE_MAX_CHAMPS_FICHIER) * sizeof(char));

		// On suppose que le format est respecté

		// Tant que tous les champs n'ont pas été complétés :
		while (iNumChamps < 4 && ifsFichier.good()) { // 4 champs nécessaires : NBSommets, NBArcs, Sommets et Arcs
			//Pour chaque ligne du fichier :
			valeurCourrante = getLineValue(cLigne);

			// Affectation des attributs :
			switch (iNumChamps) {
				// NBSommet :
			case 0:
				uiGPHNbSommets = atoi((const char*)valeurCourrante);
				break;


				// NBArcs :
			case 1:
				uiNbArcs = atoi((const char*)valeurCourrante);
				break;


				// Sommets :
			case 2:
			{
				// Initialisation tableau sommets : 
				ppSomGPHSommets = (CSommet**)malloc(uiGPHNbSommets * sizeof(CSommet*));
				unsigned int uiBoucleInitSommets = 0;

				// Retour à la ligne (début des valeurs) :
				ifsFichier >> cLigne;

				while (uiBoucleInitSommets < uiGPHNbSommets) {
					// Ajout nouveau CSommet :
					GPHAjouterSommet(new CSommet(atoi((const char*) getLineValue(cLigne))));

					// Passage à la valeur suivante :
					ifsFichier >> cLigne;

					uiBoucleInitSommets++;
				}
			}
			break;

				// Arcs :
			case 3:
			{
				unsigned int uiBoucleInitArcs= 0;

				// Retour à la ligne (début des valeurs) :
				ifsFichier >> cLigne;

				while (uiBoucleInitArcs< uiGPHNbSommets) {

					const char* pccVal1 = getLineValue(cLigne); // Numéro sommet début arc
					const char* pccVal2 = getLineValue((char*)pccVal1); // Numéro sommet fin arc

					CSommet* pSOMdebut = GPHGetSommet(atoi(pccVal1));
					CSommet* pSOMfin = GPHGetSommet(atoi(pccVal2));

					// Ajout nouvel arc :
					GPHAjouterArc(pSOMdebut, pSOMfin);

					// Passage à la valeur suivante :
					ifsFichier >> cLigne;

					uiBoucleInitArcs++;
				}
			}
			break;


			default:
				std::cout << "switch défaut, erreur rencontrée" << std::endl;
				break;
			}



			// Passage au champs suivant :
			iNumChamps++;
			ifsFichier >> cLigne;
		}
	}
	//std::cout << "Fin constructeur par fichier. \n";
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

/* Fonction de vérification de doublons
		Entrée :
			- pArgSommet : Pointeur vers le CSommet de l'arc à vérifier
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


// Getter : retourne le pointeur CSommet de numéro uiNum
CSommet* CGraphe::GPHGetSommet(unsigned int uiNum) {
	try {
		unsigned int uiBoucle = 0;
		for (uiBoucle; uiBoucle < uiGPHNbSommets; uiBoucle++) {
			if (ppSomGPHSommets[uiBoucle]->SOMGetNumero() == uiNum) {
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