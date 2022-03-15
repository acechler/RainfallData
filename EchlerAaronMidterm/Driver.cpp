/*
	Rainfall Statistics Class
	Create a class to hold Rainfall Statistics.  This class will be a LinkedList.

	The program will ask the user to enter the number of months to be saved.  Your driver program will show the following menu items:

	A -- Add a month of statistics
	E -- Edit a month of statistics
	P -- Print report
	Q -- Quit

	The A option will prompt a user to enter a month and the amount of rainfall during the month.
	The E option will prompt a user to override the amount of rainfall for a given month (also supplied by the user).
	The P option will print a report with the following information:
		Total amount of rain
		The average amount of rain
		The month(s) with the highest amount of rain
		The month(s) with the lowest amount of rain

	An example run would be:

	Enter your choice

	A -- Add a month of statistics
	E -- Edit a month of statistics
	P -- Print report
	Q -- Quit

	Choice: A

	Enter Month: Jan
	Enter Rainfall (in Inches): 42

	Enter your choice

	A -- Add a month of statistics
	E -- Edit a month of statistics
	P -- Print report
	Q -- Quit

	Choice: A

	Enter Month: Feb

	Enter Rainfall (In Inches): 23

	Enter your choice

	A -- Add a month of statistics
	E -- Edit a month of statistics
	P -- Print report
	Q -- Quit

	Choice: E

	Enter Month: Mar
	ERROR: Invalid Month
	Enter Month: Feb
	Enter Rainfall (In Inches): 24

	Enter your choice

	A -- Add a month of statistics
	E -- Edit a month of statistics
	P -- Print report
	Q -- Quit

	Choice: P

	Total Rainfall: 66 inches

	Average Rainfall: 33 inches

	Most Rainfall: Jan had 42 inches

	Least Rainfall: Feb had 24 inches

	Enter your choice

	A -- Add a month of statistics
	E -- Edit a month of statistics
	P -- Print report
	Q -- Quit

	Choice: Q



	The program will have the following:

	Driver.cpp -- Contains the main and any unique subroutines.
	Rainfall.h -- Contains the header information for the Rainfall class
	Rainfall.cpp -- Contains the implementation of the Rainfall class
	List.h -- Contains the header information for your linked list class.
	List.cpp -- Contains the implementation

	Implement:

	ListInterface.h in Listing 8-1 on pp. 261-262.
	Node.h
	PrecondViolatedExcept.h
	LinkedList.h in Listing 9-2 on p. 273-274.

*/

#include "InputChecker.h"

void displayCLI() {

	std::cout << " Enter your choice\n"
		<< "A -- Add a month of statistics\n"
		<< "E -- Edit a month of statistics\n"
		<< "P -- Print report\n"
		<< "Q -- Quit \n"
		<< "\nChoice : ";
}




int main() {

	bool prog = true;
	bool addMonth = false;
	bool editMonth = false;
	bool printReport = false;
	std::string input;
	bool inputFlag = true;

	InputChecker inputChecker;

	while (inputFlag) {
		displayCLI();
		std::getline(std::cin, input);
		inputFlag = inputChecker.check(input, true, false);
	}
	// Traverse Menu depending on results of the users input.
	if		(input == "a" || input == "A") { std::cout << "Add a month of statistics\n"; }
	else if (input == "e" || input == "E") { std::cout << "Edit a month of statistics\n"; }
	else if (input == "p" || input == "P") { std::cout << "Print report\n"; }
	else if (input == "q" || input == "Q") { std::cout << "Quit\n"; }
	else{ std::cout << "Error invalid input.\n"; }

	std::cin.ignore();
	return 0;
}