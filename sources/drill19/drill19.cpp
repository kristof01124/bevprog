#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class S {
   T val;
   void set(const T& v) {
     val = v;
   }
 public:
   T& get();
   T get() const;
   void print() {std::cout<<val<<std::endl;}
   S(T v)
   :val(v) {};
   void operator = (const T& other) {
     set(other);
   }
 };

template<typename T>
void read_val(T& v) {
  std::cin>>v;
}

template<typename T>
T& S<T>::get() {
  return val;
}

template<typename T>
T S<T>::get() const {
  return val;
}

 void print_vector(std::ostream& os, std::vector<int> v) {
   std::cout<<"The elements of the vector:\n";
   for (int i = 0; i<v.size(); ++i) {
     std::cout<<v[i]<<" ";
   }
   std::cout<<std::endl;
 }

template <typename T>
std::istream& operator >> (std::istream& in,S<T>& other) {
    return in>>other.get();
}

template <typename T>
std::ostream& operator << (std::ostream& out,S<T>& other) {
    return out<<other.get();
}


int main() {
  std::vector<int> a;
  S<int> s_int(2);
  s_int.print();
  S<char> s_char('2');
  s_char.print();
  S<double> s_dub(2.0);
  s_dub.print();
  S<std::string> s_str("two");
  s_str.print();
  S<std::vector<int>> s_vec({2});
  print_vector(std::cout,s_vec.get());
  std::cout<<"int:"<<std::endl;
  std::cin>>s_int;
  std::cout<<s_int<<std::endl;
  std::cout<<"double:"<<std::endl;
  std::cin>>s_dub;
  std::cout<<s_dub<<std::endl;
  std::cout<<"string:"<<std::endl;
  std::cin>>s_str;
  std::cout<<s_str<<std::endl;
}
