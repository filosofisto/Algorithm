#include "vigenere.h"
#include <string>

using std::string;
using std::string_view;

Vigenere::Vigenere(string_view chosenKey)
{
	for (int i{0}; i < chosenKey.size(); ++i) {
		if (chosenKey[i] >= 'A' && chosenKey[i] <= 'Z') {
			this->key += chosenKey[i];
		} else if (chosenKey[i] >= 'a' && chosenKey[i] <= 'z') {
			this->key += chosenKey[i] + 'A' - 'a';
		}
	}
}

string Vigenere::encrypt(string_view plainText) const{
	string encryptedOutput;

	for (int i{0}, j{0}; i < plainText.length(); ++i) {
		char c = plainText[i];
		
		if (c >= 'a' && c <= 'z') {
			c += 'A' - 'a';
		} else if (c < 'A' || c > 'Z') {
			continue;
		}

		encryptedOutput += (c + key[j] - 2 * 'A') % 26 + 'A';
		j = (j + 1) % key.length();
	}

	return encryptedOutput;
}

string Vigenere::decrypt(string_view encryptedText) const
{
	string decryptedOutput;

	for (int i{0}, j{0}; i < encryptedText.length(); ++i) {
		char c = encryptedText[i];
		
		if (c >= 'a' && c <= 'z') {
			c += 'A' - 'a';
		} else if (c < 'A' || c > 'Z') {
			continue;
		}

		decryptedOutput += (c - key[j] + 26) % 26 + 'A';
		j = (j + 1) % key.length();
	}

	return decryptedOutput;
}
