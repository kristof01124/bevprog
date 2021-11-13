#pragma once
#include <vector>
#include <cmath>

namespace Functions {
	double sqrt(const std::vector<double>& left, const std::vector<double>& right);
	double sin(const std::vector<double>& left, const std::vector<double>& right);
	double cos(const std::vector<double>& left, const std::vector<double>& right);
	double tan(const std::vector<double>& left, const std::vector<double>& right);
	double asin(const std::vector<double>& left, const std::vector<double>& right);
	double acos(const std::vector<double>& left, const std::vector<double>& right);
	double atan(const std::vector<double>& left, const std::vector<double>& right);
	double pow(const std::vector<double>& left, const std::vector<double>& right);
	double log(const std::vector<double>& left, const std::vector<double>& right);
}