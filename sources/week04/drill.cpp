#include "../include/std_lib_facilities.h"

int main() {
try {
	cout<<" "<<1<<endl;
	cout << "  Success!\n ";
	cout<<2<<endl;
	cout << " Success!\n ";
	cout<<3<<endl;
	cout << " Success" << "!\n ";
	cout<<4<<endl;
	cout << " Success!" << '\n';
	{
		cout<<" "<<5<<endl;
		int res = 7; 
		vector<int> v(10); 
		v[5] = res; 
		cout << " Success!\n " ;
		}
	{
		cout<<6<<endl;
		vector<int> v(10); 
		v[5] = 7; 
		if (v[5]==7) 
			cout << " Success!\n " ;
		}
	{
		cout<<7<<endl;
		bool cond = true;
		if (cond) 
			cout << " Success!\n "; 
		else 
			cout << " Fail!\n ";
		}
	{
		cout<<8<<endl;
		bool c = true; 
		if (c) 
			cout << " Success!\n "; 
		else 
			cout << " Fail!\n ";
		}
	{
		cout<<9<<endl;
		string s = " ape " ; 
		bool c = " fool " > s; 
		if (c) 
			cout << " Success!\n " ;
	}
	{
		cout<<10<<endl;
		string s = " fool " ; 
		if (s== " fool " ) 
			cout << " Success!\n " ;
	}
	{
		cout<<11<<endl;
		string s = " ape " ; 
		if (s== " ape " ) 
			cout << " Success!\n " ;
	}
	{
		cout<<12<<endl;
		string s = " ape "; 
		if (s+ " fool "  == " ape  fool ") 
			cout << " Success!\n " ;
	}
	{
		cout<<13<<endl;
		vector<char> v(5);
		for (int i=0; i<v.size(); ++i) ;
			cout << " Success!\n " ;
	}
	{
		cout<<14<<endl;
		vector<char> v(5); 
		for (int i=0; i<=v.size(); ++i) ;
			cout << " Success!\n ";
	}
	{
		cout<<15<<endl;
		string s = " Success!\n "; 
		for (int i=0; i<s.size(); ++i) 
			cout << s[i];
	}
	{
		cout<<16<<endl;
		if (true) 
			cout << " Success!\n "; 
		else 
			cout << " Fail!\n " ;
	}
	{
		cout<<17<<endl;
		int x = 2000; 
		int c = x; 
		if (c==2000) 
			cout << " Success!\n " ;
	}
	{
		cout<<18<<endl;
		string s = " Success!\n " ;
		for (int i=0; i<s.size(); ++i) 
			cout << s[i];
	}
	{
		cout<<19<<endl;
		vector<int> v(5); 
		for (int i=0; i<=v.size(); ++i) ; 
			cout << " Success!\n " ;
	}
	{
		cout<<20<<endl;
		int i=0; 
		int j = 9; 
		while (i<10) 
			++i; 
		if (j<i) cout << " Success!\n " ;
	}
	{
		cout<<21<<endl;
		int x = 2; 
		double d = 9/double(x); 
		if (d==2*double(x)+0.5) 
			cout << " Success!\n " ;
	}
	{
		cout<<22<<endl;
		string s = " Success!\n " ; 
		for (int i=0; i<=10; ++i) 
			cout << s[i];
	}
	{
		cout<<23<<endl;
		int i=0; 
		int j = 5;
		while (i<10) 
			++i; 
		if (j<i) 
			cout << " Success!\n " ;
	}
	{
		cout<<24<<endl;
		int x = 4; 
		double d = 17/double(x - 2); 
		if (d=2*double(x)+0.5) 
			cout << " Success!\n " ;}
	{
		cout<<25<<endl;
		cout << " Success!\n  " ;
	}
keep_window_open();
return 0;
}
catch (exception& e) {
cerr << "error: " << e.what() << '\n';
keep_window_open();
return 1;
}
catch (...) {
cerr << "Oops: unknown exception!\n ";
keep_window_open();
return 2;
}
}