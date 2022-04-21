#include <iostream>
#include "Tests.h"
#include "UI.h"

int main() {
	Test* testProdus = new TestProdus;
	Test* testTonomat = new TestTonomat;
	Test* testService = new TestService;
	testProdus->RunAllTests();
	testTonomat->RunAllTests();
	testService->RunAllTests();
	delete testProdus;
	delete testTonomat;
	delete testService;

	UI ui = UI();
	ui.run();


	return 0;
}