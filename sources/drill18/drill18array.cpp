#include <vector>
#include <iostream>

int ga[10]  = {1,2,4,8,16,32,64,128,256,512};

void print_array(std::ostream& os, int* a,unsigned int n) {
  std::cout<<"The elements of the array:\n";
  for (int * i = a;i<a + n; ++i) {
    os<<*i<<std::endl;
  }
}

void f(int* ga,unsigned int n) {
  int la[n];
  for (int i = 0;i<n;++i)
    la[i] = ga[i];
  print_array(std::cout,la,n);
  int * p = new int[n];
  for (int i = 0;i<n;++i)
    p[i] = ga[i];
  print_array(std::cout,p,n);
  delete[] p;
}

int main() {
  f(ga,10);
  int aa[10];
  int val = 1;
  for (int i = 0;i<10;++i) {
    val*=i+1;
    aa[i] =val;
  }
  f(aa,10);
}
