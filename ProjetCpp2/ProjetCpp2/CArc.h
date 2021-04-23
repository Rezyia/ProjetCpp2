#pragma once
class CArc
{
private:
	unsigned int uiARCDestination;

public:
	CArc();
	CArc(unsigned int uiArgDest);

	void ARCAfficher();


	// Getter
	unsigned int ARCGetNumero() {
		return uiARCDestination;
	}

	// Setter
	void ARCSetNumero(unsigned int uiArgNumDest) {
		uiARCDestination = uiArgNumDest;
	}
};

