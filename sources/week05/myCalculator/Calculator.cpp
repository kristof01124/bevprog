#include "Header_files/Operations.h"
#include "Header_files/Calculator.h"
#include "Header_files/Functions.h"

//default consturctor, sets m_value to 0, useful in eg. (-1)
element::element() {}

//for assigning variables
element::element(Type type, const double& value) {
	m_type = type;
	m_solved = true;
	m_value = {value};
}

//for general purpuse
element::element(Type type, const std::string& expr)
{
	m_type = type;
	m_expr = expr;
}

//for functions and operators
element::element(Type type, const std::string& expr, double(*func)(const std::vector<double>&, const std::vector<double>&), int pres)
{
	m_pres = pres;
	m_type = type;
	m_expr = expr;
	m_func = func;
}

//solves an element with information of sorroundings
void element::solve(element& left,element& right)
{
	if (m_solved)
		return;
	m_solved = true;
	if (m_type == Expression || m_type == Number || m_type == Variable) {
		solve();
		return;
	}
	if (m_type == Operator)
		left.solve();
	right.solve();
	m_value = std::vector<double>({ m_func(left.value(), right.value()) });

}

//solves an element without knowing the sorroundings
void element::solve()
{
	if (m_solved || m_type == Operator || m_type == Function) {
		if (!m_solved)
			throw exception("Tried to solve function or operator without valid parameters!");
			//shouldn't happen
		return;
	}
	m_solved = true;
	if (m_type == Variable) {
		m_value = std::vector<double>({ Calculator().getVariable(m_expr).value() });
		return;
	}
	if (m_type == Expression) {
		m_value = Calculator().solve(m_expr.substr(1, m_expr.size() - 2));
		return;
	}
	m_value = std::vector<double>({Calculator::to_int(m_expr)});
}

//------------------getters and setters-----------------------
std::vector<double>& element::value()
{
	return m_value;
}

std::string& element::expr()
{
	return m_expr;
}

Type& element::type()
{
	return m_type;
}

int& element::pres()
{
	return m_pres;
}

void element::setFunc(double(*func)(const std::vector<double>&, const std::vector<double>&))
{
	m_func = func;
}

bool element::solved()
{
	return m_solved;
}
//-----------------------------------------

Calculator::Calculator()
{
	if (!findVariable("pi")) {
		setDefault();
	}
}

std::unordered_map<std::string, element> Calculator::m_operators;
std::unordered_map<std::string, element> Calculator::m_constants;
std::unordered_map<std::string, element> Calculator::m_functions;

std::vector<double> Calculator::solve(const std::string& s)
{
	breakDown(s);
	//printElements();
	handleNumbers();
	handleFunctions();
	handleOperators();
	std::vector<double> out;
	for (element el : m_elements) {
		if (el.value().size() == 0)
			throw exception("Bad expression!");
		if (el.expr() != ",")
			out.push_back(el.value()[0]);
	}
	if (out.size() == 1)
		m_constants["ans"] = element(Number,out[0]);
	return out;
}

//setting up the base variables, operators and functions
void Calculator::setDefault()
{
	m_constants["pi"] = element(None, 3.14159265358);
	m_constants["e"] = element(None, 2.71828182845);

	m_operators["+"] = element(Operator, "+", operations::addition, 1);
	m_operators["-"] = element(Operator, "-", operations::subtraction, 1);
	m_operators["*"] = element(Operator, "*", operations::multiplication, 2);
	m_operators["/"] = element(Operator, "/", operations::division, 2);
	m_operators["%"] = element(Operator, "%", operations::modulo, 2);
	m_operators["mod"] = element(Operator, "%", operations::modulo, 2);
	m_operators["^"] = element(Operator, "^", operations::power, 3);
	m_operators["div"] = element(Operator, "div", operations::intDivision, 2);

	m_functions["sqrt"] = element(Function, "sqrt", Functions::sqrt, 0);
	m_functions["sqr"] = element(Function, "sqr", Functions::sqrt, 0);
	m_functions["sin"] = element(Function, "sin", Functions::sin, 0);
	m_functions["cos"] = element(Function, "cos", Functions::cos, 0);
	m_functions["tan"] = element(Function, "tan", Functions::tan, 0);
	m_functions["asin"] = element(Function, "asin", Functions::asin, 0);
	m_functions["acos"] = element(Function, "acos", Functions::acos, 0);
	m_functions["atan"] = element(Function, "atan", Functions::atan, 0);
	m_functions["pow"] = element(Function, "pow", Functions::pow, 0);
	m_functions["log"] = element(Function, "log", Functions::log, 0);
}

