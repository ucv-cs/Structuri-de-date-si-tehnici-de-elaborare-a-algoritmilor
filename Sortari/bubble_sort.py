"""
Bubble sort
"""
import lib_utils as lu

# lista de numere
array = [
    4, 78, 13, 45, 2, 90, 66, 34, 21, 32, 10, 7, 5, 102, 56, 11, 19, 23, 75, 88
]


def bubble_sort(array):
	"""
	Sortează o listă folosind algoritmul bubble sort.
	 param array: lista
	"""
	length = len(array)

	for i in range(length):
		print(f'\n#{i}:')  # indexul curent
		for j in range(length - i - 1):
			lu.print_array(array, j, j + 1, '+ ')  # lista la începutul iterației
			if array[j] > array[j + 1]:
				array[j], array[j + 1] = array[j + 1], array[j]
				lu.print_array(array, j, j + 1, '->')  # lista modificată în iterație


bubble_sort(array)
print(f'\nLista sortată: {array}')