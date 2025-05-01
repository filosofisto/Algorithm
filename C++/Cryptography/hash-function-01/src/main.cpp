#include <iostream>
#include <sstream> 	// templates and types for interoperation between flow buffers and string objects
#include <bitset>		// storing bits library
#include <vector>
#include <iomanip>
#include <cstring>

// defined in accordance with the NIST standard
#define ROTRIGHT(word,bits) (((word) >> (bits)) | ((word) << (32-(bits))))
#define SSIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define SSIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))
#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
// in accordance with the latest updates of the NIST standard
// we will replace BSIG0 with EP0 and BSIG1 with EP0 in our implementation
#define BSIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define BSIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))
#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
// we will verify if the process of checking (testing) is enabled
// by the missed arguments in the command line.
// The steps are as follows:
// (1) Take the ascii string and convert it in n 8 bit segments by
// representing the ascii value of each independently character
// (2) add paddings to the message in order to get a 512 bit long
// (3) take separately each 8 bit ascii value and convert it to 32
// bit words and create a combination of them.
// (4) calculate the hash and get the vallue
// (5) if we are doing test, take the result and compare it with

using namespace std;

// Function declarations
vector<unsigned long> resizingTheBlock(vector<unsigned long>);
void outputTheBlockState(vector<unsigned long>); 
string displayAsHex(unsigned long);
string displayAsBinary(unsigned long);
vector <unsigned long> addPadOf512Bits(vector<unsigned long>);
string computingTheHash(const vector<unsigned long>);

// constants
const bool displayBlockStateAddOne = 0;
const bool displayDistanceFrom512Bit = 0;
const bool displayResultsOfPadding = false;
const bool displayWorkVariablesForT = 0;
const bool displayT1Computation = false;
const bool displayT2Computation = false;
const bool displayTheHashSegments = false;
const bool displayWt = false;

// the function purpose is to resize the blocks from 64 and 8 bit
// to 16 and 32 bit sections. The function as input will take a
// vector of individual 8 bit ascii values. As output we will get a
// vector with 32 bit words that are found within a combination of ascii values.
vector<unsigned long> resizingTheBlock(vector<unsigned long> inputOf8BitAsciiValues)
{
	vector<unsigned long> outputOf32BitWordsCombinedAsAsciiValues(16);

	// parse all 64 sections using a 4 step and mergem them accordingly
	for (int i{0}; i < 64; i+=4) {
		// create for beginning a big 32 bit section first
		bitset<32> temporary32BitSection(0);

		// create a shifting of the blocks on their assigned positions
		temporary32BitSection = (unsigned long) inputOf8BitAsciiValues[i] << 24;
		temporary32BitSection |= (unsigned long) inputOf8BitAsciiValues[i+1] << 16;	
		temporary32BitSection |= (unsigned long) inputOf8BitAsciiValues[i+2] << 8;
		temporary32BitSection |= (unsigned long) inputOf8BitAsciiValues[i+3];

		// set the new 32 bot word within the proper output of the array location
		outputOf32BitWordsCombinedAsAsciiValues[i/4] = temporary32BitSection.to_ulong();
	}

	return outputOf32BitWordsCombinedAsAsciiValues;
}

// the function display  the contents of all the blocks as binary format
// Used only for debugging purpose
void outputTheBlockState(vector<unsigned long> vectorOfCurrentBlocks)
{
	cout << "---- The current State of the Block ----\n";
	for (int i{0}; i < vectorOfCurrentBlocks.size(); ++i) {
		cout 	<< "block[" << i << "] binary: " 
					<< displayAsBinary(vectorOfCurrentBlocks[i]) << "     hex y: 0x"
					<< displayAsHex(vectorOfCurrentBlocks[i]) << endl;
	}
}

// display in hex format the content of the block
string displayAsHex(unsigned long input32BitBlock)
{
	bitset<32> theBitSet(input32BitBlock);
	unsigned number = theBitSet.to_ulong();
	stringstream theStringStream;
	theStringStream << hex << setw(8) << setfill('0') << number;

	string temporary;
	theStringStream >> temporary;

	return temporary;
}

