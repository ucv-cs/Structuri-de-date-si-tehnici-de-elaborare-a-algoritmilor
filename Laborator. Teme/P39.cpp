/**
 * 39. Verificati daca un numar este par sau impar.
 */
#include <climits>	 // INT_MAX (gcc in Linux)
#include <iostream>	 // cout, cin
using namespace std;

#pragma region Setup
void get_input(int*);

int limit = INT_MAX;
string separator =
	"\n"
	"*********************************************************************\n";
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	int number;

	cout << "39. Verificati daca un numar este par sau impar.\n";
	while (true) {
		cout << "\nScrie un numar intreg: ";
		get_input(&number);
		string parity = "impar";
		if (number % 2 == 0) {
			parity = "par";
		}
		cout << "\t" << number << " este " + parity;

		cout << separator;
	}

	return 0;
}

#pragma region Utils
/**
 * @brief Obtine de la utilizator un numar intreg valabil si il aloca variabilei
 * primite (valideaza inputul)
 * @param integer pointer la variabila care va folosi valoarea introdusa
 */
void get_input(int* integer) {
	int temp;

	while (true) {
		// FIXME: input de tip 8asd e validat ca 8
		if ((cin >> temp) && (temp >= -limit) && (temp <= limit)) {
			cin.ignore(1000, '\n');	 // 1000 e arbitrar ales
			break;
		}
		cout << "Numarul trebuie sa fie un intreg: " << -limit
			 << " <= n <= " << limit << "!\nMai incearca: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	*integer = temp;
}
#pragma endregion Utils