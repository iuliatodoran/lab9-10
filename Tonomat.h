#pragma once
#include "Produs.h"
#include <iostream>
#include <vector>
using std::vector;

class Bani {
public:
	int unLeu;
	int cinciLei;
	int zeceLei;
	int cincizeciLei;

	// Constructor
	Bani();
	Bani(int unLeu, int cinciLei, int zeceLei, int cincizeciLei);
	Bani(const Bani& other);

	int getTotal();

	// Operator
	friend Bani operator-(const Bani& first, const Bani& second);
	friend Bani operator+(const Bani& first, const Bani& second);
	friend bool operator==(const Bani& first, const Bani& second);

};

class Tonomat : public Produs {
public:
	// Constructors
	Tonomat();
	Tonomat(const Tonomat& other);

	// Destructor
	~Tonomat();

	// Getters
	vector<Produs> getAll();
	Bani getBani();

	// Setters
	void setAll(vector<Produs> newProduse);
	void setBani(Bani newBani);

	// Operations
	void addItem(const Produs& item);

	// Operators
	friend std::ostream& operator<<(std::ostream& s, const Tonomat& tonomat);

private:
	vector<Produs> produse;
	Bani baniTonomat;
	friend class Service;
};