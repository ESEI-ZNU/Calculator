#include "Number.h"

/// <summary>
/// Class constructor
/// </summary>
Number::Number() {
	num = "0";
	base = 10;
}
/// <summary>
/// Class constructor
/// </summary>
/// <param name="number">- number as string </param>
Number::Number(string str) {
	num = str;
	base = 10;
}
/// <summary>
/// Class constructor
/// </summary>
/// <param name="number">- number as string </param>
/// <param name="basis">- numerical system of this number </param>
Number::Number(string str, int basis) {
	num = str;
	base = basis;
}
/// <summary>
/// Class constructor
/// </summary>
/// <param name="number">- number as string </param>
/// <param name="basis">- numerical system of this number </param>
Number::Number(double str, int basis) {
	num = to_string(str);
	base = basis;
}
/// <summary>
/// Class destructor
/// </summary>
Number::~Number() {
	num = "";
	base = 0;
}
/// <summary>
/// Converting a number to another number system
/// </summary>
/// <param name="number">- number as string </param>
/// <param name="basis">- numerical system of this number </param>
/// <returns> null </returns>
string Number::get(int basis) {
	if (basis == 10) {
		return toDecimal(num, basis, 5);
	} else if (base == 10) {
		return fromDecimal(num, basis, 5);
	} else {
		return fromDecimal(toDecimal(num, base, 5), basis, 5);
	}
}
/// <summary>
/// Finding a number from the decimal system
/// </summary>
/// <param name="number">- the number to be translated </param>
/// <param name="basis">- original number system </param>
/// <param name="length">- is the number of decimal places </param>
/// <returns> Returns a number in the specified number system </returns>
string Number::fromDecimal(string number, int basis, int length) {
	stack<char> stk;
	int integer = (int)atof(number.c_str());
	double fractional = atof(number.c_str()) - integer;
	string equal = "";
	do {
		int remainder = integer % basis;
		if (remainder > 9 && remainder <= 36) {
			stk.push((char)(remainder + 55));
		} else
			stk.push((char)(remainder + 48));
		integer = integer / basis;
	} while (integer != 0);
	while (!stk.empty()) {
		equal += stk.top();
		stk.pop();
	}
	equal += '.';
	for (int i = 0; i < length; ++i) {
		fractional *= basis;
		int remainder = fractional;
		if (remainder > 9 && remainder <= 36) {
			equal += (char)(remainder + 55);
		} else
			equal += (char)(remainder + 48);
		if (fractional > 1) {
			fractional -= (int)fractional;
		}
	}
	stk = stack<char>();
	return equal;
}
/// <summary>
/// The known number in dozens of systems
/// </summary>
/// <param name="number">- the number to be translated </param>
/// <param name="basis">- original number system </param>
/// <param name="length">- is the number of decimal places </param>
/// <returns> Returns a number in the 10th notation system </returns>
string Number::toDecimal(string number, int basis, int length) {
	string equal = "";
	int lastInt = number.find_first_of('.') - 1, j = 0;
	if (lastInt < 0)
		lastInt = number.length() - 1;
	double sum = 0;
	for (int i = lastInt; i >= 0; --i) {
		int num = 0;
		char c = number.at(i);
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			num = c - 55;
		} else if (c >= '0' && c <= '9') {
			num = c - 48;
		}
		sum += num * pow(base, j);
		++j;
	}
	if (number.find_first_of('.') > 0) {
		j = -1;
		for (int i = lastInt + 2; i < number.length(); ++i) {
			int num = 0;
			char c = number.at(i);
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
				num = c - 55;
			} else if (c >= '0' && c <= '9') {
				num = c - 48;
			}
			sum += num * pow(base, j);
			--j;
		}
	}
	equal = to_string(sum);
	equal = equal.erase(equal.find_last_of('.') + 1 + length);
	return equal;
}
