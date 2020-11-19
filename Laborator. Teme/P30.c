/**
 * 30. Scrieti un program in C care sa contina o functie recursiva si o functie
 * iterativa replace(char *s, char from, char to) care schimba toate aparitiile
 * lui from din s in to. (replace(steve, e, a) = stava).
 */
#include <stdio.h>	 // printf(), scanf(), fgets(), getchar()
#include <stdlib.h>	 // malloc()
#include <string.h>	 // strlen(), strcpy()

#pragma region Setup
const unsigned size = 100;
void replace_recursively(char*, char, char);
void replace_iteratively(char*, char, char);
void flush_stdin();
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	printf(
		"30. Scrieti un program in C care sa contina o functie recursiva si o "
		"functie iterativa replace(char *s, char from, char to) care schimba "
		"toate aparitiile lui from din s in to. (replace(steve, e,a) = "
		"stava).\n ");

	while (1) {
		char initial_text[size];
		char recursive_text[size];
		char iterative_text[size];
		char from;
		char to;
		printf("\nScrie textul de modificat: ");
		fgets(initial_text, size, stdin);
		flush_stdin();
		printf("Scrie caracterul de inlocuit: ");
		from = getchar();
		flush_stdin();

		printf("Scrie caracterul cu care se inlocuieste: ");
		to = getchar();
		flush_stdin();

		strcpy(recursive_text, initial_text);
		replace_recursively(recursive_text, from, to);
		printf("\nTextul modificat recursiv:\n\t%s", recursive_text);

		strcpy(iterative_text, initial_text);
		replace_iteratively(iterative_text, from, to);
		printf("\nTextul modificat iterativ:\n\t%s", iterative_text);

		printf("\nTextul initial:\n\t%s", initial_text);
		printf("\n---------------------------------\n");
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Intr-un string dat inlocuieste recursiv doua caractere date
 * @param text stringul dat
 * @param from caracter de inlocuit
 * @param to caracter cu care se inlocuieste
 */
void replace_recursively(char* text, char from, char to) {
	if (*text == '\0') {
		return;
	}

	if (*text == from) {
		*text = to;
	}

	replace_recursively(text + 1, from, to);
}

/**
 * @brief Intr-un string dat inlocuieste iterativ doua caractere date
 * @param text stringul dat
 * @param from caracter de inlocuit
 * @param to caracter cu care se inlocuieste
 */
void replace_iteratively(char* text, char from, char to) {
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == from) {
			text[i] = to;
		}
	}
}
#pragma endregion Algorithms

#pragma region Utils
/**
 * @brief Consuma inputul ramas in bufferul stdin
 */
void flush_stdin() {
	/* 	int c;
		while ((c = getchar()) != '\n' && (c != EOF)) {
		} */
	fflush(stdin);	// FIXME: neportabil pe platformele non-Windows
}
#pragma endregion Utils