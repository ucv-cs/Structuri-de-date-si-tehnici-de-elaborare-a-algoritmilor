/**
 * 38. Verificati daca un numar este palindrom.
 */
#include <climits>	 // UINT_MAX (gcc in Linux)
#include <iostream>	 // cout, cin
using namespace std;

#pragma region Setup
bool is_palindrome(unsigned);
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
	cout << "38. Verificati daca un numar este palindrom.\n";
	unsigned number;  // N.B. se putea inversa si ca un string...

	while (true) {
		cout << "\nScrie un numar pozitiv: ";
		get_input(&number);

		string palindrome = "nu ";
		if (is_palindrome(number)) {
			palindrome = "";
		}
		cout << number << " " << palindrome << "este palindrom.";

		cout << separator;
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Verifica daca un numar este palindrom, comparand numarul cu varianta
 * sa inversata
 * @param number
 * @return bool
 */
bool is_palindrome(unsigned number) {
	unsigned result = 0;
	unsigned initial_number = number;

	while (number != 0) {
		result = result * 10 + number % 10;
		number /= 10;
	}
	return (result == initial_number);
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