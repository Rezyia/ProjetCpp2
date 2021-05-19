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

	void GPHFreeSommets();
	void GPHDispSommets();

	CSommet * GPHGetSommet(unsigned int uiIndice);

	void GPHSupprimerArc(CSommet* pArgDepart, CSommet* pArgDestination) {
		pArgDepart->SOMSupprimerArcPartant(pArgDestination);
		pArgDestination->SOMSupprimerArcArrivant(pArgDepart);
	}



	
};

