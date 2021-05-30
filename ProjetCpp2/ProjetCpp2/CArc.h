#pragma once
#include <iostream>

class CArc
{
private:
	unsigned int uiARCDestination;

public:
	// Constructeur par défaut
	CArc(unsigned int uiArgDest) {
		uiARCDestination = uiArgDest;
	}
	// Constructeur de recopie
	CArc(CArc* ARCarg) {
		uiARCDestination = ARCarg->ARCGetNumero();
	}

	// Fonction d'affichage de l'arc
	void ARCAfficher() {
		std::cout << "\tArc vers " << uiARCDestination;
	}

	// Getter : retourne le numéro de destination de l'arc
	unsigned int ARCGetNumero() {
		return uiARCDestination;
	}

	// Setter : associe le numéro de destination de l'arc avec l'argument passé en paramètre
	void ARCSetNumero(unsigned int uiArgNumDest) {
		uiARCDestination = uiArgNumDest;
	}
};

