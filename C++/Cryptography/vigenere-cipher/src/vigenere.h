#ifndef __VIGENERE__
#define __VIGENERE__

#include <string>
#include <string_view>

class Vigenere
{
	public: 
		Vigenere(std::string_view chosenKey);
		virtual ~Vigenere() = default;

		std::string encrypt(std::string_view plainText) const;
		std::string decrypt(std::string_view encryptedText) const;

	private:
		std::string key;
};

#endif
