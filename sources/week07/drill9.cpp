#include "../include/std_lib_facilities.h"
#include <vector>

enum Month {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};


struct Date {
private:
 int y;
 int m;
 int d;

//helper functions
public:
   static int leap_year(int a){
   if (a%400 == 0 || (a%100!=0 && a%4==0))
    return 1;
  else
    return 0;
 }

 static int days_of_month(int y,int m){
   if (m!=2)
    return monthDays[m-1];
    return monthDays[m-1]+leap_year(y);
  }


//actual functions
public:
  static int monthDays[12];
 Date(int a, int b, int c) {
   //checks the month
   if (b<1 || b>12)
   simple_error("Bad date!");
   //checks the day
   if (c<0 || (c>days_of_month(a,b)))
   simple_error("Bad date!");
   y = a;
   m = b;
   d = c;
 }

 void add_days(int n) {
   //while it can jump months repeats
   while (n > (days_of_month(y,m))-day()) {
     n-=days_of_month(y,m)-day()+1;
     d = 1;
     m++;
     if (m>12) {
       y++;
       m=1;
     }
   }
   //just add the rest of the days
   d+=n;
 }

 void add_month(int n) {
   m+=n;
   m%=12;
   if (m==0)
    m=12;
 }

 void add_year(int n) {
   y+=n;
 }

 int year() const{
   return y;
 }

 int month() const{
   return m;
 }

 int day() const{
   return d;
 }
};

int Date::monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

ostream& operator<<(ostream& os, const Date& d)
{
  return os << '(' << d.year()<< ',' << d.month()<< ',' << d.day() << ')';
}

int main() {
  Date today(2020, 11, 20);
  today.add_days(30);
}
