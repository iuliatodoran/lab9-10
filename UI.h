#pragma once
#include <iostream>
#include <iomanip>
#include "Service.h"
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::setw;

class UI {
public:
	// Constructors
	UI();
	UI(const Service& other);

	void run();

private:
	Service SimulareTonomat;
};