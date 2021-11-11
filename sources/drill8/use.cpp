#include "my.h"
#include <iostream>

int foo;

void swap_v(int a,int b) {
	int temp; 
	temp = a; 
	a=b; 
	b=temp;
}

void swap_r(int& a,int& b)  {
	int temp; 
	temp = a; 
	a=b; 
	b=temp;
}

void swap_cr(const int& a, const int& b) {
	int temp; 
	temp = a;
	//a=b; doesnt work, beacause a and b are consts 
	//b=temp;
}

namespace X {
	int var;
	void print() {
		std::cout<<var<<std::endl;
	}
}

namespace Y {
	int var;
	void print() {
		std::cout<<var<<std::endl;
	}	
}

namespace Z {
	int var;
	void print() {
		std::cout<<var<<std::endl;
	}
}

int main() {
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print();
	{
	using Z::var;
	using Z::print;
	var = 11;
	print();
	}
	print();
	X::print();
}