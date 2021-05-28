#include "CSommet.h"

#pragma once
class CGraphe
{
private:
	CSommet** ppSomGPHSommets;
	unsigned int uiGPHNbSommets;

public:
	CGraphe();
	CGraphe(CGraphe* GPHarg);
	~CGraphe();

	void GPHAjouterSommet(CSommet* pArgSommet);
	void GPHSupprimerSommet(CSommet* pArgSommet);
	int GPHIsSommetExists(CSommet* pArgSommet);

	void GPHAjouterArc(CSommet* pArgSommetSource, CSommet* pArgSommetDestination);

	void GPHAfficher();

	CSommet * GPHGetSommet(unsigned int uiIndice);


	/* Retourne un nouveau tableau de dimension uiArgNbNew avec les valeurs recopiées de ppArcArg
		Entrée :
			- pArgDepart : Pointeur vers le sommet de départ de l'arc
			- pArgDestination : Pointeur vers le sommet de destination de l'arc
	*/
	void GPHSupprimerArc(CSommet* pArgDepart, CSommet* pArgDestination) {
		pArgDepart->SOMSupprimerArcPartant(pArgDestination);
		pArgDestination->SOMSupprimerArcArrivant(pArgDepart);
	}
};