// display as binary
string displayAsBinary(unsigned long input32OrLessBitBlock)
{
	bitset<8> theBitSet(input32OrLessBitBlock);
	return theBitSet.to_string();
}

// based on the string, it will take the entire set of the characters and
// converts them into ascii binary
vector<unsigned long> binaryConversion(const string inputOfAnyLength)
{
	// the vector used to store all the ascii characters
	vector<unsigned long> vectorBlockHoldingAsciiCharacters;

	// take each character and convert the ascii characer to the binary representation
	for (int i{0}; i < inputOfAnyLength.size(); ++i) {
		// create a temporary variable. Use it to store the 8 bit template for ascii value
		bitset<8> bitSetOf8Bits(inputOfAnyLength.c_str()[i]);

		// the template of 8 bit add it into the block
		vectorBlockHoldingAsciiCharacters.push_back(bitSetOf8Bits.to_ulong());
	}

	return vectorBlockHoldingAsciiCharacters;
}
 
// get the ascii values stored as a vector in binary and add padding to it in order to
// obtain a total of 512 bits
vector <unsigned long> addPadOf512Bits(vector<unsigned long> vectorBlockHoldingAsciiCharacters)
{
	// you can keep the variables names as given in the NIST
	// for our implementation I have used my personal names for variables in order to get a 
	// uniqueness	of the code the variable will store the length of the message in bits
	int lengthOfMessageInBits = vectorBlockHoldingAsciiCharacters.size() * 8;
	int zerosToAdd = 447 - lengthOfMessageInBits;

	// add another 8 bit block with the first bit being set to 1
	if (displayBlockStateAddOne) {
		outputTheBlockState(vectorBlockHoldingAsciiCharacters);
	}

	unsigned long t1Block = 0x80;
	vectorBlockHoldingAsciiCharacters.push_back(t1Block);

	if (displayBlockStateAddOne) {
		outputTheBlockState(vectorBlockHoldingAsciiCharacters);
	}

	// we have 7 zeros. We will need to substract 7 from zerosToAdd
	zerosToAdd = zerosToAdd - 7;

	// debug mode. Find how much we need to get close to 512 bit
	if (displayDistanceFrom512Bit) {
		cout << "lengthOfMessageInBits = " << lengthOfMessageInBits << endl;
		cout << "adding " << zerosToAdd / 8 << " empty eight bit blocks!\n";
	}

	// add blocks of 8 bit length that will contains zero's
	for (int i{0}; i < zerosToAdd / 8; ++i) {
		vectorBlockHoldingAsciiCharacters.push_back(0x00000000);

		// we are finding ourself in 488 bits out 512 phase
		// next step is adding 1 in the binary representation in order to form of eight bit blocks
		bitset<64> theBig64BlobBit(lengthOfMessageInBits);

		if (displayDistanceFrom512Bit) {
			cout << "1 in a 64 bit ninary bloc: \n\t" << theBig64BlobBit << endl;
		}

		// divide the 64 bit big into 8 bit segments
		string big_64bit_string = theBig64BlobBit.to_string();

		// take the first block and push it on the 56 position
		bitset<8> temp_string_holder1(big_64bit_string.substr(0,8));
		vectorBlockHoldingAsciiCharacters.push_back(temp_string_holder1.to_ulong());

		// take the rest of the blocks with 8 bits length and push 
		for (int i{8}; i < 63; i+=8) {
			bitset<8> temporaryStringHolder2(big_64bit_string.substr(i,8));
			vectorBlockHoldingAsciiCharacters.push_back(temporaryStringHolder2.to_ulong());
		}

		// just show in the console everything in order to know what is happening in this freakin code
		if (displayResultsOfPadding) {
			cout << "Current 512 bit pre-processed hash in binary: \n";
			for (int i{0}; i < vectorBlockHoldingAsciiCharacters.size(); i+=4) {
				cout 	<< i 		<< ": " << displayAsBinary(vectorBlockHoldingAsciiCharacters[i]) << "    "
							<< i+1 	<< ": " << displayAsBinary(vectorBlockHoldingAsciiCharacters[i+1]) << "    "
							<< i+2 	<< ": " << displayAsBinary(vectorBlockHoldingAsciiCharacters[i+2]) << "    "
							<< i+3 	<< ": " << displayAsBinary(vectorBlockHoldingAsciiCharacters[i+3]) << "    " << endl;
			}

			cout << "Current 512 bit pre-processed hash in hex: \n";
			for (int i{0}; i < vectorBlockHoldingAsciiCharacters.size(); i+=4) {
				cout 	<< i 		<< ": 0x" << displayAsHex(vectorBlockHoldingAsciiCharacters[i]) << "    "
							<< i+1 	<< ": 0x" << displayAsHex(vectorBlockHoldingAsciiCharacters[i+1]) << "    "
							<< i+2 	<< ": 0x" << displayAsHex(vectorBlockHoldingAsciiCharacters[i+2]) << "    "
							<< i+3 	<< ": 0x" << displayAsHex(vectorBlockHoldingAsciiCharacters[i+3]) << "    " << endl;
			}
		}
	}

	return vectorBlockHoldingAsciiCharacters;
}

