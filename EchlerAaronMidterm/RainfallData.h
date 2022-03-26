// EchlerAaronMidterm : 
// 
// Name: Aaron Echler
// Course Section (CIS 2207 N01)
// Date: 3/14/22
// 
//     Description: Contains all attributes for the rainfall data, This is to keep the data organized and easy to access and display.
//  



#ifndef _RAINFALL_DATA_H
#define _RAINFALL_DATA_H

#include <iostream>
#include <string>

/// <summary>
///		Class that acts as a container to hold a month and the amount of rainfall.
/// </summary>
class RainfallData
{
	/// <summary>
	///		Allows the properties of this class to be easily display in the output stream.
	/// </summary>
	/// <param name="os"> The output stream</param>
	/// <param name="rainfallData"> The reference of the class to be displayed in the stream.</param>
	/// <returns> class properties in a streamed format. </returns>
	friend std::ostream& operator<<(std::ostream &os, const RainfallData& rainfallData);

private:
	std::string month;
	double rainfall;

public:
	RainfallData();
	RainfallData(std::string month, double rainfall);

	std::string getMonth();
	void setMonth(std::string month);

	double getRainfall();
	void setRainFall(double rainfall);

	/// <summary>
	///		The instructions for how this object handles the < comparison opererator.
	/// </summary>
	/// <param name="otherMonth"> The other month being compared</param>
	/// <returns> if the other months rainfall is greater than this month.</returns>
	bool operator<(const RainfallData& otherMonth) const;
	
	/// <summary>
	///		The instructions for how this object handles the > comparison opererator.
	/// </summary>
	/// <param name="otherMonth"> The other month being compared</param>
	/// <returns> if the other months rainfall is less than this month.</returns>
	bool operator>(const RainfallData& otherMonth) const;


};
#endif
