#include "RainfallData.h"

RainfallData::RainfallData()
{
	this->month = "";
	this->rainfall = 0;

}

RainfallData::RainfallData(std::string month, double rainfall)
{
	this->month = month;
	this->rainfall = rainfall;

}

std::string RainfallData::getMonth()
{
	return this->month;
}

void RainfallData::setMonth(std::string month)
{
	this->month = month;
}

double RainfallData::getRainfall()
{
	return this->rainfall;
}

void RainfallData::setRainFall(double rainfall)
{
	this->rainfall = rainfall;
}

bool RainfallData::operator<(const RainfallData& otherMonth) const
{
	return this->rainfall < otherMonth.rainfall;
}

bool RainfallData::operator>(const RainfallData& otherMonth) const
{
	return this->rainfall > otherMonth.rainfall;;
}



std::ostream& operator<<(std::ostream& os, const RainfallData& rainfallData)
{
	os << "Month: " << rainfallData.month << "   Rainfall: " << rainfallData.rainfall << " inches";
	return os;
}
