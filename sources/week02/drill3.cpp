// read and write a first name
#include "../include/std_lib_facilities.h"

int main()
{
 cout << "Enter the name of the person you want to write to:\n";
 string first_name; // first_name is a variable of type string
 cin >> first_name; // read characters into first_name
 cout << "Dear " << first_name << ",\n";
 cout << "	How are you? I am fine. I miss you.\n";
 string friend_name;
 cout << "Tell me another one of your friends' name:\n";
 cin >> friend_name;
 cout << "Have you seen " + friend_name + " lately?\n";
 char friend_sex = 0;
 cout << "Tell me your other friend's gender: (f - female, m - male)\n";
 cin >> friend_sex;
 if (friend_sex == 'm')
 	cout<<"If you see " + friend_name + " please ask him to call me.\n";
 if (friend_sex == 'f')
 	cout<<"If you see " + friend_name + " please ask her to call me.\n";
 int age;
 cout << "Tell me the age of your friend: ";
 cin >> age;
if (age <= 0 || age >= 110)
	simple_error("you're kidding!");
 cout << "I hear you just had a birthday and you are "<<age<<" years old.\n";
if (age < 12)
	cout << "Next year you will be "<<age+1<<" years old.\n";
if (age == 17)
	cout << "Next year you will be able to vote.\n";
if (age > 70)
	cout << "I hope you're enjoying your retirement.\n";
cout << "Yours sincerely, \n\nKristof\n";
}
