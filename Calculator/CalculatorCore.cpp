#include <iostream>
#include <string>
#include "Number.h"

using namespace std;

/// <summary>
/// Get postfix notation
/// </summary>
/// <param name="input">- your string</param>
/// <returns>postfix form</returns>
string toPostfix(string input);
/// <summary>
/// Calculate postfix notation
/// </summary>
/// <param name="input">- postfix form</param>
/// <returns>answer</returns>
double postfixCalculate(string reversed);

/// <summary>
/// Main function
/// </summary>
/// <returns>0</returns>
int main() {
	string string = "", substr = "", postfix;
	int basis, toBasis, task;
	double answer;
	char symbol;
	do {
		/* Task chooser */
		cout << "0 - out; " << endl;
		cout << "1 - simple calculator; " << endl;
		cout << "2 - numerical systems calculator. " << endl;
		do {
			cin >> task;
		} while (task < 0 || task > 2);
		/* First task */
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
		} /* Second task */
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