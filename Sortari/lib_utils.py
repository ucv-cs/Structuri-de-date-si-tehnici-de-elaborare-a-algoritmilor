"""
Modul cu utilitare.

Notă: pentru a preveni crearea de foldere __pycache__ trebuie adăugată
variabila de sistem (environment variable): PYTHONDONTWRITEBYTECODE=1
"""


def print_array(array, index, next, marker='  '):
	"""
	Afișează conținutul unei liste, marcând și elementele ce se modifică.
	 param array: lista de afișat
	 param index: elementul comparat *
	 param next: elementul de modificat ^
	 param marker: symbol de afișat la începutul liniei
	"""
	result = ""
	separator = " "
	for i in range(len(array)):
		if i == index:
			result += f'{array[i]:3}' + '*' + separator
		elif i == next:
			result += f'{array[i]:3}' + '^' + separator
		else:
			result += f'{array[i]:3}' + ' ' + separator
	print(marker + "{" + result + "}")