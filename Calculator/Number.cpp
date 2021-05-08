#include "Number.h"

Number::Number() {
	num = "0";
	base = 10;
}
Number::Number(string str) {
	num = str;
	base = 10;
}
Number::Number(string str, int basis) {
	num = str;
	base = basis;
}
Number::Number(double str, int basis) {
	num = to_string(str);
	base = basis;
}
Number::~Number() {
	num = "";
	base = 0;
}

string Number::get(int basis) {
	return fromTenTo(num, basis, 5);
}

string Number::fromTenTo(string number, int basis, int length) {
	stack<char> stack;
	int integer = (int)atof(number.c_str());
	double fractional = atof(number.c_str()) - integer;
	string equal = "";
	do {
		int remainder = integer % basis;
		if (remainder > 9 && remainder <= 36) {
			stack.push((char)(remainder + 55));
		} else
			stack.push((char)(remainder + 48));
		integer = integer / basis;
	} while (integer != 0);
	while (!stack.empty()) {
		equal += stack.top();
		stack.pop();
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
	return equal;
}
