// EchlerAaronMidterm : 
// 
// Name: Aaron Echler
// Course Section (CIS 2207 N01)
// Date: 3/14/22
// 
//      Description: The core of the application, this is where the user will traverse through different states of the program. 
//  




#ifndef _RAINFALL_H
#define _RAINFALL_H
#include <string>

#include "LinkedList.h"
#include "InputChecker.h"
#include "RainfallData.h"


class Rainfall
{
private:

	/// <summary>
	///		List Interface to hold the rainfall data.
	/// </summary>
	ListInterface<RainfallData>* rainfallListPtr;
	
	/// <summary>
	///		Utility Method that iterates through linked list
	/// </summary>
	void displayCurrentEntries();

	/// <summary>
	///		Calculates the total rainfall from the rainfall linked list
	/// </summary>
	/// <returns> Total Rainfall </returns>
	double calcTotalRainfall();
	
	/// <summary>
	///		Calculates the average from the rainfall linked list 
	/// </summary>
	/// <returns></returns>
	double calcAverageRainfall();
	
	/// <summary>
	///		Finds month with the list rainfall
	/// </summary>
	/// <returns> Month with the least rainfall</returns>
	RainfallData findLeastRainfall();

	/// <summary>
	///		Finds the month with the most rainfall.
	/// </summary>
	/// <returns> Month with the first rainfall </returns>
	RainfallData findMostRainfall();

public:
	// Constructor //
	Rainfall();


	// PROGRAM MENU DISPLAYS //
	/// <summary>
	///		Displays the main menu for the user.
	/// </summary>
	void displayMainMenuCLI();

	/// <summary>
	/// 
	///		This is the Add Month menu and handles user input.
	///	 This adds month data and rainfall data to the list.	
	/// 
	/// </summary>
	/// <param name="input"> holds the input of the user. </param>
	/// <param name="inputChecker"> Utility to check if the users input is valid. </param>
	void displayAddMonthCLI(std::string& input, InputChecker& inputChecker);

	/// <summary>
	/// 
	///		This is the Edit Month menu and it handles user input,
	///	 allows a user to edit an existing month. 
	/// 
	/// </summary>
	/// <param name="input"> holds the input of the user. </param>
	/// <param name="inputChecker"> Utility to check if the users input is valid. </param>
	void displayEditMenuCLI(std::string& input, InputChecker& inputChecker);

	/// <summary>
	///		Displays rainfall data.
	/// </summary>
	void displayRainfallReportCLI();

	/// <summary>
	///  The program states.
	/// </summary>
	void run();

	// Destructor //
	~Rainfall(){
		delete rainfallListPtr;
		
	}
};
#endif

