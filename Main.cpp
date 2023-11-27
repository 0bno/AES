#include <iostream>

#include"Affichage.h"

using namespace std;

int main()
{
	//I Chiffrement en bloc

	unsigned char message[4][4] = {
	{0x00, 0x40, 0x80, 0xC0},
	{0x10, 0x50, 0x90, 0xD0},
	{0x20, 0x60, 0xA0, 0xE0},
	{0x30, 0x70, 0xB0, 0xF0} };

	unsigned char cleChiffrement[4][4] = {  {0xD6,0xD2,0xDA,0xD6},
											{0xAA,0xAF,0xA6,0xAB},
											{0x74,0x72,0x78,0x76},
											{0xFD,0xFA,0xF1,0xFE} };

	cout << "Bienvenue sur decodatator 3000" << endl;
	cout << "Matrice remplie !" << endl;
	int size = 4;
	displayMatrice44(size, message);

	//II Chiffrement AES SubBytes OK

	subBytes(message);

	displayMatrice44(size, message);

	//III- Chiffrement AES ShiftRows OK

	shiftRows(message);

	displayMatrice44(size, message);

	//IV- MixColumns
	MixColumns2(message);

	displayMatrice44(size, message);

	//V- Add

	return 0;
}


/*
	char choix_hexa_dec = '0';
	char saisie = '0';

cout << "Souhaitez vous saisir votre code en bits ou en hexadecimal ?" << endl;
cout << "Merci de saisir B pour une saisie en bits ou H pour une saisie en hexa." << endl;
cin >> choix_hexa_dec;
while (choix_hexa_dec != 'H' && choix_hexa_dec != 'h' && choix_hexa_dec != 'B' && choix_hexa_dec != 'b') {
	cout << "Merci de saisir B pour une saisie en bits ou H pour une saisie en hexa." << endl;
	cin >> choix_hexa_dec;
}
if (choix_hexa_dec == 'H' || choix_hexa_dec == 'h') {
	cout << "Merci de saisir vos 32 entrée 1 par 1, afin de constuire la matrice :" << endl;
	for (int i = 0; i < 32; i++)
	{
		cout << "Merci de saisir le caractère de la case [" << i << "] :" << endl;
		cin >> message[i];
	}
	cout << "Matrice remplie !" << endl;
	int size = 4;
	displayMatrice44(size, message);
}
else {
	cout << "Fonctionnalité non implémentée." << endl;
	cout << "Merci de saisir vos 128 entrée afin de constuire la matrice" << endl;
}
*/

/*
char message[32] = {'0', '0', '1', '0', '2', '0', '3', '0', '4', '0', '5', '0', '6', '0', '7', '0', '8', '0', '9', '0', 'A', '0', 'B', '0', 'C', '0', 'D', '0', 'E', '0', 'F', '0'};


int message2[4][4] = {	{0x00,0x40,0x80,0xC0},
									{0x10,0x50,0x90,0xD0},
									{0x20,0x60,0xA0,0xE0},
									{0x30,0x70,0xB0,0xF0}  };
*/