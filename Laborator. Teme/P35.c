/**
 * 35. Implementati Insertion sort pentru liste simplu inlantuite.
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
List insertion_sort_list(List);
void print_list(List);
void delete_list(List);
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	printf("35. Implementati Insertion sort pentru liste simplu inlantuite.\n");

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
		print_list(insertion_sort_list(list));

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
 * @brief Sorteaza o lista folosind algoritmul Insertion sort
 * @param list
 */
List insertion_sort_list(List list) {
	if (list == NULL || list->next == NULL) {
		return list;
	}

	Node sorted_list = NULL;
	while (list) {
		Node current_node = list;
		list = list->next;
		if (sorted_list == NULL || current_node->value < sorted_list->value) {
			current_node->next = sorted_list;
			sorted_list = current_node;
		} else {
			Node temp = sorted_list;
			while (temp) {
				if (temp->next == NULL ||
					current_node->value < temp->next->value) {
					current_node->next = temp->next;
					temp->next = current_node;
					break;
				}
				temp = temp->next;
			}
		}
	}

	return sorted_list;
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