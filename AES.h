/* Marc Vis
 *
 * AES Algorithm object.  This object can perform AES encryption and decryption on
 * any 16 byte block.  AES128, AES192, and AES256 algorithms taken into consideration.
 *
 * To use: 
 *  1.) load 16 bytes of data as an unsigned char[] using loadState() method. 
 *  2.) load 16, 24, or 32 byte key as unsigned char[] using loadErk().  Pass the length of the array as second parameter.
 *  3.) Use either encrypt() or decrypt() to use AES algorithm of loaded state using loaded key.
 *  4.) At any time, you can retrieve state using getState() method.
 */
#include <iostream>
#include <string>

using namespace std;

#pragma once
class AES
{
private:
	static const unsigned char sbox[256];
	static const unsigned char invSbox[256];
	static const char hexLookup[16];
	static const unsigned char mixer[4][4];
	static const unsigned char invMixer[4][4];
	unsigned char** state;
	unsigned char* erk;
	unsigned char** w;
	int Nk;
	int Nr;

	static string toHex(unsigned char a);
	unsigned char xtime(unsigned char a);
	unsigned char xmult(unsigned char a, unsigned char b);
	void buildKeySchedule();
	void testPrintW();
	void getWord(int i, unsigned char* t);
	void putWord(int i, unsigned char* t);
	void subWord(unsigned char* t);
	void rotWord(unsigned char* t);
	void xorWord(unsigned char* t, unsigned char* p);
	void subBytes();
	void invSubBytes();
	void shiftRows();
	void invShiftRows();
	void mixColumns();
	void invMixColumns();
	void addRoundKey(int a);

public:

	AES(void);
	~AES(void);

	void loadState(unsigned char* in);
	void printState();
	void getState(unsigned char* out);

	void loadErk(unsigned char* e, int k);

	void encrypt();
	void decrypt();
};

