/**
 * 40. Scrieti un program care afla maximul din 4 numere.
 */
#include <climits>	 // INT_MAX (gcc in Linux)
#include <iostream>	 // cout, cin
using namespace std;

#pragma region Setup
int maximum_value(int*, int);
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
	cout << "40. Scrieti un program care afla maximul din 4 numere.\n";
	// presupunem ca numerele sunt intregi...
	int list_size = 4;	// daca cerinta s-ar schimba (ex. pentru 10 numere) doar
						// aceasta variabila ar trebui modificata
	int list[list_size] = {0};

	while (true) {
		cout << "\nScrie " << list_size << " numere:\n";
		for (int i = 0; i < list_size; i++) {
			cout << "\t[" << i + 1 << "] = ";
			get_input(&list[i]);
		}

		cout << "\nMaximul listei: " << maximum_value(list, list_size);

		cout << separator;
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Calculeaza maximul unei liste de numere (fara max()); functia este
 * reutilizabila pentru orice numar de elemente in lista (nu doar 4)
 * @param list
 * @param list_size
 * @return maximul
 */
int maximum_value(int* list, int list_size) {
	int maximum = list[0];
	for (int i = 1; i < list_size; i++) {
		if (list[i] > maximum) {
			maximum = list[i];
		}
	}
	return maximum;
}
#pragma endregion Algorithms

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