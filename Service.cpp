#include "Service.h"

Service::Service()
{
	this->tonomat = Tonomat();
	this->baniClient.unLeu = 0;
	this->baniClient.cinciLei = 0;
	this->baniClient.zeceLei = 0;
	this->baniClient.cincizeciLei = 0;
}

Service::Service(const Tonomat& tonomat, Bani baniClient)
{
	this->tonomat = tonomat;
	this->baniClient.unLeu = baniClient.unLeu;
	this->baniClient.cinciLei = baniClient.cinciLei;
	this->baniClient.zeceLei = baniClient.zeceLei;
	this->baniClient.cincizeciLei = baniClient.cincizeciLei;
}

Tonomat Service::getTonomat()
{
	return this->tonomat;
}

Bani Service::getBaniClient()
{
	return this->baniClient;
}

void Service::setTonomat(const Tonomat& newTonomat)
{
	this->tonomat = newTonomat;
}

void Service::addBaniTonomat(Bani newBani)
{
	this->tonomat.setBani(this->tonomat.getBani() + newBani);
}

void Service::setBaniClient(Bani newBaniClient)
{
	this->baniClient.unLeu = newBaniClient.unLeu;
	this->baniClient.cinciLei = newBaniClient.cinciLei;
	this->baniClient.zeceLei = newBaniClient.zeceLei;
	this->baniClient.cincizeciLei = newBaniClient.cincizeciLei;
}

void Service::addItem(const Produs& produs)
{
	this->tonomat.addItem(produs);
}

bool Service::buyProdus(int codProdus)
{
	// Cautam produsul dupa cod pentru a vedea daca exista in tonomat
	bool found = false;
	Produs produs;
	for (std::vector<Produs>::iterator it = this->tonomat.produse.begin(); it != this->tonomat.produse.end() && !found; it++) {
		if (it->getCod() == codProdus) {
			found = true;
			produs = *it;
		}
	}

	// Daca produsul nu exista, nu se poate efectua operatia
	if (!found)
		return false;
	// Daca exista, incercam sa finalizam plata iar daca exista destule monezi pentru a da restul clientului operatia va fi efectuata, altfel, nu se va putea efectua
	else {
		Bani rest = giveChange(produs);

		// Daca tonomatul nu are destule bancnote sa dea rest, functia va returna un struct Bani cu restul -1
		if (rest.unLeu == -1)
			return false;
		else
		{
			return true;
		}
	}

}

// TODO: Implementez functie greedy care sa ia cea mai mica bancnota posibila iar cand nu este o bancnota mai mica decat cea nevoita, iau una mai mare si adaug la rest,
// ulterior, verific si daca tonomatul are destui bani sa dea rest
Bani Service::giveChange(const Produs& produs)
{
	Bani rest = Bani();
	Bani baniTonomat = this->tonomat.getBani();
	Bani copieBaniClient = this->baniClient;
	int total = 0, totalRest = 0;
	
	// Mai intai incerc sa iau un numar fix de bancnote folosind un algoritm greedy astfel incat aparatul sa nu dea rest inapoi,
	// daca nu reusesc, voi lua o moneda mai mare astfel incat aparatul sa dea cel mai mic rest posibil
	while (produs.getPret() > total && !(copieBaniClient == Bani())) {
		if (copieBaniClient.unLeu > 0)
		{
			copieBaniClient.unLeu--;
			baniTonomat.unLeu++;
			total += 1;
		}

		else if (copieBaniClient.cinciLei > 0) 
		{
			copieBaniClient.cinciLei--;
			baniTonomat.cinciLei++;
			total += 5;
		}
		
		else if (copieBaniClient.zeceLei > 0)
		{
			copieBaniClient.zeceLei--;
			baniTonomat.zeceLei++;
			total += 10;
		}
		
		else if (copieBaniClient.cincizeciLei > 0)
		{
			copieBaniClient.cincizeciLei--;
			baniTonomat.cincizeciLei++;
			total += 50;
		}

		else {
			break;
		}
	}

	// Daca am gasit destule bancnote, tranzactia e terminata, nu avem rest de dat iar tonomatul primeste banii clientului
	if (total == produs.getPret()) {
		this->baniClient = copieBaniClient;
		this->tonomat.setBani(baniTonomat);
		return rest;
	}
	// Daca nu am gasit destule bancnote inseamna ca clientul nu a bagat destui bani
	else if (total < produs.getPret()) {
		rest.unLeu = -1;
		return rest;
	}
	// Daca totalul a depasit produsul pretului inseamna ca tonomatul trebuie sa dea rest unde aplic din nou greedy
	if (total > produs.getPret()) {
		while (total - produs.getPret() > totalRest && !(baniTonomat == Bani())) {
			if (baniTonomat.unLeu > 0)
			{
				copieBaniClient.unLeu++;
				rest.unLeu++;
				baniTonomat.unLeu--;
				totalRest += 1;
			}
			
			else if (baniTonomat.cinciLei > 0)
			{
				copieBaniClient.cinciLei++;
				rest.cinciLei++;
				baniTonomat.cinciLei--;
				totalRest += 5;
			}

			else if (baniTonomat.zeceLei > 0)
			{
				copieBaniClient.zeceLei++;
				rest.zeceLei++;
				baniTonomat.zeceLei--;
				totalRest += 10;
			}
			
			else if (baniTonomat.cincizeciLei > 0)
			{
				copieBaniClient.cincizeciLei++;
				rest.cincizeciLei++;
				baniTonomat.cincizeciLei--;
				totalRest += 50;
			}

			else
			{
				break;
			}
		}
	}
	// Tonomatul are rest sa dea clientului
	if (totalRest == total - produs.getPret()) {
		baniClient = copieBaniClient;
		this->tonomat.setBani(baniTonomat);
		return rest;
	}
	// Tonomatul nu are rest sa dea clientului, operatia nu se poate efectua
	else {
		rest.unLeu = -1;
		return rest;
	}
}
