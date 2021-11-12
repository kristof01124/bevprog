#include <vector>
#include <iostream>

std::vector<int> gv = {1,2,4,8,16,32,64,128,256,512};

void print_vector(std::ostream& os, std::vector<int> v) {
  std::cout<<"The elements of the vector:\n";
  for (int i = 0; i<v.size(); ++i) {
    std::cout<<v[i]<<std::endl;
  }
}

void f(std::vector<int> gv) {
  std::vector<int> lv;
  lv = gv;
  std::vector<int> lv2(gv);
  print_vector(std::cout,lv2);
}

int main() {
  f(gv);
  std::vector<int> vv(10);
  int val = 1;
  for (int i =0;i<10;++i) {
    val*=(i+1);
    vv[i] = val;
  }
  f(vv);
}
