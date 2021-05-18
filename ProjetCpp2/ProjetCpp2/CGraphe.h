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
	bool GPHSommetExists(CSommet* pArgSommet);

	void GPHAjouterArc(CSommet* pArgSommetSource, CSommet* pArgSommetDestination);

	void GPHAfficher();

	void GPHFreeSommets();
	void GPHDispSommets();



	// Getter : retourne le pointeur CSommet d'indice uiIndice
	CSommet* GPHGetSommet(unsigned int uiIndice) {
		return ppSomGPHSommets[uiIndice];
	}
};

