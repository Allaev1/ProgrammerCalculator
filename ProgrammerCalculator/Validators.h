#include <iostream>
#include <string>

using namespace std;

class Validator { // validator for numbers
private:
	string symbols_for_binary{ "01" };
	string symbols_for_hex{ "0123456789ABCDEF" };
	string symbols_for_dec{ "0123456789" };
	string symbols_for_octal{ "01234567" };
public:
	bool is_correct_binary(string string_for_check) {
		for (int i = 0; i < string_for_check.length(); ++i) {
			int dismatch = 0;

			for (int k = 0; k < symbols_for_binary.length(); ++k) {
				if (string_for_check[i] == symbols_for_binary[k])
					break;
				else {
					dismatch++;

					if (dismatch == 2) {
						cout << "There is invalid symbol found in position " << i << endl;
						return false;
					}
				}
			}
		}

		return true;
	}

	bool is_correct_hex(string string_for_check) {
		for (int i = 0; i < string_for_check.length(); ++i) {
			int dismatch = 0;

			for (int k = 0; k < symbols_for_hex.length(); ++k) {
				if (string_for_check[i] == symbols_for_hex[k])
					break;
				else {
					dismatch++;

					if (dismatch == 16) {
						cout << "There is invalid symbol found in position " << i << endl;
						return false;
					}
				}
			}
		}

		return true;
	}

	bool is_correct_dec(string string_for_check) {
		for (int i = 0; i < string_for_check.length(); ++i) {
			int dismatch = 0;

			for (int k = 0; k < symbols_for_dec.length(); ++k) {
				if (string_for_check[i] == symbols_for_dec[k])
					break;
				else {
					dismatch++;

					if (dismatch == 10) {
						cout << "There is invalid symbol found in position " << i << endl;
						return false;
					}
				}
			}
		}

		return true;
	}

	bool is_correct_octal(string string_for_check) {
		for (int i = 0; i < string_for_check.length(); ++i) {
			int dismatch = 0;

			for (int k = 0; k < symbols_for_octal.length(); ++k) {
				if (string_for_check[i] == symbols_for_octal[k])
					break;
				else {
					dismatch++;

					if (dismatch == 8) {
						cout << "There is invalid symbol found in position " << i << endl;
						return false;
					}
				}
			}
		}

		return true;
	}
};