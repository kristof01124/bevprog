#include "../include/std_lib_facilities.h"

int main() {
	double first,second;
	while (cin>>first>>second) {
		if (first < second)
			std::swap(first, second);
		std::cout<<"The smaller value is: "<<second<<std::endl;
		std::cout<<"The larger value is: "<<first<<std::endl;
		if (first - second < 1.0/100.0)
			std::cout<<"The numbers are almost equal!"<<std::endl;

	}
}
