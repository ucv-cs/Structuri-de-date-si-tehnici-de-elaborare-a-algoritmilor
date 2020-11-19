/**
 * 15. Creati doua liste: o lista ce contine numere pare si o lista ce contine
 * numere impare. Numerele se vor citi de la tastatura pana cand se introduce
 * -1.
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
void fill_odds_evens(List, List*, List*);
void print_list(List);
void delete_list(List);
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	printf(
		"15. Creati doua liste: o lista ce contine numere pare si o lista ce "
		"contine numere impare.\n");
	// N.B. am ignorat cerinta "Numerele se vor citi de la tastatura pana cand
	// se introduce -1." pentru ca nu pare a fi esentiala si pentru ca am deja o
	// modalitate mai naturala de interceptare a finalului de input (\n in loc
	// de -1)

	Data value;
	char terminator;
	while (1) {
		List list = NULL;
		List odds = NULL;
		List evens = NULL;

		printf("\nScrie o lista cu numere intregi separate prin spatii: ");
		while (
			scanf("%d%c", &value, &terminator)) {  // FIXME: %d abstractizare?
			append_node(&list, value);
			if (terminator == '\n' || isalpha(terminator)) {
				break;
			}
		}
		fflush(stdin);	// FIXME: nerecomandabil, neportabil in Unix*

		printf("\nLista initiala: ");
		print_list(list);

		fill_odds_evens(list, &odds, &evens);

		printf("\nLista cu numere impare: ");
		print_list(odds);

		printf("\nLista cu numere pare: ");
		print_list(evens);

		delete_list(list);
		delete_list(odds);
		delete_list(evens);

		printf("\n***********************************************\n");
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Pornind de la o lista data, adauga elementele pare intr-o lista si
 * elementele impare in alta
 * @param base lista initiala data
 * @param odds lista cu numere impare
 * @param evens lista cu numere pare
 */
void fill_odds_evens(List base, List* odds, List* evens) {
	Node current = base;
	while (current) {
		if (current->value % 2 == 0) {
			append_node(evens, current->value);
		} else {
			append_node(odds, current->value);
		}
		current = current->next;
	}
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
		temp = NULL;
	}
}
#pragma endregion Algorithms