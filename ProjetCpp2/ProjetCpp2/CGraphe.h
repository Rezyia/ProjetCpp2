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
	void GPHAjouterSommet(CSommet* pArgSommet);
	void GPHSupprimerSommet(CSommet* pArgSommet);
	bool GPHSommetExists(CSommet* pArgSommet);
	void GPHAfficher();

	void GPHFreeSommets();
	void GPHDispSommets();



	// Getter : retourne le pointeur CSommet d'indice uiIndice
	CSommet* GPHGetSommet(unsigned int uiIndice) {
		std::cout << "test-1" << std::endl;
		return ppSomGPHSommets[uiIndice];
	}
};

