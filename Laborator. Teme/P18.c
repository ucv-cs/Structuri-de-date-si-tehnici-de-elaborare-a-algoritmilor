/**
 * 18. Sa se construiasca o lista liniara simplu inlantuita cu elemente numere
 * intregi. Sa se stearga toate numerele pare.
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
void print_list(List);
void delete_list(List);
void delete_even_values(List*);
#pragma endregion Setup
/**
 * @brief Inceputul executiei
 */
int main() {
	printf(
		"18. Sa se construiasca o lista liniara simplu inlantuita cu elemente "
		"numere intregi. Sa se stearga toate numerele pare.\n");

	Data value;
	char terminator;
	while (1) {
		List list = NULL;

		printf("\nScrie o lista cu numere intregi separate prin spatiu: ");
		while (
			scanf("%d%c", &value, &terminator)) {  // FIXME: %d abstractizare?
			append_node(&list, value);
			if (terminator == '\n' || isalpha(terminator)) {
				fflush(stdin);	// FIXME: nerecomandabil
				break;
			}
		}

		printf("\nLista initiala  : ");
		print_list(list);

		printf("\nLista modificata: ");
		delete_even_values(&list);
		print_list(list);

		delete_list(list);
		fflush(stdin);	// FIXME: nerecomandabil

		printf(
			"\n****************************************************************"
			"*****\n");
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Sterge nodurile cu valori pare dintr-o lista data
 * @param node
 */
void delete_even_values(List* list) {
	Node* current = list;

	while (*current) {
		// ignora nodurile cu valoare impara: n % 2 != 0, deci true
		if ((*current)->value % 2) {
			current = &(*current)->next;
			continue;
		}

		Node temp = *current;
		*current = temp->next;
		free(temp);
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
	}
}
#pragma endregion Algorithms