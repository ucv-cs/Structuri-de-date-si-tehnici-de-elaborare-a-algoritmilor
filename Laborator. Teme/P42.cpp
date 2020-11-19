/**
 * 42. Scrieti un program care returneaza un numar inversat (ex. input 1234567,
 * ouput 7654321).
 */
#include <climits>	 // UINT_MAX (gcc in Linux)
#include <iostream>	 // cout, cin
using namespace std;

#pragma region Setup
string revert_integer(unsigned);
void get_input(unsigned*);

unsigned limit = UINT_MAX;
string separator =
	"\n"
	"*********************************************************************\n";
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	cout << "42. Scrieti un program care returneaza un numar inversat (ex. "
			"input 1234567, ouput 7654321).\n";
	unsigned number;  // N.B. se putea inversa si ca un string...

	while (true) {
		cout << "\nScrie un numar pozitiv: ";
		get_input(&number);

		cout << "                        "<<revert_integer(number);

		cout << separator;
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Inverseaza un numar
 * @param number
 * @return string cu numarul inversat
 */
string revert_integer(unsigned number) {
	string result;
	while (number != 0) {
		result += to_string(number % 10);
		number /= 10;
	}
	return result;
}
#pragma endregion Algorithms

#pragma region Utils
/**
 * @brief Obtine de la utilizator un numar intreg valabil si il aloca variabilei
 * primite (valideaza inputul)
 * @param integer pointer la variabila care va folosi valoarea introdusa
 */
void get_input(unsigned* integer) {
	unsigned temp;

	while (true) {
		// FIXME: input de tip 8asd e validat ca 8
		if ((cin >> temp) && (temp > 0) && (temp <= limit)) {
			cin.ignore(1000, '\n');	 // 1000 e arbitrar ales
			break;
		}
		cout << "Numarul trebuie sa fie un intreg: 0 < n <= " << limit
			 << "!\nMai incearca: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	*integer = temp;
}
#pragma endregion Utils