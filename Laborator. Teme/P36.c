/**
 * 36. Implementati ShellSort pentru liste simplu inlantuite.
 */
#include <ctype.h>	 // isalpha()
#include <stdio.h>	 // printf(), scanf()
#include <stdlib.h>	 // malloc()

#pragma region Setup
typedef int Data;  // abstractizare?
typedef struct node {
	Data value;
	struct node* next;
} * Node;
typedef Node List;	// alias pentru a diferentia semantic intre lista si nod

void append_node(List*, Data);
int get_list_length(List list);
List shellsort_list(List);
void print_list(List);
void delete_list(List);
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	printf("36. Implementati ShellSort pentru liste simplu inlantuite.\n");

	Data value;
	char terminator;
	while (1) {
		List list = NULL;

		printf("\nScrie o lista cu elemente separate prin spatiu: ");
		while (
			scanf("%d%c", &value, &terminator)) {  // FIXME: %d abstractizare?
			append_node(&list, value);
			if (terminator == '\n' || isalpha(terminator)) {
				fflush(stdin);	// FIXME: nerecomandabil, neportabil in Unix*
				break;
			}
		}

		printf("\nLista initiala : ");
		print_list(list);

		printf("\nLista sortata  : ");
		print_list(shellsort_list(list));

		delete_list(list);
		fflush(stdin);	// FIXME: nerecomandabil, neportabil in Unix*

		printf(
			"\n****************************************************************"
			"*****\n");
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Sorteaza o lista folosind algoritmul ShellSort
 * @param list
 */
List shellsort_list(List list) {
	if (list == NULL || list->next == NULL) {
		return list;
	}

	if (list) {
		int size = get_list_length(list);
		Node current_node = list;

		// distanta (gap) intre elementele verificate este egala cu jumatate de
		// lista
		for (int gap = size / 2; gap > 0; gap /= 2) {
			for (int i = gap; i > 0; i--) {
				for (int j = gap - i; j < size; j += gap) {
					current_node = list;

					int k;
					for (k = 0; k < j; k++) {
						current_node = current_node->next;
					}

					Node node = current_node;
					int temp = k + gap;
					while (node) {
						while (k < temp) {
							if (node) {
								node = node->next;
								k++;
							} else {
								break;
							}
						}

						if (node) {
							if (current_node->value > node->value) {
								// inlocuieste valorile intre ele, nu nodurile
								Data temp = current_node->value;
								current_node->value = node->value;
								node->value = temp;
							}
						}

						temp += gap;
					}
				}
			}
		}
	}

	return list;
}

/**
 * @brief Calculeaza numarul de noduri dintr-o lista
 * @param list
 * @return numarul de noduri
 */
int get_list_length(List list) {
	List temp = list;

	int counter;
	for (counter = 0; temp; counter++) {
		temp = temp->next;
	}

	return counter;
}

/**
 * @brief Adauga un nod la lista
 * @param list
 * @param value
 */
void append_node(List* list, Data value) {
	// creeaza nodul cu valoarea data
	Node node = (Node)malloc(sizeof(struct node));
	node->value = value;
	node->next = NULL;

	// adauga nodul dupa ultimul nod din lista
	if (*list == NULL) {  // lista goala
		*list = node;
	} else {  // iteram pana la ultimul nod
		Node current = *list;
		while (current->next) {
			current = current->next;
		}
		current->next = node;
	}
}

/**
 * @brief Afiseaza continutul unei liste
 * @param list
 */
void print_list(List list) {
	Node temp = list;
	while (temp) {
		printf("%d ", temp->value);	 // FIXME: ar trebui generalizat formatul
		temp = temp->next;
	}
}

/**
 * @brief Marcheaza pentru stergere memoria folosita de o lista
 * @param list
 */
void delete_list(List list) {
	Node temp;
	while (list) {
		temp = list;
		list = list->next;
		free(temp);
	}
}
#pragma endregion Algorithms