#include "CGraphe.h"
#include "CException.h"

#define ERROR_SOMMET_EXIST "Le sommet existe deja";
#define ERROR_SOMMET_NOT_EXIST "Le sommet n'existe pas";

CGraphe::CGraphe()
{
}

CGraphe::CGraphe(CGraphe * GPHarg)
{
}

void CGraphe::GPHAjouterSommet(CSommet * pArgSommet)
{
	try {
		if (GPHSommetExists(pArgSommet)) {
			throw new CException((char*)ERROR_SOMMET_EXIST);
		}
		//TODO : reste du code
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur();
	}
}

void CGraphe::GPHSupprimerSommet(CSommet * pArgSommet)
{
	try {
		if (!GPHSommetExists(pArgSommet)) {
			throw new CException((char*)ERROR_SOMMET_NOT_EXIST);
		}
		//TODO : reste du code
	}
	catch (CException EXClevee) {
		std::cout << EXClevee.EXCLireErreur();
	}
}

bool CGraphe::GPHSommetExists(CSommet * pArgSommet)
{
	return false;
}

void CGraphe::GPHAfficher()
{
}
