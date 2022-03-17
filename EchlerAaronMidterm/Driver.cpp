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


/// <summary>
///  Displays the main menu for the user.
/// </summary>
void displayMainMenuCLI() {

	std::cout << "Enter your choice\n"
		<< "A -- Add a month of statistics\n"
		<< "E -- Edit a month of statistics\n"
		<< "P -- Print report\n"
		<< "Q -- Quit \n"
		<< "\nChoice : ";
}


/// <summary>
///		This is the Add Month menu and handles user input.
///	 This adds month data and rainfall data to the list.	
/// 
/// </summary>
/// <param name="input"> holds the input of the user. </param>
/// <param name="inputChecker"> Utility to check if the users input is valid. </param>
void displayAddMonthCLI(std::string& input, InputChecker& inputChecker) {
	bool inputFlag = true;
	while (inputFlag) {
		std::cout << "Enter Month : ";
		std::getline(std::cin, input);
		inputFlag = inputChecker.check(input, true, false);
	}

	inputFlag = true;
	while (inputFlag) {
		std::cout << "Enter Rainfall(in Inches) : ";
		std::getline(std::cin, input);
		inputFlag = inputChecker.check(input, false, true);
	}
}


/// <summary>
///		This is the Edit Month menu and it handles user input,
///	 allows a user to edit an existing month. 
/// 
/// </summary>
/// <param name="input"> holds the input of the user. </param>
/// <param name="inputChecker"> Utility to check if the users input is valid. </param>
void displayEditMenuCLI(std::string& input, InputChecker& inputChecker) {
	bool inputFlag = true;
	while (inputFlag) {
		std::cout << "Enter Month : ";
		std::getline(std::cin, input);
		inputFlag = inputChecker.check(input, true, false);
		//ERROR: Invalid Month Check if month exists in the list
	}

	inputFlag = true;
	while (inputFlag) {
		std::cout << "Enter Rainfall(in Inches) : ";
		std::getline(std::cin, input);
		inputFlag = inputChecker.check(input, false, true);
	}	
}

/// <summary>
///		Displays rainfall data.
/// </summary>
void displayRainfallReportCLI() {
	std::cout << "Total Rainfall: 66 inches \n";
	
	std::cout << "Average Rainfall : 33 inches \n";

	std::cout << "Most Rainfall : Jan had 42 inches \n";

	std::cout << "Least Rainfall : Feb had 24 inches \n";
}

int main() {

	bool program = true; 
	bool mainMenu = true;
	bool addMonth = false;
	bool editMonth = false;
	bool printReport = false;
	std::string input;
	bool inputFlag = true;

	InputChecker inputChecker;

	while (program) {

		while (mainMenu) {

			// Check if the user input is valid
			bool inputFlag = true;
			while (inputFlag) {
				displayMainMenuCLI();
				std::getline(std::cin, input);
				inputFlag = inputChecker.check(input, true, false);
			}

			// Traverse Menu depending on results of the users input.
			if (input == "a" || input == "A") { addMonth    = true;     mainMenu = false; }  ///< User selects add month menu.
			if (input == "e" || input == "E") { editMonth   = true;     mainMenu = false; }  ///< User selects edit month menu.
			if (input == "p" || input == "P") { printReport = true;     mainMenu = false; }  ///< User selects print report menu.
			if (input == "q" || input == "Q") { program     = false;    mainMenu = false; }  ///< User selects Quit.
			
		}

		while (addMonth) {
			displayAddMonthCLI(input, inputChecker);
			addMonth = false;
			mainMenu = true;
			
		}

		while (editMonth) {
			std::cout << "Edit Month\n";
			editMonth = false;
			mainMenu = true;
			
		}
		while (printReport) {
			std::cout << "Print Report\n";
			printReport = false;
			mainMenu = true;
		}
	}
	std::cin.ignore();
	return 0;
}