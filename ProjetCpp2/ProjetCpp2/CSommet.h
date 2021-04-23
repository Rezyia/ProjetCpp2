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

	bool SOMIsEmptyArrivants();
	bool SOMIsEmptyPartants();
	void SOMAjouterArc(CSommet* pArgDestination); // Ajouter l'arc du sommet appelé vers la destination.
	void SOMSupprimerArc(CSommet* pArgDestination); // Supprimer l'arc du sommet appelé vers la destination.
};

