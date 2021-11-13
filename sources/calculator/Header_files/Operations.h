#pragma once
#include <vector>
#include <cmath>

namespace operations {
	double addition(const std::vector<double>& left,const std::vector<double>& right);
	double subtraction(const std::vector<double>& left, const std::vector<double>& right);
	double multiplication(const std::vector<double>& left, const std::vector<double>& right);
	double division(const std::vector<double>& left, const std::vector<double>& right);
	double modulo(const std::vector<double>& left, const std::vector<double>& right);
	double intDivision(const std::vector<double>& left, const std::vector<double>& right);
	double power(const std::vector<double>& left, const std::vector<double>& right);
}
