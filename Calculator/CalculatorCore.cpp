#include<iostream>
#include<string>
#include "Number.h"

using namespace std;

/* Образи функцій */
string toPostfix(string input);
double postfixCalculate(string reversed);

/* Головна функція */
int main() {
	string string = "", substr = "", postfix;
	int basis, toBasis, task;
	double answer;
	char symbol;
	do {
		/* Вибір завдання або вихід з програми */
		cout << "0 - out; " << endl;
		cout << "1 - simple calculator; " << endl;
		cout << "2 - numerical systems calculator. " << endl;
		do {
			cin >> task;
		} while (task < 0 || task > 2);
		/* Звичайний калькулятор */
		if (task == 1) {
			cout << "Enter your formula: " << endl;
			string = "";
			do {
				cin >> symbol;
				if (symbol != ' ' && symbol != '=')
					string += symbol;
			} while (symbol != '=');
			postfix = toPostfix(string);
			answer = postfixCalculate(postfix);
			cout << postfix << endl;
			cout << endl;
			cout << answer << " (" << 10 << ")" << endl;
			cout << endl;
			Number num(answer, 10);
			cout << num.get(2) << " (" << 2 << ")" << endl;
			cout << num.get(8) << " (" << 8 << ")" << endl;
			cout << num.get(16) << " (" << 16 << ")" << endl;
		} /* Калькулятор систем числення */
		else if (task == 2) {
			cout << "Enter your number (ex. AF.32 (16)): " << endl;
			cin >> string;
			do {
				cin >> substr;
				if (substr.find_first_of('(') >= 0)
					substr.erase(substr.find_first_of('('), 1);
				if (substr.find_first_of(')') >= 0)
					substr.erase(substr.find_first_of(')'), 1);
			} while ((int)atof(substr.c_str()) < 2 && (int)atof(substr.c_str()) > 36);
			basis = (int)atof(substr.c_str());
			cout << "Convert to (basis): " << endl;
			do {
				cin >> toBasis;
			} while (toBasis < 2 || toBasis > 36);
			cout << endl;
			Number num(string, basis);
			cout << string << " (" << basis << ") = " << num.get(toBasis) << " (" << toBasis << ")" << endl;
		}
		cout << endl;
	} while (task != 0);
	return 0;
}