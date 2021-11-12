#include <vector>
#include <iostream>

void print_array10(std::ostream& os, int* a) {
  std::cout<<"The elements of the array:\n";
  for (int * i = a;i<a + 10; ++i) {
    os<<*i<<std::endl;
  }
}

void print_array(std::ostream& os, int* a,unsigned int n) {
  std::cout<<"The elements of the array:\n";
  for (int * i = a;i<a + n; ++i) {
    os<<*i<<std::endl;
  }
}

void print_vector(std::ostream& os, std::vector<int> v) {
  std::cout<<"The elements of the vector:\n";
  for (int i = 0; i<v.size(); ++i) {
    std::cout<<v[i]<<std::endl;
  }
}

int main() {
  {
  //--------------- FIRST PART ------------------------------
  //with new
  int * myArray = new int[10];
  print_array10(std::cout, myArray);
  delete[] myArray;
  myArray = new int[10];
  for (int i = 0;i<10;++i)
    myArray[i] = 100 +i;
  print_array10(std::cout, myArray);
  int * myOtherArray = new int[11];
  for (int i = 0;i<11;++i)
      myOtherArray[i] = 100 +i;
  print_array(std::cout, myOtherArray, 11);
  delete[] myArray;
  myArray = new int[20];
  for (int i = 0;i<20;++i)
    myArray[i] = 100 +i;
  print_array(std::cout, myArray, 20);
  delete[] myArray, myOtherArray;
  //with vectors
  std::vector<int> myVector(10);
  for (int i = 0;i<myVector.size();++i)
    myVector[i] = 100+i;
  print_vector(std::cout, myVector);
  myVector.push_back(110);
  print_vector(std::cout, myVector);
  myVector.resize(20);
  for (int i = 11;i<myVector.size();++i)
    myVector[i] = 100+i;
  print_vector(std::cout, myVector);
  }
  //--------------------------- SECOND PART ------------------
  int * p1 = new int(7);
  std::cout<<p1<<" "<<*p1<<std::endl;
  int * p2 = new int[7];
  int val = 1;
  for (int i = 0;i<7;++i) {
    p2[i] = val;
    val*=2;
  }
  std::cout<<p2<<std::endl;
  print_array(std::cout, p2, 7);
  int * p3(p2);
  delete p1;
  p1 = p2;
  p2 = p3;
  std::cout<<p1<<" "<<*p1<<std::endl;
  std::cout<<p2<<" "<<*p2<<std::endl;
  delete[] p2;
  int myArray[10],myOtherArray[10];
  val = 1;
  for (int i = 0;i<10;++i) {
    myArray[i] = val;
    val*=2;
    myOtherArray[i] = myArray[i];
  }
  print_array10(std::cout,myArray);
  print_array10(std::cout,myOtherArray);
  std::vector<int> myVector(10);
  val = 1;
  for (int i = 0;i<10;++i) {
    myVector[i] = val;
    val*=2;
  }
  std::vector<int> myOtherVector(myVector);
  print_vector(std::cout, myVector);
  print_vector(std::cout, myOtherVector);
}
