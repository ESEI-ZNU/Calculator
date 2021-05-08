/* 

Щось про copyrights...

*/

#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include <string>

using namespace std;

/* Функція факторіалу */
double factorial(double a) {
	if (a <= 0)
		return a;
	return a + factorial(a - 1);
}

/* Функція заміни підрядка в рядку */
bool strReplace(string& str, const string& from, const string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

/* Функція визначення пріоритету операндів */
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

/* Функція додавання числа до черги */
void pushNumber(queue<string> &queue, string line, int from, int to) {
	string number = "";
	for (int j = from; j < to; ++j) {
		number += line.at(j);
	}
	if (number != "")
		queue.push(number);
}

/* Функція розрахунку постфіксної форми */
double postfixCalculate(string reversed) {
	stack<string> stack;
	string current;
	double temp, firstOperand, secondOperand;
	int j = 0;
	/* Перебираємо рядок */
	for (int i = 0; i < reversed.length(); ++i) {
		char a = reversed.at(i);
		current = ""; current += a;
		/* Якщо символ дорівнює '+', '-', '*', '/', '%' або '^' */
		if ((a == '+' || a == '-' || a == '*' || a == '/' || a == '%' || a == '^') && !stack.empty()) {
			/* Чи є факторіал -> парсимо перше число з рядку */
			if (!stack.top().find("!")) {
				string fact = stack.top();
				strReplace(fact, "!", "");
				secondOperand = factorial(atof(fact.c_str())); stack.pop();
			} else {
				secondOperand = atof(stack.top().c_str()); stack.pop();
			}
			/* Чи є факторіал -> парсимо друге число з рядку */
			if (!stack.top().find("!")) {
				string fact = stack.top();
				strReplace(fact, "!", "");
				firstOperand = factorial(atof(fact.c_str())); stack.pop();
			} else {
				firstOperand = atof(stack.top().c_str()); stack.pop();
			}
			/* Виконуємо операцію та результат штовхаємо до стека */
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
		} /* Якщо символ дорівнює цифрі штовхаємо у стек*/
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

/* Функція переведення рядка в постфіксну форму */
string toPostfix(string input) {
	stack<string> stack;
	queue<string> queue;
	string current, reversed;
	int last = 0;
	/* Перебираємо рядок */
	for (int i = 0; i < input.length(); ++i) {
		char a = input.at(i);
		current = ""; current += a;
		/* Якщо символ дорівнює '+', '-', '*', '/' або '%' */
		if (a == '+' || a == '-' || a == '*' || a == '/' || a == '%' || a == '^') {
			pushNumber(queue, input, last, i);
			last = i + 1;
			/* Додаємо операнд до стека */
			if (stack.empty() || stack.top() == "(") {
				stack.push(current);
			} else if (priority(stack.top().at(0)) < priority(a)) {
				stack.push(current);
			} else if (!stack.empty()) {
				while (priority(stack.top().at(0)) >= priority(a)) {
					queue.push(stack.top());
					stack.pop();
					if (stack.empty()) break;
				}
				stack.push(current);
			}
		} /* Якщо символ дорівнює '(' */ 
		else if (a == '(') {
			stack.push(current);
			last = i + 1;
		} /* Якщо символ дорівнює ')' */
		else if (a == ')') {
			pushNumber(queue, input, last, i);
			last = i + 1;
			/* Вивантажуємо все з стека в чергу поки не буде '(' */
			while (stack.top() != "(") {
				queue.push(stack.top());
				stack.pop();
				if (stack.empty()) break;
			}
			/* Видаляємо '(' з стека */
			if (stack.top() == "(") 
				stack.pop();
		}
		else if ((i + 1) == input.length()) {
			pushNumber(queue, input, last, (i + 1));
		}
	}
	/* Вивантажуємо з стека в чергу */
	while (!stack.empty()) {
		queue.push(stack.top());
		stack.pop();
	}
	/* Переводимо чергу в рядок */
	while (!queue.empty()) {
		reversed += queue.front() + ' ';
		queue.pop();
	}
	return reversed;
}