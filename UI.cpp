#include "UI.h"

UI::UI()
{
	SimulareTonomat = Service();
}

UI::UI(const Service& other)
{
	SimulareTonomat = other;
}

void UI::run()
{
	bool running = true;
	string key;

	SimulareTonomat.addBaniTonomat(Bani(10, 10, 10, 10));
	SimulareTonomat.addItem(Produs(1, "suc", 3));

	cout << setw(5) << "Simulator Tonomat" << '\n';

	while (running) {
		cout << setw(10) << "Modificare tonomat (M/m)" << '\n' << "Optiuni client (C/c)" << '\n' <<
			"Iesire aplicatie (Q/q)" << '\n';

		cout << setw(5) << "Asteptare input...";
		cin >> key;

		if (key == "M" || key == "m") {
			cout << setw(10) << "Adaugati un produs nou (A/a)" << '\n' << "Adaugati bani in tonomat (AM/am)" << '\n' <<
				"Afisare bani tonomat (B/b)" << '\n';

			cout << setw(5) << "Asteptare input...";
			cin >> key;

			int cod;
			string nume;
			int pret;

			if (key == "A" || key == "a") {
				cout << setw(10) << "Introduceti codul produsului: " << '\n'; cin >> cod;
				cout << setw(10) << "Introduceti numele produsului: " << '\n'; cin >> nume;
				cout << setw(10) << "Introduceti pretul produsului: " << '\n'; cin >> pret;

				this->SimulareTonomat.addItem(Produs(cod, nume, pret));

				cout << setw(10) << "Produsul a fost adaugat cu succes!" << '\n';
			}

			if (key == "AM" || key == "am") {
				cout << setw(10) << "Introduceti tipul banilor: 1 = un leu, 5 = cinci lei, 10 = zece lei, 50 = cincizeci de lei" << '\n';
				cin >> key;

				if (key == "1")
					SimulareTonomat.addBaniTonomat(Bani(1, 0, 0, 0));
				else if (key == "5")
					SimulareTonomat.addBaniTonomat(Bani(0, 1, 0, 0));
				else if (key == "10")
					SimulareTonomat.addBaniTonomat(Bani(0, 0, 1, 0));
				else if (key == "50")
					SimulareTonomat.addBaniTonomat(Bani(0, 0, 0, 1));
				else
					cout << setw(5) << "Operatie nereusita, nu ati introdus o valoare valida" << '\n';
			}

			if (key == "B" || key == "b")
				cout << setw(5) << "Total bani tonomat: " << SimulareTonomat.getTonomat().getBani().getTotal() << '\n';
		}

		if (key == "C" || key == "c") {
			cout << setw(10) << "Afisare produse (A/a)" << '\n' << "Adaugare bancnote (B/b)" << '\n' << "Cumparati produs (C/c)" << '\n' <<
				"Afisare bani introdusi (V/v)" << '\n';

			cin >> key;

			vector<Produs> toateProdusele = SimulareTonomat.getAll();

			if (key == "A" || key == "a") {
				for (vector<Produs>::iterator it = toateProdusele.begin(); it != toateProdusele.end(); it++) {
					cout << *it;
				}
			}

			else if (key == "B" || key == "b") {
				cout << setw(10) << "Introduceti bancnota: un leu = 1, cinci lei = 5, zece lei = 10, cincizeci de lei = 50" << '\n';
				cin >> key;

				if (key == "1")
					SimulareTonomat.setBaniClient(SimulareTonomat.getBaniClient() + Bani(1, 0, 0, 0));
				else if (key == "5")
					SimulareTonomat.setBaniClient(SimulareTonomat.getBaniClient() + Bani(0, 1, 0, 0));
				else if (key == "10")
					SimulareTonomat.setBaniClient(SimulareTonomat.getBaniClient() + Bani(0, 0, 1, 0));
				else if (key == "50")
					SimulareTonomat.setBaniClient(SimulareTonomat.getBaniClient() + Bani(0, 0, 0, 1));
				else {
					cout << "Valoare invalida!" << '\n';
					break;
				}
				cout << "Bancnota introdusa cu succes!" << '\n';
			}

			else if (key == "C" || key == "c") {
				int cod;
				cout << setw(10) << "Introduceti codul produsului" << '\n';
				cin >> cod;

				bool cumparat = SimulareTonomat.buyProdus(1);

				if (cumparat)
					cout << setw(5) << "Produs cumparat cu succes!" << '\n';
				else
					cout << setw(5) << "Tranzactie esuata! (cod gresit sau bancnote insuficiente)" << '\n';

			}

			else if (key == "V" || key == "v") {
				cout << "Valoare introdusa: " << SimulareTonomat.getBaniClient().getTotal() << '\n';
			}

			else cout << "Valoare invalida!" << '\n';
		}

		if (key == "Q" || key == "q")
			running = false;
	}
}
