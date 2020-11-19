/**
 * 45. Scrieti un program care calculeaza produsul primelor n numere naturale
 * recursiv.
 */
#include <iostream>	 // cout, cin
using namespace std;

#pragma region Setup
unsigned long long sum_naturals(unsigned long long);
void get_input(unsigned*);

int limit = 20;	 // 20! este suficient de mare
string separator =
	"\n"
	"*********************************************************************\n";
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	cout
		<< "45. Scrieti un program care calculeaza produsul primelor n numere\n"
		   "naturale recursiv.\n";
	unsigned number;  // -> 18.446.744.073.709.551.615

	while (true) {
		cout << "\nScrie un numar natural nenul: ";
		get_input(&number);

		cout << number << "! = " << sum_naturals(number);

		cout << separator;
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Genereaza produsul primelor n numere naturale nenule, folosind
 * recursiunea
 * @param number
 */
unsigned long long sum_naturals(unsigned long long number) {
	if ((number == 1) || (number == 0)) {
		return 1;
	} else {
		return number * sum_naturals(number - 1);
	}
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
		if ((cin >> temp) && (temp >= 0) && (temp <= limit)) {
			cin.ignore(1000, '\n');	 // 1000 e arbitrar ales
			break;
		}
		cout << "Numarul trebuie sa fie un intreg: 0 <= n <= " << limit
			 << "!\nMai incearca: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	*integer = temp;
}
#pragma endregion Utils