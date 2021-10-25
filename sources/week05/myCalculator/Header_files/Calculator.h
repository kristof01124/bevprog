#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include "..\Header_files\exception.h"

enum Type {Number, Function, Expression, Operator, Variable, None};

//everything is an element
class element {
	Type m_type = Number;
	std::string m_expr;
	bool m_solved = false;
	int m_pres;
	std::vector<double> m_value = { 0 };
public:
	double (*m_func)(const std::vector<double>&, const std::vector<double>&) = NULL;
	element();
	element(Type type, const double& value);
	element(Type type, const std::string& expr);
	element(Type type, const std::string& expr, double(* func)(const std::vector<double>&, const std::vector<double>&), int pres);
	void solve(element& left,element& right);
	void solve();
	std::vector<double>& value();
	std::string& expr();
	Type& type();
	int& pres();
	void setFunc(double(*func)(const std::vector<double>&, const std::vector<double>&));
	bool solved();
};

class Calculator {
	static std::unordered_map<std::string, element> m_operators;
	static std::unordered_map<std::string, element> m_functions;
	static std::unordered_map<std::string, element> m_constants;
	std::vector<element> m_elements;
public:
	Calculator();
	std::vector<double> solve(const std::string& s);
	void setDefault();
	void breakDown(const std::string& s);
	void handleOperators();
	void handleNumbers();
	void handleFunctions();
	void printElements();
	// void printOperators();
	// void printFunctions();

	Type find(const std::string& s);
	element getVariable(const std::string& s);
	bool findVariable(const std::string& s);
	element getOperator(const std::string& s);
	bool findOperator(const std::string& s);
	element getFunction(const std::string& s);
	bool findFunction(const std::string& s);

	static bool is_a_number(const char& c);
	static double to_int(const std::string& s);
};
