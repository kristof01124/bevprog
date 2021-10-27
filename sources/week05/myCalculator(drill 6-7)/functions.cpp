#include "Header_files/Functions.h"

double Functions::sqrt(const std::vector<double>& left, const std::vector<double>& right)
{
	if (right.size() != 1)
		throw "Bad expression";
	return ::sqrt(right[0]);
}

double Functions::sin(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw "Bad expression";
	return ::sin(right[0]);
}

double Functions::cos(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw "Bad expression";
	return ::cos(right[0]);
}

double Functions::tan(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw "Bad expression";
	return ::tan(right[0]);
}

double Functions::asin(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw "Bad expression";
	return ::asin(right[0]);
}

double Functions::acos(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw "Bad expression";
	return ::acos(right[0]);
}

double Functions::atan(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw "Bad expression";
	return ::atan(right[0]);
}

double Functions::pow(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 2)
		throw "Bad expression";
	return ::pow(right[0], right[1]);
}

double Functions::log(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 2)
		throw "Bad expression";
	return  ::log(right[1])/::log(right[0]);
}
