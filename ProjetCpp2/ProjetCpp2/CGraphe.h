#include "CSommet.h"

#pragma once
class CGraphe
{
private:
	CSommet** ppGPHSommets;

public:
	void GPHAjouterSommet(CSommet* pArgSommet);
	void GPHSupprimerSommet(CSommet* pArgSommet);
	bool GPHSommetExists(CSommet* pArgSommet);
	void GPHAfficher();
};

