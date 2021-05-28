#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include <string>

using namespace std;

/// <summary>
/// Factorial
/// </summary>
/// <param name="a">- double </param>
/// <returns>double a with factorial</returns> 
double factorial(double a) {
	if (a <= 0)
		return a;
	return a + factorial(a - 1);
}

/// <summary>
/// Substring replacement in a string
/// </summary>
/// <param name="str">- string to replace </param>
/// <param name="from">- start </param>
/// <param name="to">- end </param>
/// <returns>success of operstion</returns> 
bool strReplace(string& str, const string& from, const string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

/// <summary>
/// Determining the priority of operands
/// </summary>
/// <param name="a">- char </param>
/// <returns>priority</returns> 
int priority(char a) {
	switch (a) {
	case ')': return 5;
	case '^': return 4;
	case '*': case '/': return 3;
	case '-': case '+': return 2;
	case '(': return 1;
	}
	return 0;
}

/// <summary>
/// Pushing a number to the queue
/// </summary>
/// <param name="queue">- queue pointer </param>
/// <param name="line">- number </param>
/// <param name="from">- start </param>
/// <param name="to">- end </param>
void pushNumber(queue<string>& queue, string line, int from, int to) {
	string number = "";
	for (int j = from; j < to; ++j) {
		number += line.at(j);
	}
	if (number != "")
		queue.push(number);
}

/// <summary>
/// Calculate postfix notation
/// </summary>
/// <param name="reversed">- postfix form </param>
/// <returns>answer</returns>
double postfixCalculate(string reversed) {
	stack<string> stack;
	string current;
	double temp, firstOperand, secondOperand;
	int j = 0;
	/* Go throough the line */
	for (int i = 0; i < reversed.length(); ++i) {
		char a = reversed.at(i);
		current = ""; current += a;
		/* If the symbol is equal to '+', '-', '*', '/', '%' or '^' */
		if ((a == '+' || a == '-' || a == '*' || a == '/' || a == '%' || a == '^') && !stack.empty()) {
			/* Whether there is a factorial -> parsing the first number from the string */
			if (!stack.top().find("!")) {
				string fact = stack.top();
				strReplace(fact, "!", "");
				secondOperand = factorial(atof(fact.c_str())); stack.pop();
			}
			else {
				secondOperand = atof(stack.top().c_str()); stack.pop();
			}
			/* Whether there is a factorial -> parsing the second number from the string */
			if (!stack.top().find("!")) {
				string fact = stack.top();
				strReplace(fact, "!", "");
				firstOperand = factorial(atof(fact.c_str())); stack.pop();
			}
			else {
				firstOperand = atof(stack.top().c_str()); stack.pop();
			}
			/* Perform the operation and push the result to the stack */
			switch (a) {
			case '+':
				temp = (firstOperand + secondOperand);
				stack.push(to_string(temp));
				break;
			case '-':
				temp = (firstOperand - secondOperand);
				stack.push(to_string(temp));
				break;
			case '*':
				temp = (firstOperand * secondOperand);
				stack.push(to_string(temp));
				break;
			case '/':
				temp = (firstOperand / secondOperand);
				stack.push(to_string(temp));
				break;
			case '%':
				temp = fmod(firstOperand, secondOperand);
				stack.push(to_string(temp));
				break;
			case '^':
				temp = pow(firstOperand, secondOperand);
				stack.push(to_string(temp));
				break;
			}
		} /* If the symbol is equal to a number, push it into the stack*/
		else if ((a >= '0' && a <= '9') || a == '!') {
			string number = "";
			while (((a >= '0' && a <= '9') || a == '!') && i <= reversed.length() && reversed.at(i) != ' ') {
				number += reversed.at(i); ++i;
			}
			stack.push(number);
		}
	}
	return atof(stack.top().c_str());
}

/// <summary>
/// Translating a string into a postfix form
/// </summary>
/// <param name="input">- your string </param>
/// <returns>postfix form</returns> 
string toPostfix(string input) {
	stack<string> stack;
	queue<string> queue;
	string current, reversed;
	int last = 0;
	/* Go through the line */
	for (int i = 0; i < input.length(); ++i) {
		char a = input.at(i);
		current = ""; current += a;
		/* If the symbol is equal to '+', '-', '*', '/' or '%' */
		if (a == '+' || a == '-' || a == '*' || a == '/' || a == '%' || a == '^') {
			pushNumber(queue, input, last, i);
			last = i + 1;
			/* Add the operand to the stack */
			if (stack.empty() || stack.top() == "(") {
				stack.push(current);
			}
			else if (priority(stack.top().at(0)) < priority(a)) {
				stack.push(current);
			}
			else if (!stack.empty()) {
				while (priority(stack.top().at(0)) >= priority(a)) {
					queue.push(stack.top());
					stack.pop();
					if (stack.empty()) break;
				}
				stack.push(current);
			}
		} /* If the symbol is equal to '(' */
		else if (a == '(') {
			stack.push(current);
			last = i + 1;
		} /* If the symbol is equal to ')' */
		else if (a == ')') {
			pushNumber(queue, input, last, i);
			last = i + 1;
			/* Take all from the stack into queue until there isn't '(' */
			while (stack.top() != "(") {
				queue.push(stack.top());
				stack.pop();
				if (stack.empty()) break;
			}
			/* Delete '(' from the stack */
			if (stack.top() == "(")
				stack.pop();
		}
		else if ((i + 1) == input.length()) {
			pushNumber(queue, input, last, (i + 1));
		}
	}
	/* Take all from the stack into queue */
	while (!stack.empty()) {
		queue.push(stack.top());
		stack.pop();
	}
	/* Translate the queue into a line */
	while (!queue.empty()) {
		reversed += queue.front() + ' ';
		queue.pop();
	}
	return reversed;
}