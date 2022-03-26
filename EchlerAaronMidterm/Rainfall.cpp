#include "Rainfall.h"

void Rainfall::displayCurrentEntries()
{
	std::cout << "--- Current Entries ---\n";
	for (int i = 0; i < rainfallListPtr->getLength(); i++) {
		std::cout << rainfallListPtr->getEntry(i) << std::endl;
	}


}

double Rainfall::calcTotalRainfall()
{

	double total = 0;
	for (int i = 0; i < rainfallListPtr->getLength(); i++) {
		total += rainfallListPtr->getEntry(i).getRainfall();
	}

	return total;
}

double Rainfall::calcAverageRainfall()
{

	double total = calcTotalRainfall();
	double average = total / rainfallListPtr->getLength();

	return average;
}

RainfallData Rainfall::findLeastRainfall()
{
	RainfallData leastRainfall = rainfallListPtr->getEntry(0);
	for (int i = 0; i < rainfallListPtr->getLength(); i++) {
		if (leastRainfall > rainfallListPtr->getEntry(i)) {
			leastRainfall = rainfallListPtr->getEntry(i);
		}
	}
	return leastRainfall;
}

RainfallData Rainfall::findMostRainfall()
{
	RainfallData mostRainfall = rainfallListPtr->getEntry(0);;
	for (int i = 0; i < rainfallListPtr->getLength(); i++) {
		if (mostRainfall < rainfallListPtr->getEntry(i)) {
			mostRainfall = rainfallListPtr->getEntry(i);
		}
	}
	return mostRainfall;
}

Rainfall::Rainfall()
{
	rainfallListPtr = new LinkedList<RainfallData>();
}

void Rainfall::displayMainMenuCLI()
{
	std::cout << "Enter your choice\n"
		<< "A -- Add a month of statistics\n"
		<< "E -- Edit a month of statistics\n"
		<< "P -- Print report\n"
		<< "Q -- Quit \n"
		<< "\nChoice : ";
}

void Rainfall::displayAddMonthCLI(std::string& input, InputChecker& inputChecker)
{
	bool inputFlag = true;
	// Have user enter the month, checks to make sure that the input characters are valid.
	while (inputFlag) {
		std::cout << "Enter Month : ";
		std::getline(std::cin, input);
		inputFlag = inputChecker.check(input, true, false);
	}
	std::string month = input;
	inputFlag = true;
	// Have user enter the rainfall amount, check to make sure the input characters are valid.
	while (inputFlag) {
		std::cout << "Enter Rainfall(in Inches) : ";
		std::getline(std::cin, input);
		inputFlag = inputChecker.check(input, false, true);
	}

	// Add users entry into the rainfall linked list
	double rain = std::stod(input);
	RainfallData container(month, rain);
	int listSize = rainfallListPtr->getLength();
	rainfallListPtr->insert(listSize, container);

}

void Rainfall::displayEditMenuCLI(std::string& input, InputChecker& inputChecker)
{
	bool inputFlag = true;
	bool foundEntry = false;
	int entriesIndex = 0;
	std::string month = "";
	displayCurrentEntries();

	// Have the user enter a month they want to edit.
	while (inputFlag) {
		std::cout << "Enter Month : ";
		std::getline(std::cin, input);
		inputFlag = inputChecker.check(input, true, false);
	}
	// Find the location of the month in the list.
	for (int i = 0; i < rainfallListPtr->getLength(); i++) {
		if (rainfallListPtr->getEntry(i).getMonth() == input) {
			foundEntry = true;
			entriesIndex = i;
			month = rainfallListPtr->getEntry(i).getMonth();
		}
	}
	// Have the user change their data from the target month.
	if (foundEntry) {
		inputFlag = true;
		while (inputFlag) {
			std::cout << "Enter Rainfall(in Inches) : ";
			std::getline(std::cin, input);
			inputFlag = inputChecker.check(input, false, true);
		}
		double rain = std::stod(input);
		RainfallData container(month, rain);
		rainfallListPtr->replace(entriesIndex, container);
	}
	else {
		std::cout << "Error, entry not found.\n";
	}

}

void Rainfall::displayRainfallReportCLI()
{
	double totalRainfall = calcTotalRainfall();
	double averageRainfall = calcAverageRainfall();
	RainfallData mostRainfall = findMostRainfall();
	RainfallData leastRainfall = findLeastRainfall();

	displayCurrentEntries();
	std::cout << "\n\n";

	std::cout << "Total Rainfall : " << totalRainfall << "\n";
	std::cout << "Average Rainfall : " << averageRainfall << "\n";
	std::cout << "Most Rainfall : " << mostRainfall << "\n";
	std::cout << "Least Rainfall : " << leastRainfall << "\n";
	std::cout << "\n\n";

}

void Rainfall::run()
{
	bool program = true;
	bool mainMenu = true;
	bool addMonth = false;
	bool editMonth = false;
	bool printReport = false;
	std::string input;
	bool inputFlag = true;

	InputChecker inputChecker;

	// The main loop of the program
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
			if (input == "a" || input == "A") { addMonth = true;     mainMenu = false; }  ///< User selects add month menu.
			if (input == "e" || input == "E") { editMonth = true;     mainMenu = false; }  ///< User selects edit month menu.
			if (input == "p" || input == "P") { printReport = true;     mainMenu = false; }  ///< User selects print report menu.
			if (input == "q" || input == "Q") { program = false;    mainMenu = false; }  ///< User selects Quit.

		}

		while (addMonth) {
			displayAddMonthCLI(input, inputChecker);
			addMonth = false;
			mainMenu = true;

		}

		while (editMonth) {
			displayEditMenuCLI(input, inputChecker);
			editMonth = false;
			mainMenu = true;

		}
		while (printReport) {
			displayRainfallReportCLI();
			printReport = false;
			mainMenu = true;
		}
	}
}

