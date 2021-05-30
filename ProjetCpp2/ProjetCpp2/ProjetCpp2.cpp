// ProjetCpp2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CGraphe.h"

int main()
{
	CGraphe graphe = new CGraphe();

	std::cout << "CGraphe créé" << std::endl;

	CSommet* s1 = new CSommet(1);
	graphe.GPHAjouterSommet(s1);
	CSommet* s2 = new CSommet(2);
	graphe.GPHAjouterSommet(s2);
	CSommet* s3 = new CSommet(3);
	graphe.GPHAjouterSommet(s3);
	CSommet* s4 = new CSommet(4);
	graphe.GPHAjouterSommet(s4);
	CSommet* s5 = new CSommet(5);
	graphe.GPHAjouterSommet(s5);
	CSommet* s6 = new CSommet(6);
	graphe.GPHAjouterSommet(s6);
	CSommet* s7 = new CSommet(7);
	graphe.GPHAjouterSommet(s7);
	CSommet* s8 = new CSommet(8);
	graphe.GPHAjouterSommet(s8);

	std::cout << "Sommets créés" << std::endl;

	graphe.GPHAjouterArc(s1, s2);
	graphe.GPHAjouterArc(s1, s3);
	graphe.GPHAjouterArc(s1, s4);
	graphe.GPHAjouterArc(s1, s5);
	graphe.GPHAjouterArc(s2, s6);
	graphe.GPHAjouterArc(s3, s6);
	graphe.GPHAjouterArc(s3, s7);
	graphe.GPHAjouterArc(s4, s6);
	graphe.GPHAjouterArc(s4, s7);
	graphe.GPHAjouterArc(s5, s7);
	graphe.GPHAjouterArc(s6, s8);
	graphe.GPHAjouterArc(s7, s8);

	std::cout << "Arcs créés" << std::endl;

	std::cout << "\nAffichage du graphe :" << std::endl;
	graphe.GPHAfficher();

	std::cout << "Fin du programme." << std::endl;

	CGraphe gFichier = new CGraphe((char*)"test.txt");
	gFichier.GPHAfficher();

	//Tentative de création de graphe inverse
	CGraphe graphe_inverse = new CGraphe(graphe);
	for (unsigned int uiBoucle = 0; uiBoucle < graphe_inverse.GPHGetNbSommet(); uiBoucle++) {
		CSommet* pSomBoucle = graphe_inverse.GPHGetAllSommet()[uiBoucle];

		CArc** ppArcTmp = pSomBoucle->SOMGetPartants();
		unsigned int uiTmp = pSomBoucle->SOMGetNbPartants();

		pSomBoucle->SOMSetPartants(pSomBoucle->SOMGetArrivants());
		pSomBoucle->SOMSetNbPartants(pSomBoucle->SOMGetNbArrivants());

		pSomBoucle->SOMSetArrivants(ppArcTmp);
		pSomBoucle->SOMSetNbArrivants(uiTmp);
	}
	graphe_inverse.GPHAfficher();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
