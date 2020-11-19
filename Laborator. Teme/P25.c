/**
 * 25. Sa se scrie un program care afiseaza toate permutarile unui string. (ABC:
 * ABC, ACB, BAC, BCA, CAB, CBA). Folositi un algoritm de backtracking.
 */
#include <stdio.h>	 // printf()
#include <string.h>	 // strlen()

#pragma region Setup
void shuffle(char*, int, int);
void swap(char*, char*);
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	printf(
		"25. Sa se scrie un program care afiseaza toate permutarile unui "
		"string. (ABC: ABC, ACB, BAC, BCA, CAB, CBA). Folositi un algoritm de "
		"backtracking.\n");
	char text[] = "ABCDEF";
	int size = strlen(text);

	shuffle(text, 0, size - 1);

	getchar();
	return 0;
}

#pragma region Algorithms
/**
 * @brief Permuta recursiv caracterele dintr-un text in format C-string
 * @param text
 * @param start
 * @param end
 */
void shuffle(char* text, int start, int end) {
	if (start == end)
		printf("%s\n", text);
	else {
		for (int i = start; i <= end; i++) {
			swap((text + start), (text + i));
			shuffle(text, start + 1, end);
			swap((text + start), (text + i));
		}
	}
}

/**
 * @brief Schimba intre ele doua caractere
 * @param first
 * @param last
 */
void swap(char* first, char* last) {
	char temp = *first;
	*first = *last;
	*last = temp;
}
#pragma endregion Algorithms