/**
 * 32. Scrieti un program in C care sa afiseze triunghiul lui Pascal pentru n
dat.
	1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
 */
#include <stdio.h>	// printf(), scanf()

#pragma region Setup
void print_pascal_triangle(int);

const int limit = 25;  // suficient pentru demonstratie
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	printf(
		"32. Scrieti un program in C care sa afiseze triunghiul lui Pascal "
		"pentru n dat.\n ");

	int number;
	while (1) {
		printf("\nScrie un numar pozitiv: ");
		if (!scanf("%d", &number) || (number < 1) || (number > limit)) {
			// fflush(stdin); // neportabil, nerecomandat...
			int c;
			while ((c = getchar()) != '\n' && (c != EOF)) {
				// consuma inputul ramas in buffer
			}
			printf("Numarul trebuie sa fie un intreg: 0 < n <= %d", limit);
			continue;
		}

		print_pascal_triangle(number);
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Afiseaza triunghiul lui Pascal pentru un numar dat de randuri
 * @param number
 */
void print_pascal_triangle(int number) {
	for (int row = 1; row <= number; row++) {
		int item = 1;

		// spatii pana la numere
		for (int i = 1; i < (number - row + 1); i++) {
			printf("  ");
		}

		// numerele de pe rand
		for (int i = 1; i <= row; i++) {
			printf("%d   ", item);
			item = item * (row - i) / i;
		}

		printf("\n");
	}
}
#pragma endregion Algorithms