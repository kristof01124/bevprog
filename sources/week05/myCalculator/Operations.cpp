#include "Header_files/Operations.h"
#include "Header_files/exception.h"

double operations::addition(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw exception("Bad expression");
	return left[0] + right[0];
}

double operations::subtraction(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw exception("Bad expression");
	return left[0] - right[0];
}

double operations::multiplication(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw exception("Bad expression");
	return left[0] * right[0];
}

double operations::division(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw exception("Bad expression");
	return left[0] / right[0];
}

double operations::modulo(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw exception("Bad expression");
	return fmod(left[0], right[0]);
}

double operations::intDivision(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw exception("Bad expression");
	return long(left[0] / right[0]);
}

double operations::power(const std::vector<double>& left, const std::vector<double>& right)
{
	if (left.size() != 1 || right.size() != 1)
		throw exception("Bad expression");
	return ::pow(left[0], right[0]);
}

