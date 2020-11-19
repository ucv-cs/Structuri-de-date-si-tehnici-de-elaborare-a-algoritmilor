/**
 * 41. Scrieti un program care interschimba 3 valori. (input: a=2, b=3, c=4,
 * output: a=3, b=4, c=2).
 */
#include <climits>	 // INT_MAX (gcc in Linux)
#include <iostream>	 // cout, cin
using namespace std;

#pragma region Setup
void switch_values(int&, int&, int&);
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
	cout << "41. Scrieti un program care interschimba 3 valori. (input: a = 2, "
			"b = 3, c = 4, output: a = 3, b = 4, c = 2).\n";
	int a;
	int b;
	int c;

	while (true) {
		cout << "\nScrie numerele:\n";
		cout << "\ta = ";
		get_input(&a);
		cout << "\tb = ";
		get_input(&b);
		cout << "\tc = ";
		get_input(&c);

		switch_values(a, b, c);

		cout << "\nRezultatul inlocuirii:\n\ta = " << a;
		cout << "\n\tb = " << b;
		cout << "\n\tc = " << c;

		cout << separator;
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Schimba intre ele valorile parametrilor (nealeatoriu!), dupa exemplul
 * din enunt
 * @param a
 * @param b
 * @param c
 */
void switch_values(int& a, int& b, int& c) {
	int temp = a;
	a = b;
	b = c;
	c = temp;
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
		cout << "Numarul trebuie sa fie un intreg: 0 < n <= " << limit
			 << "!\nMai incearca: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	*integer = temp;
}
#pragma endregion Utils