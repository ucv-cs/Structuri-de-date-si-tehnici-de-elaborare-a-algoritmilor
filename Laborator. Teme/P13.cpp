/**
 * 13. Sa se verifice daca intr-o expresie se parantezele se inchid corect ex.
 * a{b[c]d}e // corect
 * a[b{c}d]e} //incorect.
 */
#include <iostream>	 // cout, cin
#include <stack>	 // stack
#include <string>
using namespace std;

#pragma region Setup
bool balanced_parantheses(string);
string extract_parantheses(string);

string separator =
	"\n"
	"*********************************************************************\n";
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	cout << "13. Sa se verifice daca intr-o expresie se parantezele se inchid "
			"corect\n";
	string expression;

	while (true) {
		cout << "\nScrie o expresie continand paranteze: ";
		getline(cin, expression);
		string message = "nu ";
		if (balanced_parantheses(expression)) {
			message = "";
		}

		cout << "Parantezele " << message << "se inchid corect.";
		cout << separator;
	}
}

#pragma region Algorithms
/**
 * @brief Verifica daca parantezele dintr-o expresie se inchid corect
 * @param expression
 * @return bool
 */
bool balanced_parantheses(string expression) {
	expression = extract_parantheses(expression);
	int length = expression.length();

	// optimizare: un numar nul sau impar de paranteze nu se inchide corect
	if ((length == 0) || (length % 2 != 0)) {
		return false;
	}

	stack<char> parantheses;
	char bracket;

	// adauga in stiva parantezele de inceput
	for (int i = 0; i < length; i++) {
		if (expression[i] == '(' || expression[i] == '[' ||
			expression[i] == '{') {
			parantheses.push(expression[i]);
			continue;
		}

		// daca nu se gasesc paranteze de inceput
		if (parantheses.empty()) {
			return false;
		}

		// verifica potrivirea parantezelor
		switch (expression[i]) {
			case ')':
				bracket = parantheses.top();
				parantheses.pop();
				if (bracket != '(') {
					return false;
				}
				break;
			case ']':
				bracket = parantheses.top();
				parantheses.pop();
				if (bracket != '[') {
					return false;
				}
				break;
			case '}':
				bracket = parantheses.top();
				parantheses.pop();
				if (bracket != '{') {
					return false;
				}
				break;
		}
	}

	return (parantheses.empty());
}
#pragma endregion Algorithms

#pragma region Utils
/**
 * @brief Extrage parantezele dintr-un text, pastrand ordinea aparitiei lor
 * @param expression
 * @return string cu parantezele extrase
 */
string extract_parantheses(string expression) {
	string result;

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '(' || expression[i] == '[' ||
			expression[i] == '{' || expression[i] == ')' ||
			expression[i] == ']' || expression[i] == '}') {
			result += expression[i];
		}
	}

	return result;
}
#pragma endregion Utils