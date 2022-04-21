#pragma once
#include <iostream>
#include "Tonomat.h"
#include "Produs.h"

class Service : public Tonomat, Produs {
public:
	// Constructors
	Service();
	Service(const Tonomat& tonomat, Bani baniClient);

	// Getters
	Tonomat getTonomat();
	Bani getBaniClient();

	// Setters
	void setTonomat(const Tonomat& newTonomat);
	void addBaniTonomat(Bani newBani);
	void setBaniClient(Bani newBaniClient);
	void addItem(const Produs& produs);

	// Operations
	Bani giveChange(const Produs& produs);
	bool buyProdus(int codProdus);

private:
	Tonomat tonomat;
	Bani baniClient;
};