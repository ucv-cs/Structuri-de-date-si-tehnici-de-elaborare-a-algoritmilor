/**
 * 34. Implementati QuickSort pentru liste simplu inlantuite.
 */
#include <ctype.h>	 // isalpha()
#include <stdio.h>	 // printf(), scanf()
#include <stdlib.h>	 // malloc(), rand()
#include <time.h>	 // srand()

#pragma region Setup
typedef int Data;  // abstractizare?
typedef struct node {
	Data value;
	struct node* next;
} * Node;
typedef Node List;	// alias pentru a diferentia semantic intre lista si nod

void append_node(List*, Data);
int get_list_length(List list);
Node _select_pivot(List list);
List quick_sort_list(List);
void print_list(List);
void delete_list(List);
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	printf("34. Implementati QuickSort pentru liste simplu inlantuite.\n");

	srand(time(0));
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
		print_list(quick_sort_list(list));

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
 * @brief Sorteaza o lista folosind algoritmul QuickSort
 * @param list
 */
List quick_sort_list(List list) {
	if (get_list_length(list) <= 1) {
		return list;
	}
	Node less = NULL;
	Node more = NULL;
	Node next = NULL;
	Node end = NULL;
	Node temp = NULL;

	// alege pivotul si apoi il inlatura din lista
	Node pivot = _select_pivot(list);
	while (list) {
		next = list->next;
		if (list->value != pivot->value) {
			list->next = temp;
			temp = list;
		}
		list = next;
	}

	// adauga in listele less si more elementele mai mici, respectiv, mai mari
	// decat pivotul
	while (temp) {
		next = temp->next;
		if (temp->value < pivot->value) {
			temp->next = less;
			less = temp;
		} else {
			temp->next = more;
			more = temp;
		}
		temp = next;
	}

	// foloseste quicksort recursiv pentru listele less si more
	less = quick_sort_list(less);
	more = quick_sort_list(more);

	// recombina rezultatele
	if (less) {
		end = less;
		while (end->next) {
			end = end->next;
		}
		pivot->next = more;
		end->next = pivot;
		// less = less + pivot + more
		return less;
	} else {
		pivot->next = more;
		// pivot = pivot + more
		return pivot;
	}
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
 * @brief Intr-o lista data alege un nod ca pivot
 * @param list
 * @returns nodul din lista ales ca pivot
 */
Node _select_pivot(List list) {
	Node pivot = list;
	int list_length = get_list_length(list);

	// index gasit aleatoriu, dar poate fi folosita orice alta
	// schema (ex. a lui Hoare: jumatatea listei; a lui Lomuto: ultimul element
	// al listei)
	int k = rand() % list_length;

	for (int i = 0; i < k; i++) {
		pivot = pivot->next;
	}

	return pivot;
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