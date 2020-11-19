/**
 * 43. Verificati daca un numar poate fi scris ca suma a doua numere prime.
 */
#include <iostream>	 // cout, cin
using namespace std;

#pragma region Setup
bool test_prime_components(unsigned, unsigned&, unsigned&);
bool is_prime(unsigned);
void get_input(unsigned*);

int limit = 3e4;  // valoare inca viabila pe 64 biti
string separator =
	"\n"
	"*********************************************************************\n";
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	cout << "43. Verificati daca un numar poate fi scris ca suma a doua numere "
			"prime.\n";
	unsigned number;
	unsigned first_term = 0;
	unsigned second_term = 0;
	while (true) {
		cout << "\nScrie numarul de verificat: ";
		get_input(&number);

		if (test_prime_components(number, first_term, second_term)) {
			cout << number << " = " << first_term << " + " << second_term;
		} else {
			cout << number << " nu poate fi scris ca suma de numere prime.";
		}

		cout << separator;
		first_term = 0;
		second_term = 0;
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Verifica daca un numar dat poate fi scris ca suma a doua numere prime;
 * daca da, atunci returneaza termenii primi prin referintele primite
 * @param number
 * @param first_term
 * @param second_term
 */
bool test_prime_components(unsigned number, unsigned& first_term,
						   unsigned& second_term) {
	if (number <= 2) {
		return false;
	}

	// adauga intr-o lista dinamica toate numerele prime pana la numarul dat
	int prime_count = number / 2;  // pana la N pot fi cel mult N/2 numere prime
	unsigned* list = new unsigned[prime_count];
	list[0] = 2;
	int list_index = 0;
	for (int i = 3; i < number; i += 2) {
		if (is_prime(i)) {
			list_index++;
			list[list_index] = i;
		}
	}

	bool result = false;

	// scade succesiv din numarul dat fiecare numar prim gasit; daca rezultatul
	// este in lista, atunci numarul dat este o suma de numere prime
	for (int i = 0; i <= list_index; i++) {
		int difference = number - list[i];
		for (int j = 0; j <= list_index; j++) {
			if (difference == list[j]) {
				first_term = list[j];
				second_term = list[i];
				result = true;
				break;
			}
		}
	}

	delete[] list;
	return result;
}

/**
 * @brief Verifica daca un numar este prim
 * @param number
 */
bool is_prime(unsigned number) {
	if (number < 2) {
		return false;
	} else if (number == 2) {
		return true;
	}

	for (int i = 3; i * i <= number; i += 2) {
		if (number % i == 0) {
			return false;
		}
	}

	return true;
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