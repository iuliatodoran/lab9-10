#pragma once
#include "Produs.h"
#include "Tonomat.h"
#include "Service.h"
#include <cassert>
#include <iostream>

class Test {
public:
	virtual void RunAllTests() = 0;
};

class TestProdus : public Test {
public:
	void RunAllTests();
	int creationTest();
	int gettersSettersTest();
	int operatorsTest();
};

class TestTonomat : public Test {
public:
	void RunAllTests();
	int creationTest();
	int gettersSettersTest();
	int operationTest();
};

class TestService : public Test {
public:
	void RunAllTests();
	int creationTest();
	int gettersSettersTest();
	int operationsTest();
};