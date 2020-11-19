"""
Selection sort
"""
import lib_utils as lu

# lista de numere
array = [
    4, 78, 13, 45, 2, 90, 66, 34, 21, 32, 10, 7, 5, 102, 56, 11, 19, 23, 75, 88
]


def selection_sort(array):
	"""
	Sortează o listă folosind algoritmul selection sort.
	 param array: lista
	"""
	length = len(array)
	pivot = 0

	for i in range(length):
		print(f'\n#{i}:')  # pivotul curent
		lu.print_array(array, i, pivot, '+ ')  # lista la începutul iterației
		pivot = i
		j = i + 1
		for j in range(j, length):
			if array[j] < array[pivot]:
				pivot = j
		if pivot != i:
			(array[pivot], array[i]) = (array[i], array[pivot])
		lu.print_array(array, i, pivot, '->')  # lista la sfârșitul iterației


selection_sort(array)
print(f'\nLista sortată: {array}')