#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

#define N 7

struct point  {
  int m_x,m_y;
public:
  point(int x, int y)
  :m_x(x), m_y(y) {}

  void print() {
    std::cout<<'('<<m_x<<','<<m_y<<')'<<std::endl;
  }
  int x() const {return m_x;}
  int y() const  {return m_y;}
  bool operator == (const point& other) {
    return x() == other.x() && y() == other.y();
  }
  bool operator != (const point& other) {
    return !(*this == other);
  }
};

int main() {
  std::vector<point> original_points;
  std::cout<<"Gimme "<<N<<" points!"<<std::endl;
  for (int i = 0; i<N;++i) {
    int a,b;
    std::cin>>a>>b;
    original_points.emplace_back(a,b);
  }
  for (point p:original_points)
    p.print();
  std::ofstream out("mydata.txt");
  for (point p:original_points) {
    out<<p.x()<<" "<<p.y()<<std::endl;
  }
  out.close();
  std::ifstream in("mydata.txt");
  std::vector<point> processed_points;
  while (true) {
    int a,b;
    in>>a>>b;
    if (in.eof())
      break;
    processed_points.emplace_back(a,b);
  }
  std::cout<<"Original points:"<<std::endl;
  for (point p:original_points)
    p.print();
    std::cout<<"Processed points:"<<std::endl;
  for (point p:processed_points)
    p.print();
  try {
  if (processed_points.size() != original_points.size())
    throw std::string("Something's wrong!");
  for (int i = 0; i < processed_points.size(); ++i) {
    if (processed_points[i] != original_points[i])
      throw std::string("Something's wrong!");
  }
}
catch (std::string s) {
  std::cout<<s<<std::endl;
  return 0;
}
std::cout<<"Everything is OK."<<std::endl;
}
