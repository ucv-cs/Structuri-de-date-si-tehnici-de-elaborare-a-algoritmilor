/**
 * 29. Scrieti un program in C care sa contina o functie recursiva si o functie
 * iterativa count_spaces(char *s) care numara cate spatii libere apar intr-un
 * string.
 */
#include <stdio.h>	 // printf(), fgets()
#include <string.h>	 // strlen()

#pragma region Setup
unsigned count_spaces_recursively(char*);
unsigned count_spaces_iteratively(char*);
void flush_stdin();

const unsigned size = 100;
char initial_text[size];
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	printf(
		"29. Scrieti un program in C care sa contina o functie recursiva si o "
		"functie iterativa count_spaces(char *s) care numara cate spatii "
		"libere apar intr-un string.\n ");

	while (1) {
		printf("\nScrie textul de analizat: ");
		fgets(initial_text, size, stdin);
		flush_stdin();

		printf("\nNumar de spatii (recursiv): %d",
			   count_spaces_recursively(initial_text));

		printf("\nNumar de spatii (iterativ): %d",
			   count_spaces_iteratively(initial_text));

		printf("\n---------------------------------\n");
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Intr-un string dat afla numarul de spatii (recursiv)
 * @param text
 * @returns numarul de spatii gasite
 */
unsigned count_spaces_recursively(char* text) {
	if (*text == '\0') {
		return 0;
	}

	unsigned counter = 0;
	if (text[0] == ' ') {
		counter = 1;
	}

	return count_spaces_recursively(text + 1) + counter;
}

/**
 * @brief Intr-un string dat afla numarul de spatii (iterativ)
 * @param text
 * @returns numarul de spatii gasite
 */
unsigned count_spaces_iteratively(char* text) {
	unsigned counter = 0;
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == ' ') {
			counter++;
		}
	}

	return counter;
}
#pragma endregion Algorithms

#pragma region Utils
/**
 * @brief Consuma inputul ramas in bufferul stdin
 */
void flush_stdin() {
	fflush(stdin);	// FIXME: neportabil pe platformele non-Windows
}
#pragma endregion Utils