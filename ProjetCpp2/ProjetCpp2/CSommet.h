#include "CArc.h"

#pragma once
class CSommet
{
private:
	unsigned int uiSOMNumero;
	CArc** ppArcSomPartants;
	CArc** ppArcSomArrivants;

public:
	CSommet();
	CSommet(CSommet* SOMarg);
	CSommet(unsigned int uiArg);

	bool SOMIsEmptyArrivants();
	bool SOMIsEmptyPartants();
	bool SOMIsArcExist(CSommet* pArgDestination); //Vérifie si un arc vers la destination existe
	void SOMAjouterArc(CSommet* pArgDestination); // Ajouter l'arc du sommet appelé vers la destination.
	void SOMSupprimerArc(CSommet* pArgDestination); // Supprimer l'arc du sommet appelé vers la destination.

	// Getter
	unsigned int SOMGetNumero() {
		return uiSOMNumero;
	}

	// Setter
	void SOMSetNumero(unsigned int uiArgNum) {
		uiSOMNumero = uiArgNum;
	}
};

