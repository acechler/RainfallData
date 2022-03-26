// EchlerAaronMidterm : 
// 
// Name: Aaron Echler
// Course Section (CIS 2207 N01)
// Date: 3/14/22
// 
//      Description: Utility class that checks the input for digit or alphabetical characters. This is used to prevent crashes when a bad input is provided.
//  



#ifndef _INPUT_CHECKER_H
#define _INPUT_CHECKER_H
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
#endif