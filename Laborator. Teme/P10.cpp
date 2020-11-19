/**
 * 10. Folosind metoda divide et impera, scrieti o functie care sa determine
 * daca un tablou cu elemente intregi este ordonat crescator.
 */
#include <iostream>	 // cout, cin
#include <sstream>	 // istringstream
using namespace std;

#pragma region Setup
bool check_sorting(int[], int, int);

string separator =
	"\n"
	"*********************************************************************"
	"\n";
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	cout << "10. Folosind metoda divide et impera, scrieti o functie care sa "
			"determine daca un tablou cu elemente intregi este ordonat "
			"crescator.\n";

	const int list_size = 100;	// buffer
	int list[list_size] = {0};

	while (true) {
		cout << "\nScrie o lista de numere intregi separate prin spatiu: ";
		string input;
		getline(cin, input);
		istringstream buffer(input);

		int element;
		int counter = 0;
		while (true) {
			if (buffer >> element && counter < list_size) {
				list[counter] = element;
				counter++;
				continue;
			}
			// input nevalid
			break;
		}

		// la iesirea din while counter = numarul de elemente din lista, pentru
		// ca ultima incrementare are loc inaintea testarii conditiei din loop
		if (counter > 0) {
			cout << "L = {";
			for (int i = 0; i < counter - 1; i++) {
				cout << list[i] << ", ";
			}
			cout << list[counter - 1] << "}\n\n";

			cout << (check_sorting(list, 0, counter - 1)
						 ? "Lista este sortata crescator."
						 : "Lista nu este sortata crescator.");
		} else {
			cout << "L = {}\nLista este goala. Mai incearca!\n";
		}
		cout << separator;
	}
}

#pragma region Algorithms
/**
 * @brief Verifica daca o lista data este sortata crescator
 * @param list[] lista de verificat
 * @param first indexul primului element din lista
 * @param last indexul ultimului element din lista
 * @return bool
 */
bool check_sorting(int list[], int first, int last) {
	// lista are unul sau doua elemente
	if (last - first == 1 || last == 0) {
		return (list[first] <= list[last]);
	}

	// imparte lista in doua si aplica recursiv functia la cele doua jumatati
	int middle = (first + last) / 2;
	bool left = check_sorting(list, first, middle);
	bool right = check_sorting(list, middle, last);

	return (left && right);
}
#pragma endregion Algorithms