/**
 * 19. Creati o lista ce contine un anumit numar de numere reale. Scrieti o
 * functie ce introduce un nod ce contine diferenta fiecaror doua noduri vecine,
 * intre cele doua noduri.
 */
#include <ctype.h>	 // isalpha()
#include <stdio.h>	 // printf(), scanf()
#include <stdlib.h>	 // malloc()

#pragma region Setup
typedef float Data;	 // abstractizare?
typedef struct node {
	Data value;
	struct node* next;
} * Node;
typedef Node List;	// alias pentru a diferentia semantic intre lista si nod

void append_node(List*, Data);
void print_list(List);
void delete_list(List);
void insert_differences(List);
#pragma endregion Setup
/**
 * @brief Inceputul executiei
 */
int main() {
	printf(
		"19. Creati o lista ce contine un anumit numar de numere reale. "
		"Scrieti o functie ce introduce un nod ce contine diferenta fiecaror "
		"doua noduri vecine, intre cele doua noduri.\n");

	Data value;
	char terminator;
	while (1) {
		List list = NULL;

		// N.B. pentru a fi strict in acord cu cerinta, puteam rescrie codul
		// pentru a se introduce mai intai numarul de elemente din lista, apoi
		// fiecare element;
		// am pastrat pattern-ul folosit si la alte exercitii pentru ca este mai
		// flexibil si mai intuitiv
		printf("\nScrie o lista cu numere reale separate prin spatiu: ");
		while (
			scanf("%g%c", &value, &terminator)) {  // FIXME: %g abstractizare?
			append_node(&list, value);
			if (terminator == '\n' || isalpha(terminator)) {
				fflush(stdin);	// FIXME: nerecomandabil
				break;
			}
		}

		printf("\nLista initiala: ");
		print_list(list);

		printf("\nLista noua    : ");
		insert_differences(list);
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
 * @brief Intr-o lista data, intre fiecare doua noduri vecine adauga cate un nod
 * a carui valoare este diferenta valorilor nodurilor vecine initiale
 * @param node
 */
void insert_differences(List list) {
	// lista trebuie sa aiba cel putin doua elemente pentru a se putea rezolva
	// problema
	if (list == NULL || list->next == NULL) {
		return;
	}

	Node current = list;
	while (current->next) {
		Node second = current->next;

		Node node = (Node)malloc(sizeof(struct node));
		node->value = second->value - current->value;
		node->next = second;

		current->next = node;

		current = second;
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
		printf("%g ", temp->value);	 // FIXME: ar trebui generalizat formatul
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