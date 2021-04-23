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
	unsigned int SOMGetNumero() {
		return uiARCDestination;
	}

	// Setter
	void SOMSetNumero(unsigned int uiArgNumDest) {
		uiARCDestination = uiArgNumDest;
	}
};

