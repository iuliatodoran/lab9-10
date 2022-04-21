#include "Produs.h"

Produs::Produs()
{
	this->cod = -1;
	this->nume = "none";
	this->pret = 0;
}

Produs::Produs(int cod, string nume, int pret)
{
	this->cod = cod;
	this->nume = nume;
	this->pret = pret;
}

Produs::Produs(const Produs& other)
{
	this->cod = other.cod;
	this->nume = other.nume;
	this->pret = other.pret;
}

int Produs::getCod() const
{
	return this->cod;
}

string Produs::getNume() const
{
	return this->nume;
}

int Produs::getPret() const
{
	return this->pret;
}

void Produs::setCod(int newCod)
{
	this->cod = newCod;
}

void Produs::setNume(string newNume)
{
	this->nume = newNume;
}

void Produs::setPret(int newPret)
{
	this->pret = newPret;
}

Produs& Produs::operator=(const Produs& other)
{
	this->cod = other.cod;
	this->nume = other.nume;
	this->pret = other.pret;

	return *this;
}

bool Produs::operator==(const Produs& other) const
{
	return this->cod == other.cod && this->nume == other.nume && this->pret == other.pret;
}

std::ostream& operator<<(std::ostream& s, const Produs& produs)
{
	s << "Cod: " << produs.cod << "\n" << "Nume: " << produs.nume << "\n" << "Pret: " << produs.pret << "\n";

	return s;
}
