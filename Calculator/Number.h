#include<iostream>
#include<string>
#include<stack>
#include<math.h>

using namespace std;

/* Клас "Число" */
class Number {
public:
	/* Конструктори та деструктори */
	Number();
	Number(string str);
	Number(string str, int bs);
	Number(double str, int bs);
	~Number();
	/* Геттери */
	string get(int base);
private:
	/* Поля */
	string num;
	int base;
	/* Функції класу */
	string fromDecimal(string number, int base, int length);
	string toDecimal(string number, int basis, int length);
};

