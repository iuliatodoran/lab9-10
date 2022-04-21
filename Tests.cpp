#include "Tests.h"

void TestProdus::RunAllTests()
{
	creationTest();
	gettersSettersTest();
	operatorsTest();
}

int TestProdus::creationTest()
{
	Produs produs = Produs();
	
	assert(produs.getCod() == -1);
	assert(produs.getNume() == "none");
	assert(produs.getPret() == 0);

	Produs produs2 = Produs(2, "ciocolata", 5);

	assert(produs2.getCod() == 2);
	assert(produs2.getNume() == "ciocolata");
	assert(produs2.getPret() == 5);

	Produs produs3 = produs2;

	assert(produs3.getCod() == 2);
	assert(produs3.getNume() == "ciocolata");
	assert(produs3.getPret() == 5);

	return 0;
}

int TestProdus::gettersSettersTest()
{
	Produs produs = Produs(1, "suc", 3);

	assert(produs.getCod() == 1);
	assert(produs.getNume() == "suc");
	assert(produs.getPret() == 3);

	produs.setCod(3);
	assert(produs.getCod() == 3);

	produs.setNume("croissant");
	assert(produs.getNume() == "croissant");
	
	produs.setPret(2);
	assert(produs.getPret() == 2);

	return 0;
}

int TestProdus::operatorsTest()
{
	Produs produs;
	produs = Produs(1, "suc", 3);

	assert(produs.getCod() == 1);
	assert(produs.getNume() == "suc");
	assert(produs.getPret() == 3);

	return 0;
}

void TestTonomat::RunAllTests()
{
	creationTest();
	gettersSettersTest();
}

int TestTonomat::creationTest()
{
	Tonomat tonomat;
	assert(tonomat.getAll().size() == 0);

	return 0;
}

int TestTonomat::gettersSettersTest()
{
	Tonomat tonomat = Tonomat();

	vector<Produs> produse;

	produse.push_back(Produs(1, "suc", 2));
	produse.push_back(Produs(2, "croissant", 3));

	assert(tonomat.getAll().size() == 0);
	tonomat.setAll(produse);
	assert(tonomat.getAll().size() == 2);
	assert(tonomat.getAll()[0] == Produs(1, "suc", 2));
	assert(tonomat.getAll()[1] == Produs(2, "croissant", 3));


	return 0;
}

int TestTonomat::operationTest()
{
	Tonomat tonomat = Tonomat();

	tonomat.addItem(Produs(1, "suc", 2));
	assert(tonomat.getAll().size() == 1);
	assert(tonomat.getAll()[0] == Produs(1, "suc", 2));

	return 0;
}

void TestService::RunAllTests()
{
	creationTest();
	gettersSettersTest();
	operationsTest();
}

int TestService::creationTest()
{
	Tonomat tonomat = Tonomat();
	Bani baniClient = Bani(1, 1, 1, 1);

	Service service = Service(tonomat, baniClient);

	assert(service.getBaniClient() == baniClient);
	assert(service.getTonomat() == tonomat);

	return 0;
}

int TestService::gettersSettersTest()
{
	Tonomat tonomat = Tonomat();
	Bani baniClient = Bani(1, 2, 3, 4);

	Service service = Service(tonomat, baniClient);

	assert(service.getBaniClient() == baniClient);
	assert(service.getTonomat() == tonomat);

	service.setBaniClient(baniClient + Bani(1, 1, 1, 1));
	
	Bani rezultat = Bani(2, 3, 4, 5);

	assert(service.getBaniClient() == rezultat);

	return 0;
}

int TestService::operationsTest()
{
	Tonomat tonomat = Tonomat();
	tonomat.addItem(Produs(1, "suc", 3));
	
	Bani baniClient = Bani(3, 0, 0, 0);
	
	Service service = Service(tonomat, baniClient);

	bool cumparat;
	
	cumparat = service.buyProdus(1);

	assert(cumparat == true);
	assert(service.getTonomat().getBani() == Bani(3, 0, 0, 0));
	assert(service.getBaniClient() == Bani(0, 0, 0, 0));

	service.setBaniClient(Bani(0, 1, 0, 0));

	cumparat = service.buyProdus(1);
	assert(cumparat == true);
	assert(service.getTonomat().getBani() == Bani(1, 1, 0, 0));
	assert(service.getBaniClient() == Bani(2, 0, 0, 0));

	service.setBaniClient(Bani(3, 5, 10, 5));

	cumparat = service.buyProdus(1);
	assert(cumparat == true);
	assert(service.getTonomat().getBani() == Bani(4, 1, 0, 0));
	assert(service.getBaniClient() == Bani(0, 5, 10, 5));

	cumparat = service.buyProdus(1);
	
	assert(cumparat == true);
	assert(service.getTonomat().getBani() == Bani(2, 2, 0, 0));
	assert(service.getBaniClient() == Bani(2, 4, 10, 5));

	cumparat = service.buyProdus(1);

	assert(cumparat == true);
	assert(service.getTonomat().getBani() == Bani(0, 3, 0, 0));
	assert(service.getBaniClient() == Bani(4, 3, 10, 5));

	return 0;
}
