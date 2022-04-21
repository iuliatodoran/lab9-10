#pragma once
#include <iostream>
#include <string>
using std::string;

class Produs {
public:
	// Constructors
	Produs();
	Produs(int cod, string nume, int pret);
	Produs(const Produs& other);

	// Getters
	int getCod() const;
	string getNume() const;
	int getPret() const;

	// Setters
	void setCod(int newCod);
	void setNume(string newNume);
	void setPret(int newPret);

	// Operators
	Produs& operator=(const Produs& other);
	friend std::ostream& operator<<(std::ostream& s, const Produs& produs);
	bool operator==(const Produs& other) const;

private:
	int cod;
	string nume;
	int pret;
};