// compute the hash of the message
string computingTheHash(const vector<unsigned long> blockOf512BitPaddedMessage)
{
	// the following words are from the NIST standard
	unsigned long constantOf32BitWords[64] = {
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98,
		0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
		0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8,
		0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
		0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
		0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
		0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7,
		0xc67178f2
	};

	// the initial hash values
	unsigned long static InitialHashValueFor32Bit_0 = 0x6a09e667;
  unsigned long static InitialHashValueFor32Bit_1 = 0xbb67ae85;
  unsigned long static InitialHashValueFor32Bit_2 = 0x3c6ef372;
  unsigned long static InitialHashValueFor32Bit_3 = 0xa54ff53a;
  unsigned long static InitialHashValueFor32Bit_4 = 0x510e527f;
  unsigned long static InitialHashValueFor32Bit_5 = 0x9b05688c;
  unsigned long static InitialHashValueFor32Bit_6 = 0x1f83d9ab;
  unsigned long static InitialHashValueFor32Bit_7 = 0x5be0cd19;
  unsigned long Word[64];

	for (int t{0}; t <= 15; ++t) {
		if (displayWt) {
			cout << "Word[" << t << "]: 0x" << displayAsHex(Word[t]) << endl;
		}
	}

	for (int t{16}; t <= 63; ++t) {
		Word[t] = SSIG1(Word[t-2]) + Word[t-7] + SSIG0(Word[t-15]) + Word[t-16];
		Word[t] = Word[t] & 0xFFFFFFFF;
		
		if (displayWt) {
			cout << "Word[" << t << "]: " << Word[t];
		}
	}

	unsigned long temporary_1;
	unsigned long temporary_2;
	unsigned long a = InitialHashValueFor32Bit_0;
	unsigned long b = InitialHashValueFor32Bit_1;
	unsigned long c = InitialHashValueFor32Bit_2;
	unsigned long d = InitialHashValueFor32Bit_3;
	unsigned long e = InitialHashValueFor32Bit_4;
	unsigned long f = InitialHashValueFor32Bit_5;
	unsigned long g = InitialHashValueFor32Bit_6;
	unsigned long h = InitialHashValueFor32Bit_7;

	if (displayWorkVariablesForT) {
		cout << "         A        B        C        D        "
				 << "E        F        G        H        T1   T2\n";
	}

	for (int t{0}; t < 64; ++t) {
		// according to the NIST Standard and Specification,
		// the BSG1 is incorrect, we will replace it with EP1
		temporary_1 = h + EP1(e) + CH(e,f,g) + constantOf32BitWords[t] + Word[t];
		if ((t == 20) & displayT1Computation) {
			cout << "h: 0x" << hex << h << "  dec:" << dec << h
					 << "  sign:" << dec << (int)h << endl;
			cout << "EP1(e): 0x" << hex << EP1(e) << "  dec:"
					 << dec << EP1(e) << "  sign:" << dec << (int)EP1(e) << endl;
			cout << "CH(e,f,g): 0x" << hex << CH(e,f,g) << "  dec:"
					 << dec << CH(e,f,g) << "  sign:" << dec
					 << (int)CH(e,f,g) << endl;
			cout << "constantOf32BitWords[t]: 0x" << hex << constantOf32BitWords[t] << "  dec:" << dec
					 << constantOf32BitWords[t] << "  sign:" << dec << (int)constantOf32BitWords[t] << endl;
			cout << "Word[t]: 0x" << hex << Word[t] << "  dec:" << dec << Word[t] << "  sign:" << dec 
					 << (int)Word[t] << endl;
			cout << "temporary_1 = 0x" << hex << temporary_1 << "  dec:" << dec << temporary_1 
					 << "  sign:" << dec << (int)temporary_1 << endl;
		}

		// according to the NIST Standard and Specification,
		// the BSIG0 is incorrect. We will replace it with EP0
		temporary_2 = EP0(a) + MAJ(a,b,c);

		// in order to get T2 we will display the variables and operations
		if ((t == 20) & displayT2Computation) {
			cout << "a: 0x" << hex << a << "  dec:" << dec << a
					 << "  sign:" << dec << (int)a << endl;
			cout << "b: 0x" << hex << b << "  dec:" << dec << b
					 << "  sign:" << dec << (int)b << endl;
			cout << "c: 0x" << hex << c << "  dec:" << dec << c
					 << "  sign:" << dec << (int)c << endl;
			cout << "EP0(a): 0x" << hex << EP0(a) << "  dec:"
					 << dec << EP0(a) << "  sign:" << dec << (int)EP0(a) << endl;
			cout << "MAJ(a,b,c): 0x" << hex << MAJ(a,b,c) 
					 << "  dec:" << dec << MAJ(a,b,c) 
					 << "  sign:" << dec << (int)MAJ(a,b,c) << endl;
			cout << "temporary_2 = 0x" << hex << temporary_2 
					 << "  dec:" << dec << temporary_2 
					 << "  sign:" << dec << (int)temporary_2 << endl; 
		}

		// according to the NIST standard
		h = g;
		g = f;
		f = e;
		// Get the guarantee that we are still using 32 bits
		e = (d + temporary_1) & 0xFFFFFFFF;
		d = c;
		c = b;
		b = a;
		// Get the guarantee that we are still using 32 bits
		a = (temporary_1 + temporary_2) & 0xFFFFFFFF;
		// display the content of each of the variable from
		// above according to the NIST standard.

		if (displayTheHashSegments) {
			cout << "InitialHashValueFor32Bit_0 = " << displayAsHex(InitialHashValueFor32Bit_0) << " + "
					 << displayAsHex(a) << " " << displayAsHex(InitialHashValueFor32Bit_0 + a) << endl;
			cout << "InitialHashValueFor32Bit_1 = " << displayAsHex(InitialHashValueFor32Bit_1) << " + "
					 << displayAsHex(b) << " " << displayAsHex(InitialHashValueFor32Bit_1 + b) << endl;
			cout << "InitialHashValueFor32Bit_2 = " << displayAsHex(InitialHashValueFor32Bit_2) << " + "
					 << displayAsHex(c) << " " << displayAsHex(InitialHashValueFor32Bit_2 + c) << endl;
			cout << "InitialHashValueFor32Bit_3 = " << displayAsHex(InitialHashValueFor32Bit_3) << " + "
					 << displayAsHex(d) << " " << displayAsHex(InitialHashValueFor32Bit_3 + d) << endl;
			cout << "InitialHashValueFor32Bit_4 = " << displayAsHex(InitialHashValueFor32Bit_4) << " + "
					 << displayAsHex(e) << " " << displayAsHex(InitialHashValueFor32Bit_4 + e) << endl;
			cout << "InitialHashValueFor32Bit_5 = " << displayAsHex(InitialHashValueFor32Bit_5) << " + "
					 << displayAsHex(f) << " " << displayAsHex(InitialHashValueFor32Bit_5 + f) << endl;
			cout << "InitialHashValueFor32Bit_6 = " << displayAsHex(InitialHashValueFor32Bit_6) << " + "
					 << displayAsHex(g) << " " << displayAsHex(InitialHashValueFor32Bit_6 + g) << endl;
			cout << "InitialHashValueFor32Bit_7 = " << displayAsHex(InitialHashValueFor32Bit_7) << " + "
					 << displayAsHex(h) << " " << displayAsHex(InitialHashValueFor32Bit_7 + h) << endl;
		}

		// for each hash add all the variables in order be sure that
		// we are still on the page with the 32 bit values
		InitialHashValueFor32Bit_0 = (InitialHashValueFor32Bit_0 + a) & 0xFFFFFFFF;
		InitialHashValueFor32Bit_1 = (InitialHashValueFor32Bit_1 + b) & 0xFFFFFFFF;
		InitialHashValueFor32Bit_2 = (InitialHashValueFor32Bit_2 + c) & 0xFFFFFFFF;
		InitialHashValueFor32Bit_3 = (InitialHashValueFor32Bit_3 + d) & 0xFFFFFFFF;
		InitialHashValueFor32Bit_4 = (InitialHashValueFor32Bit_4 + e) & 0xFFFFFFFF;
		InitialHashValueFor32Bit_5 = (InitialHashValueFor32Bit_5 + f) & 0xFFFFFFFF;
		InitialHashValueFor32Bit_6 = (InitialHashValueFor32Bit_6 + g) & 0xFFFFFFFF;
		InitialHashValueFor32Bit_7 = (InitialHashValueFor32Bit_7 + h) & 0xFFFFFFFF;
	}

	// add the hash section in one piece one after the other in
	// order to obtain the 256 bit hash
	return	displayAsHex(InitialHashValueFor32Bit_0) +
					displayAsHex(InitialHashValueFor32Bit_1) +
					displayAsHex(InitialHashValueFor32Bit_2) +
					displayAsHex(InitialHashValueFor32Bit_3) +
					displayAsHex(InitialHashValueFor32Bit_4) +
					displayAsHex(InitialHashValueFor32Bit_5) +
					displayAsHex(InitialHashValueFor32Bit_6) +
					displayAsHex(InitialHashValueFor32Bit_7);
}