//breaks down the string to components
void Calculator::breakDown(const std::string& s)
{
	m_elements.clear();
	std::string currentWord;
	Type currentType = None;
	int depth = 0;
	int index = -1;
	for (char el : s) {
		index++;
		//special case for '='
		if (el == '=') {
			m_elements.clear();
			std::string name;
			int a = 0;
			while (s[a] == ' ')
				++a;
			std::string expr = '(' + s.substr(index + 1, s.size() - index - 1) + ')';
			index--;
			std::vector<double> sol;
			bool addName = false;
			//checks if there is an operator before the '='
			if (index < 0)
				throw exception("Illegal variable name!");
			if (findOperator(s.substr(index,1))) {
				addName = true;
				expr = s[index] + expr;
				index--;
			}
			while (s[index] == ' ' && index > 0)
				index--;
			for (int i = a; i <= index; ++i) {
				if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
					name += s[i];
				else
					throw exception("Illegal variable name!");
			}
			if (name.size() == 0)
				throw exception("Illegal variable name!");
			if (addName)
				expr = name + expr;
			if (name == "ans" || findOperator(name) || findFunction(name) || (findVariable(name) && getVariable(name).type() == None))
				throw exception("Illegal variable name!");
			sol = Calculator().solve(expr);
			if (sol.size() != 1)
				throw exception("Cannot assign value to variable!");
			m_constants[name] = element(Number, sol[0]);
			break;
		}
		//special case for one character operators
		if (depth == 0)
			switch (el) {
			case '+': case '-': case '*': case '%': case '/': case '^':
				if (currentWord.size() > 0) {
					m_elements.push_back(element(currentType, currentWord));
					currentWord.clear();
					currentType = None;
				}
				currentWord += el;
				m_elements.push_back(element(Variable, currentWord));
				currentWord.clear();
				continue;
			}
		if (el == ')') {
			depth++;
			currentWord += el;
			if (depth == 0) {
				m_elements.push_back(element(Expression, currentWord));
				currentWord.clear();
				currentType = None;
			}
			continue;
		}
		else if (el == '(') {
			if (currentWord.size() > 0 && depth == 0) {
				m_elements.push_back(element(currentType, currentWord));
				currentWord.clear();
				currentType = None;
			}
			depth--;
			currentType = Expression;
			currentWord += el;
			continue;
		}
		if (depth < 0 && currentType == Expression) {
			currentWord += el;
			continue;
		}
		if (Calculator::is_a_number(el)) {
			if (currentType == Number || currentType == Expression) {
				currentWord += el;
			}
			else {
				if (currentWord.size() > 0) {
					m_elements.push_back(element(currentType, currentWord));
					currentWord.clear();
					currentType = None;
				}
				currentWord += el;
				currentType = Number;
			}
		}
		else if (el == '.') {
			if (currentType == Number || currentType == None) {
				currentWord += el;
				currentType = Number;
			}
			else if (currentWord.size() > 0) {
					m_elements.push_back(element(currentType, currentWord));
					currentWord.clear();
					currentType = None;
					currentWord += el;
					currentType = Number;
			}
		}
		else if (el == ' ') {
			if (currentWord.size() > 0) {
				m_elements.push_back(element(currentType, currentWord));
				currentWord.clear();
				currentType = None;
			}
			if (el == ',') {
				m_elements.push_back(element(None, ","));
			}
		}
		else {
			if (currentType != Variable && currentWord.size() > 0) {
				m_elements.push_back(element(currentType, currentWord));
				currentWord.clear();
				currentType = None;
			}
			currentType = Variable;
			currentWord += el;
		}
	}
	if (depth != 0)
		throw exception("Bad expression!");
	if (currentWord.size() > 0) {
		m_elements.push_back(element(currentType, currentWord));
	}
	for (element& el : m_elements) {
		if (el.type() == Variable)
			el.type() = find(el.expr());
		if (el.type() == Function)
			el.setFunc(getFunction(el.expr()).m_func);
		if (el.type() == Operator) {
			el.setFunc(getOperator(el.expr()).m_func);
			el.pres() = getOperator(el.expr()).pres();
		}
	}
	if (m_elements.size() == 0)
		return;
	for (int i = 0; i < m_elements.size() - 1; ++i) {
		if (m_elements[i].type() == Number && (m_elements[i+1].type() == Variable || m_elements[i+1].type() == Expression || m_elements[i+1].type() == Function)) {
			m_elements[i].type() = Expression;
			m_elements[i].expr() = "(" + m_elements[i].expr() + "*" + m_elements[i + 1].expr() + ")";
			m_elements.erase(m_elements.begin() + i + 1);
		}
	}
	index = 0;
	for (element el : m_elements) {
		if (el.type() == None && el.expr() != ",")
			throw exception("Unknown element!");
		index++;
	}
}

