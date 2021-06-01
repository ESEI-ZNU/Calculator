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
				if (symbol == ',') {
					string += '.';
				} else if (symbol != ' ' && symbol != '=')
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
			bool correct;
			do {
				correct = true;
				cin >> string;
				int value;
				do {
					cin >> substr;
					int bracket = substr.find_first_of('(');
					if (bracket >= 0)
						substr.erase(bracket, 1);
					bracket = substr.find_first_of(')');
					if (bracket >= 0)
						substr.erase(bracket, 1);
					value = (int)atof(substr.c_str());
				} while (value < 2 && value > 36);
				basis = value;
				for (int i = 0; i < string.length(); ++i) {
					char symbol = string.at(i);
					if (symbol >= '0' && symbol <= '9') {
						symbol -= 48;
					} else if (symbol >= 'A' && symbol <= 'Z') {
						symbol -= 55;
					} else if (symbol >= 'a' && symbol <= 'z') {
						string.at(i) = symbol - 32;
						symbol -= 87;
					} else if (symbol == ',') {
						string.at(i) = '.';
					}
					if (symbol >= value && symbol != '.' && symbol != ',') {
						correct = false;
					}
				}
				if (!correct) cout << "Incorrect basis or number!" << endl;
			} while (!correct);
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