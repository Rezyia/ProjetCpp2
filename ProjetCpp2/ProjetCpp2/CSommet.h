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


	bool SOMIsEmptyArrivants();
	bool SOMIsEmptyPartants();
	void SOMAjouterArc(CSommet* pArgDestination); // Ajouter l'arc du sommet appelé vers la destination.
	void SOMSupprimerArc(CSommet* pArgDestination); // Supprimer l'arc du sommet appelé vers la destination.
	CArc* SOMGetArc(CSommet* pArgDestination); // Retoure l'arc du sommet vers la destination passée en paramètre.


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

	// Setter : associe le numéro du sommet avec l'argument passé en paramètre
	void SOMSetNumero(unsigned int uiArgNum) {
		uiSOMNumero = uiArgNum;
	}
};

