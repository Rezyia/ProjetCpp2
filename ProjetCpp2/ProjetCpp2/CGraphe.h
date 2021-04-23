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
};

