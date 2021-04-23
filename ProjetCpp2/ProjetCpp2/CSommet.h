#include "CArc.h"



#pragma once
class CSommet
{
private:
	unsigned int uiSOMNumero;
	CArc** ppArcSomPartants;
	CArc** ppArcSomArrivants;
	unsigned int uiSOMNbPartants;
	unsigned int uiSOMNbArrivants;

public:
	// Constructeur par défaut
	CSommet();

	// Constructeur de recopie
	CSommet(CSommet* SOMarg);

	// Constructeur de confort ()
	CSommet(unsigned int uiArg);

	// Destructeur
	~CSommet();


	bool SOMIsEmptyArrivants() {
		return uiSOMNbArrivants == 0;
	}
	bool SOMIsEmptyPartants() {
		return uiSOMNbPartants == 0;
	}
	bool SOMIsArcExist(CSommet* pArgDestination); //Vérifie si un arc vers la destination existe
	void SOMAjouterArc(CSommet* pArgDestination); // Ajouter l'arc du sommet appelé vers la destination.
	void SOMSupprimerArc(CSommet* pArgDestination); // Supprimer l'arc du sommet appelé vers la destination.
	//CArc* SOMGetArc(CSommet* pArgDestination); // Retoure l'arc du sommet vers la destination passée en paramètre.


	/* Retourne un nouveau tableau de dimension uiArgNbNew avec les valeurs recopiées de ppArcArg
		Entrée :
			- ppArcArg : Tableau a copier
			- uiArgNbNew : Taille du nouveau tableau
			- uiArgNbOld : Taille de l'ancien tableau
		Sortie :
			- Recopie de l'ancien tableau avec les nouvelles dimensions
	*/
	CArc** SOMCopieTabArcs(CArc** ppArcArg, unsigned int uiArgNbNew, unsigned int uiArgNbOld);



	// Getter : retourne le numéro du sommet
	unsigned int SOMGetNumero() {
		return uiSOMNumero;
	}

	// Getter : retourne le nombre d'arcs partants
	unsigned int SOMGetNbPartants() {
		return uiSOMNbPartants;
	}

	// Getter : retourne le nombre d'arcs arrivants
	unsigned int SOMGetNbArrivants() {
		return uiSOMNbArrivants;
	}


	/* Associe le numéro du sommet avec l'argument passé en paramètre
		Entrée :
			- uiArgNum : Nouveau numéro du sommet
	*/
	void SOMSetNumero(unsigned int uiArgNum) {
		uiSOMNumero = uiArgNum;
	}
};

