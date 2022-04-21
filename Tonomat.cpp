#include "Tonomat.h"

Tonomat::Tonomat()
{
	this->produse;
	this->baniTonomat.unLeu = 0;
	this->baniTonomat.cinciLei = 0;
	this->baniTonomat.zeceLei = 0;
	this->baniTonomat.cincizeciLei = 0;
}

Tonomat::Tonomat(const Tonomat& other)
{
	this->produse = other.produse;
	this->baniTonomat.unLeu = other.baniTonomat.unLeu;
	this->baniTonomat.cinciLei = other.baniTonomat.cinciLei;
	this->baniTonomat.zeceLei = other.baniTonomat.zeceLei;
	this->baniTonomat.cincizeciLei = other.baniTonomat.cincizeciLei;
}

Tonomat::~Tonomat()
{
	this->produse.~vector();
}

vector<Produs> Tonomat::getAll()
{
	return this->produse;
}

Bani Tonomat::getBani()
{
	return this->baniTonomat;
}

void Tonomat::setAll(vector<Produs> newProduse)
{
	this->produse = newProduse;
}

void Tonomat::setBani(Bani newBani)
{
	this->baniTonomat = newBani;
}

void Tonomat::addItem(const Produs& item)
{
	this->produse.push_back(item);
}

Bani operator-(const Bani& first, const Bani& second)
{
	return Bani(first.unLeu - second.unLeu, first.cinciLei - second.cinciLei, first.zeceLei - second.zeceLei, first.cincizeciLei - second.cincizeciLei);
}

Bani operator+(const Bani& first, const Bani& second)
{
	return Bani(first.unLeu + second.unLeu, first.cinciLei + second.cinciLei, first.zeceLei + second.zeceLei, first.cincizeciLei + second.cincizeciLei);
}

bool operator==(const Bani& first, const Bani& second)
{
	return first.unLeu == second.unLeu && first.cinciLei == second.cinciLei && first.zeceLei == second.zeceLei && first.cincizeciLei == second.cincizeciLei;
}

std::ostream& operator<<(std::ostream& s, Tonomat& tonomat)
{
	for (vector<Produs>::iterator it = tonomat.getAll().begin(); it != tonomat.getAll().end(); it++) {
		s << *it << "\n";
	}

	return s;
}

Bani::Bani()
{
	this->unLeu = 0;
	this->cinciLei = 0;
	this->zeceLei = 0;
	this->cincizeciLei = 0;
}

Bani::Bani(int unLeu, int cinciLei, int zeceLei, int cincizeciLei)
{
	this->unLeu = unLeu;
	this->cinciLei = cinciLei;
	this->zeceLei = zeceLei;
	this->cincizeciLei = cincizeciLei;
}

Bani::Bani(const Bani& other)
{
	this->unLeu = other.unLeu;
	this->cinciLei = other.cinciLei;
	this->zeceLei = other.zeceLei;
	this->cincizeciLei = other.cincizeciLei;
}

int Bani::getTotal()
{
	return 1 * unLeu + 5 * cinciLei + 10 * zeceLei + 50 * cincizeciLei;
}
