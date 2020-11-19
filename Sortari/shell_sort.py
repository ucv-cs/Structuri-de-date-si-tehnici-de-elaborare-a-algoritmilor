"""
Shell sort
"""
import lib_utils as lu

# lista de numere
array = [
    4, 78, 13, 45, 2, 90, 66, 34, 21, 32, 10, 7, 5, 102, 56, 11, 19, 23, 75, 88
]


def shell_sort(array, gap=0):
	"""
	Sortează o listă folosind algoritmul shell sort.
	 param array: lista
	 param gap: distanța între
	"""
	length = len(array)
	if gap < 0 or gap > length or not isinstance(gap, int):
		print(f"Gap este în afara limitelor posibile: 0 și {length}!")
		return
	gap = length // 2 if gap == 0 else gap
	counter = 0  # contor pentru numărarea iterațiilor

	while gap > 0:
		for i in range(gap, length):
			print(f'\n#{counter}:')  # indexul curent
			temp = array[i]
			j = i
			lu.print_array(array, i, j, '+ ')  # lista la începutul iterației
			while j >= gap and array[j - gap] > temp:
				array[j] = array[j - gap]
				lu.print_array(array, i, j, '->')  # lista modificată
				j -= gap
			array[j] = temp
			lu.print_array(array, i, j, '  ')  # lista la sfârșitul iterației
			counter += 1  #
		gap //= 2


shell_sort(array)
print(f'\nLista sortată: {array}')