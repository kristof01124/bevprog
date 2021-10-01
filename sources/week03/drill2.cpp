#include "../include/std_lib_facilities.h"

struct value {
	double number;
	std::string unit;
	bool convertTo(const std::string& newUnit) {
		return set(number * convert(unit,newUnit), newUnit);
	}
	bool set(const double& newNumber, const std::string& newUnit) {
		if (incMeters(newUnit) == -1)
			return false;
		number = newNumber;
		unit = newUnit;
		return true;
	}
	bool operator < (const value& other) {
		return number < other.number;
	}
private:
	double convert(const std::string& a, const std::string& b) {
		return incMeters(a)/incMeters(b);
	}
	double incMeters(const std::string& unit) {
		if (unit == "cm")
			return 1;
		if (unit == "m")
			return 100;
		if (unit == "in")
			return 2.54;
		if (unit == "ft")
			return 2.54*12;
		return -1;
	}
};

int main() {
	value mini, maxi, szum;
	bool first = true;
	vector<value> values;
	while (cin>>num>>unit) {
		double num;
		std::string unit;
		value temp;
		if (!temp.set(num,unit)) {
			std::cout<<"Wrong unit type!"<<std::endl;
			continue;
		}
		temp.convertTo("m");
		values.push_back(temp);
		if (first) {
			mini = temp;
			maxi = temp;
			szum = temp;
			first = false;
			continue;
		}
		if (mini.number > temp.number)
			mini = temp;
		if (maxi.number < temp.number)
			maxi = temp;
		szum.number += temp.number;
	}
	std::sort(values.begin(), values.end());
	std::cout<<"The smallest one is "<<mini.number<<" m."<<std::endl;
	std::cout<<"The largest one is "<<maxi.number<<" m."<<std::endl;
	std::cout<<"The sum is "<<szum.number<<" m."<<std::endl;
	for (value i:values)
		std::cout<<i.number<<" m."<<std::endl;
}
