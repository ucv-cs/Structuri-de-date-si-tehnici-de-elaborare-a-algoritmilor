/**
 * 33. Implementati MergeSort pentru liste simplu inlantuite.
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
void push_node(List*, int);
List _join_sorted_lists(List, List);  // _ este prefix pentru functii utilitare
void _split_list(List, List*, List*);
void merge_sort_list(List*);
void print_list(List);
void delete_list(List);
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	printf("33. Implementati MergeSort pentru liste simplu inlantuite.\n");

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

		merge_sort_list(&list);
		printf("\nLista sortata  : ");
		print_list(list);

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
 * @brief Sorteaza o lista folosind algoritmul MergeSort
 * @param list
 */
void merge_sort_list(List* list) {
	if (*list == NULL || (*list)->next == NULL) {
		return;
	}

	// imparte lista in doua jumatati
	List first_half;
	List second_half;
	_split_list(*list, &first_half, &second_half);

	// sorteaza recursiv jumatatile
	merge_sort_list(&first_half);
	merge_sort_list(&second_half);

	// jumatatile sunt sortate, deci pot fi reunite
	*list = _join_sorted_lists(first_half, second_half);
}

/**
 * @brief Imparte o lista in doua
 * @param list
 * @param first_half
 * @param second_half
 */
void _split_list(List list, List* first_half, List* second_half) {
	// lista are sub 2 noduri
	if (list == NULL || list->next == NULL) {
		*first_half = list;
		*second_half = NULL;
		return;
	}

	List first = list;
	List second = list->next;

	// first - 1 nod; second - 2 noduri
	while (second) {
		second = second->next;
		if (second) {
			first = first->next;
			second = second->next;
		}
	}

	*first_half = list;
	*second_half = first->next;
	first->next = NULL;
}

/**
 * @brief Combina doua liste sortate ascendent si returneaza lista rezultanta
 * sortata
 * @param first_list
 * @param second_list
 */
List _join_sorted_lists(List first_list, List second_list) {
	if (first_list == NULL) {
		return second_list;
	} else if (second_list == NULL) {
		return first_list;
	}

	List result = NULL;

	if (first_list->value <= second_list->value) {
		result = first_list;
		result->next = _join_sorted_lists(first_list->next, second_list);
	} else {
		result = second_list;
		result->next = _join_sorted_lists(first_list, second_list->next);
	}

	return result;
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
 * @brief Insereaza un nod la inceputul unei liste date
 * @param list
 * @param value
 */
void push_node(List* list, int value) {
	Node node = (Node)malloc(sizeof(struct node));
	node->value = value;
	node->next = *list;
	*list = node;
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