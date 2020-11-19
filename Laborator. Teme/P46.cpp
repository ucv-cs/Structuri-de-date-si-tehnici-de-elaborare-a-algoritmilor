/**
 * 46. Scrieti un program care rescrie invers o propozitie folosind
 * recursivitate. ("afara este foarte cald", dlac etraof etse arafa).
 */
#include <iostream>	 // cout, cin
using namespace std;

#pragma region Setup
string revert_string(string);

string separator =
	"\n"
	"*********************************************************************\n";
#pragma endregion Setup

/**
 * @brief Inceputul executiei
 */
int main() {
	cout << "46. Scrieti un program care rescrie invers o propozitie folosind\n"
			"recursivitate. ('afara este foarte cald', dlac etraof etse\n"
			"arafa).\n";
	string proposition;

	while (true) {
		cout << "\nScrie o propozitie: ";
		getline(cin, proposition);

		cout << revert_string(proposition);

		cout << separator;
	}

	return 0;
}

#pragma region Algorithms
/**
 * @brief Inverseaza un text, folosind recursiunea
 * @param text
 */
string revert_string(string text) {
	if (text.size() == 0) {
		return "";
	} else {
		char first_char = text.at(0);
		return revert_string(text.substr(1)) + first_char;
	}
}
#pragma endregion Algorithms