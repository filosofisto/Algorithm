#include <iostream>
#include "vigenere.h"

using namespace std;

int main()
{
	Vigenere vigenere{"APRESS!WELCOME"};
	string originalMessage = "Thisisanexampleofgenericmessage";
	string enc = vigenere.encrypt(originalMessage);
	string dec = vigenere.decrypt(enc);

	cout << "Original Message : " << originalMessage << endl;
	cout << "Encrypted Message: " << enc << endl;
	cout << "Decrypted Message: " << dec << endl;
	
	return EXIT_SUCCESS;
}
