#include "CArc.h"



#pragma once
class CSommet
{
private:
	unsigned int uiSOMNumero;
	CArc** ppArcSomPartants;
	CArc** ppArcSomArrivants;
	unsigned int uiSOMNbPartants;
	unsigned int uiSOMNbArrivants;

public:
	// Constructeur par défaut
	CSommet();

	// Constructeur de recopie
	CSommet(CSommet* SOMarg);

	// Constructeur de confort ()
	CSommet(unsigned int uiArg);

	// Destructeur
	~CSommet();


	bool SOMIsEmptyArrivants() {
		return (uiSOMNbArrivants == 0);
	}
	bool SOMIsEmptyPartants() {
		return (uiSOMNbPartants == 0); 
	}

	int SOMIsArcPartantExist(CSommet* pArgDestination); //Vérifie si un arc vers la destination existe
	int SOMIsArcArrivantExist(CSommet* pArgDepart); //Vérifie si un arc partant du départ existe

	//void SOMAjouterArc(CSommet* pArgDestination); // Ajouter l'arc du sommet appelé vers la destination.

	void SOMSupprimerArcPartant(CSommet* pArgDestination); // Supprimer l'arc partant du sommet appelé vers la destination.
	void SOMSupprimerArcArrivant(CSommet* pArgDepart);		//Supprimer l'arc arrivant du sommet appelé depuis le départ.

	void SOMAjouterArcPartant(CSommet* pArgSommet);
	void SOMAjouterArcArrivant(CSommet* pArgSommet);
	
	
	/* Retoure un arc du tableau des arcs arrivants.
		Entrée : 
			- uiArgId : indice de l'arc dans le tableau
		Sortie:
			- Le CArc de l'indice donné
	*/
	CArc* SOMGetArcArrivant(unsigned int uiArgId)
	{
		return ppArcSomArrivants[uiArgId];
	}


	/* Retoure un arc du tableau des arcs partants.
		Entrée :
			- uiArgId : indice de l'arc dans le tableau
		Sortie:
			- Le CArc de l'indice donné
	*/
	CArc* SOMGetArcPartant(unsigned int uiArgId)
	{
		return ppArcSomPartants[uiArgId];
	}


	// Getter : retourne le numéro du sommet
	unsigned int SOMGetNumero() {
		return uiSOMNumero;
	}

	// Getter : retourne le nombre d'arcs partants du sommet
	unsigned int SOMGetNbPartants() {
		return uiSOMNbPartants;
	}

	// Getter : retourne le nombre d'arcs arrivants au sommet
	unsigned int SOMGetNbArrivants() {
		return uiSOMNbArrivants;
	}

	// Getter : retourne les arcs arrivants au sommet
	CArc** SOMGetArrivants() {
		return ppArcSomArrivants;
	}

	// Getter : retourne les arcs partant du sommet
	CArc** SOMGetPartants() {
		return ppArcSomPartants;
	}

<<<<<<< HEAD
	void SOMSetArrivants(CArc** ppArcArg) {
		ppArcSomArrivants = ppArcArg;
	}

	void SOMSetPartants(CArc** ppArcArg) {
		ppArcSomPartants = ppArcArg;
	}

	void SOMSetNbArrivants(unsigned int uiArg) {
		uiSOMNbArrivants = uiArg;
	}

	void SOMSetNbPartants(unsigned int uiArg) {
		uiSOMNbPartants = uiArg;
	}


	/* Associe le numéro du sommet avec l'argument passé en paramètre
		Entrée :
			- uiArgNum : Nouveau numéro du sommet
	*/
	void SOMSetNumero(unsigned int uiArgNum) {
		uiSOMNumero = uiArgNum;
	}

=======
>>>>>>> 285898855e584832d9c4509e13b1da9fbd324158
	void SOMAfficher();
};
