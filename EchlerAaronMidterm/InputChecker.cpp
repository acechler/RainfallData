#include "InputChecker.h"

bool InputChecker::checkForDigits(std::string& input, bool& hasDigits)
{
	// Check for numeric characters in input
	for (int i = 0; i < input.size(); i++) {
		hasDigits = std::isdigit(input[i]);
		if (hasDigits)
			i = input.size();
	}
	if (hasDigits == true) {
		std::cout << "Error, no numeric characters please.\n";
		return true;
	}
	else {
		return false;
	}
}

bool InputChecker::checkForAlphas(std::string& input, bool& hasAlphas)
{
	// Check for alphabetical characters in input
	for (int i = 0; i < input.size(); i++) {
		hasAlphas = std::isalpha(input[i]);
		if (hasAlphas)
			i = input.size();
	}
	if (hasAlphas == true) {
		std::cout << "Error, no alphabetical characters please.\n";
		return true;
	}
	else {
		return false;
	}
}

bool InputChecker::check(std::string& input, bool findDigits, bool findAlphas)
{
	bool hasDigits = false;
	bool hasAlphas = false;
	bool isEmpty   = false;


	if (input.empty()) {
		std::cout << "Error, input is empty.\n";
		isEmpty = true;
		return isEmpty;
	}
	else {

		if (findDigits) {
			hasDigits = checkForDigits(input, hasDigits);
			return hasDigits;
		}
		if (findAlphas) {
			hasAlphas = checkForAlphas(input, hasAlphas);
			return hasAlphas;
		}
	}
}




void InputChecker::demo()
{
	std::string input;
	bool inputFlag = true;

	InputChecker inputChecker;

	while (inputFlag) {
		std::cout << "Please, enter your full input: ";
		std::getline(std::cin, input);
		inputFlag = inputChecker.check(input, true, false);
	}
}
