#pragma once
#include <iostream>
class CArc
{
private:
	unsigned int uiARCDestination;

public:
	CArc();
	CArc(unsigned int uiArgDest) {
		uiARCDestination = uiArgDest;
	}
	CArc(CArc* ARCarg) {
		uiARCDestination = ARCarg->ARCGetNumero();
	}

	void ARCAfficher() {
		std::cout << "Arc vers " + uiARCDestination;
	}

	// Getter
	unsigned int ARCGetNumero() {
		return uiARCDestination;
	}

	// Setter
	void ARCSetNumero(unsigned int uiArgNumDest) {
		uiARCDestination = uiArgNumDest;
	}
};