//solves all the operators in the current instance of Calculator
void Calculator::handleOperators()
{
	int index;
	//this monstrosity handles operator presedence, couldn't find a tidier solution
	while (true) {
		index = -1;
		int i = 0;
		//finds the operatror, which should be handled first
		for (element el : m_elements) {
			if (el.type() == Operator && (index == -1 || el.pres() > m_elements[index].pres()))
				index = i;
			i++;
		}
		if (index == -1)
			break;
		element right, left;
		if (index == 0 || m_elements[index - 1].type() == None)
			left = element();
		else
			left = m_elements[index - 1];
		if (index + 1 == m_elements.size() || m_elements[index + 1].type() == None)
			throw exception("Bad expression!");
		else
			right = m_elements[index + 1];
		//solves it
		m_elements[index].solve(left, right);
		m_elements[index].type() = Number;
		if (index - 1 >= 0 && m_elements[index - 1].type() != None) {
			m_elements.erase(m_elements.begin() + index - 1);
			if (index < m_elements.size())
				m_elements.erase(m_elements.begin() + index);
		}
		else if (index + 1 < m_elements.size())
			m_elements.erase(m_elements.begin() + index + 1);

	}
}

//solves all the numbers, variables and expressions in the current instance of Calculator
void Calculator::handleNumbers()
{
	for (element& el : m_elements) {
		if (el.type() == Number || el.type() == Variable || el.type() == Expression)
			el.solve();
	}
}

//solves all the functions in the current instance of Calculator
void Calculator::handleFunctions()
{
	int index = -1;
	int i = 0;
	for (element& el : m_elements) {
		if (el.type() == Function) {
			if (i == m_elements.size() - 1)
				throw exception("Bad expression!");
			element right = m_elements[i + 1], left = element();
			el.solve(left, right);
			m_elements.erase(m_elements.begin() + i + 1);
		}
		i++;
	}
}

//prints the elements of the down broken string --- for debugging
void Calculator::printElements()
{
	for (element el : m_elements) {
		std::cout << el.expr() << " " << el.value()[0] << ';';
	}
	std::cout << std::endl;
}

double Calculator::to_int(const std::string& s)
{
	if (s.back() == '.')
		throw exception("Bad expression!");
	int point = s.size();
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '.') {
			if (point == s.size())
				point = i;
			else
				throw exception("Bad expression!");
		}
	}
	double szorzo = 1;
	double out = 0;
	for (int i = point - 1; i >= 0; --i) {
		out += double(s[i] - '0') * szorzo;
		szorzo *= 10;
	}
	szorzo = 0.1;
	for (int i = point + 1; i < s.size(); ++i) {
		out += double(s[i] - '0') * szorzo;
		szorzo /= 10;
	}
	return out;
}

//determines the type of an element
Type Calculator::find(const std::string& s) {
	if (findOperator(s))
		return Operator;
	if (findFunction(s))
		return Function;
	if (findVariable(s))
		return Variable;
	return None;
}

bool Calculator::is_a_number(const char& c)
{
	return c >= '0' && c <= '9';
}

//-----------------getters---------------------------------
element Calculator::getVariable(const std::string& s)
{
	if (!findVariable(s))
		throw exception("Uninitialized variable!");
	return m_constants[s];
}

bool Calculator::findVariable(const std::string& s)
{
	return m_constants.find(s) != m_constants.end();
}

element Calculator::getOperator(const std::string& s)
{
	return m_operators[s];
}

bool Calculator::findOperator(const std::string& s)
{
	return  m_operators.find(s) != m_operators.end();
}

element Calculator::getFunction(const std::string& s)
{
	return m_functions[s];
}

bool Calculator::findFunction(const std::string& s)
{
	return m_functions.find(s) != m_functions.end();
}
//-----------------------------------------------------
