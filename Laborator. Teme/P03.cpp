/**
 * 3. Se citeste un numar n. Generati si afisati toate combinatiile de cate n
 * cifre binare care nu au doua cifre de 1 alaturate.
 */
#include <iostream>	 // cout, cin
using namespace std;

#pragma region Setup
// prototipuri de functii
void get_input(int*);
void print_result(int*, int);
void generate_bits(int);

// variabile globale
int number;			   // numarul de biti dintr-o combinatie
const int limit = 32;  // evita o executie mult prea lunga; int = 32 biti ()
int combination[limit] = {0};  // container pentru fiecare solutie
string separator =
	"\n "
	"*********************************************************************\n";
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	cout << "3. Se citeste un numar n. Generati si afisati toate combinatiile\n"
			"de cate n cifre binare care nu au doua cifre de 1 alaturate.\n";
	while (true) {
		cout << "\nScrie un numar natural nenul: ";
		get_input(&number);

		generate_bits(0);

		cout << separator;
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Genereaza bit cu bit elementele combinatiei, folosind recursiunea
 * @param current_position
 */
void generate_bits(int current_position) {
	if (current_position == number) {
		print_result(combination, number);
	} else {
		for (int i = 0; i < 2; i++) {
			if ((i == 0) || (combination[current_position - 1] == 0)) {
				combination[current_position] = i;
				generate_bits(current_position + 1);
			}
		}
	}
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

/**
 * @brief Afiseaza rezultatul: o singura combinatie conform cerintei
 * @param list lista de afisat
 * @param list_size dimensiunea listei
 */
void print_result(int* list, int list_size) {
	for (int i = 0; i < list_size; i++) {
		cout << list[i];
	}
	cout << "\n";
}
#pragma endregion Utils