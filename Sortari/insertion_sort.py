"""
Insertion sort
"""
import lib_utils as lu

# lista de numere
array = [
    4, 78, 13, 45, 2, 90, 66, 34, 21, 32, 10, 7, 5, 102, 56, 11, 19, 23, 75, 88
]


def insertion_sort(array):
	"""
	Sortează o listă folosind algoritmul insertion sort.
	 param array: lista
	"""
	length = len(array)

	for i in range(1, length):
		temp = array[i]
		print(f'\n#{i}: {temp}')  # indexul curent
		j = i
		lu.print_array(array, i, j, '+ ')  # lista la începutul iterației
		while (j > 0) and (array[j - 1] >= temp):
			array[j] = array[j - 1]
			j -= 1
		array[j] = temp
		lu.print_array(array, i, j, '->')  # lista la sfârșitul iterației


insertion_sort(array)
print(f'\nLista sortată: {array}')