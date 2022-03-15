#pragma once
#include <iostream>
#include <string>
class InputChecker {
private:
	bool checkForDigits(std::string& input, bool& hasDigits);

	bool checkForAlphas(std::string& input, bool& hasAlphas);
public:
	InputChecker() {};
	bool check(std::string& input, bool findDigits = false, bool findAlphas = false);

	// Demonstration on how to use object
	void demo();

};