int main(int argc, char **argv)
{
	string theMessage = "";
	bool testing = false;
	switch (argc) {
		case 1:
			cout << "There is no input string found. The test will be run using random first three letters abc.\n";
			theMessage = "abc";
			testing = true;
			break;
		case 2:
			if (strlen(argv[1]) > 55) {
				cout << "The string provided is bigger than 55 characteres length. Enter a shorter string or message!\n";
				return EXIT_FAILURE;
			}

			theMessage = argv[1];
			break;
		default:
			cout << "There are too many items in the command line\n";
			return EXIT_FAILURE;
	}

	// storing all the blocks
	vector<unsigned long> theBlocksArray;

	// convert the message to a vector of strings by having it represented it as a 8 bit variable
	theBlocksArray = binaryConversion(theMessage);

	// add padd to it in order to get a full of 512 bits long
	theBlocksArray = addPadOf512Bits(theBlocksArray);

	// create a separate combination of the 8 bit segments into single 32 bits sections
	theBlocksArray = resizingTheBlock(theBlocksArray);

	// compute the hash using computingTheHash function
	string myHash = computingTheHash(theBlocksArray);

	// if testing is found on true the software app will execute a self check by checking if the 
	// hash value computed for "abc" is equal with the expected hash
	if (testing) {
		const string theCorrectHashForABC = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";
		if (theCorrectHashForABC.compare(myHash) != 0) {
			cout << "\tThe test didn't occur with success!\n";
			return EXIT_FAILURE;
		} else {
			cout << "\tTest has been done with success!\n";
		}
	}

	cout << myHash << endl;
	return EXIT_SUCCESS;
}

