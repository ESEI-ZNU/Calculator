#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Number {
public:
	Number();
	Number(string str);
	Number(string str, int bs);
	Number(double str, int bs);
	~Number();
	
	string get(int base);

private:
	string num;
	int base;

	//int div(int number, int base);
	string fromTenTo(string number, int base, int length);
};

