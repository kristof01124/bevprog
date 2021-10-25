#include "Header_files/Calculator.h"
#include <iostream>



/*
Stuff that works:
var = 10
var *= 10
sqrt(2pi)
tan(e)
*/

int main() {
	Calculator c;
	c.solve("0");
	std::string s;
	double lastAns;
	std::cout << "Welcome to our simple calculator. Please enter expressions using floating - point numbers." << std::endl;
	std::cout << "Known operators: +, -, %, /, *, div(whole division), mod(mdodulo)" << std::endl;
	std::cout << "Known functions: sin, asin, cos, acos, tan, atan, sqr or sqrt, pow, log" << std::endl;
	std::cout << "Built-in constants: pi, e, ans" << std::endl;
	std::cout << "Variable operations: =, (Operator)= etc. *=" << std::endl;
	std::cout << "You can quit by typing q, x or quit." << std::endl;
	while (true) {
		try {
			lastAns = c.solve("ans")[0];
			std::cout << ">>";
			std::getline(std::cin, s);
			if (s.find("quit") != std::string::npos || s == "x" || s=="q")
				break;
			std::vector<double> sol = c.solve(s);
			if (sol.size() > 1)
				throw exception("Bad expression!");
			if (sol.size() == 1)
				std::cout << sol[0] <<std::endl;
		}
		catch (exception e) {
			std::cout << e.what() << std::endl;
			c.solve(std::to_string(lastAns));
		}
	}
}
