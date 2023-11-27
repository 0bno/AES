#include <iostream>
#include <iomanip>

#include"Affichage.h"

using namespace std;

void displayMatrice44(int size, unsigned char message[4][4])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "|" << setfill('0') << setw(2) << hex << (int)message[i][j];
		}
		cout << "|" << endl;
	}
    cout << endl;
}

void subBytes(unsigned char message[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// Applique la substitution en utilisant les valeurs de la ligne et de la colonne de la matrice de message
			message[i][j] = S_Box[(message[i][j] & 0xF0) >> 4][message[i][j] & 0x0F];
		}
	}
}

void shiftRows(unsigned char message[4][4]) {
    unsigned char temp;

    // Pas de décalage à la ligne 0
    int indice_ligne = 0;
    indice_ligne++;
    // Décalage de la ligne 1
    temp = message[indice_ligne][0];
    message[indice_ligne][0] = message[indice_ligne][1];
    message[indice_ligne][1] = message[indice_ligne][2];
    message[indice_ligne][2] = message[indice_ligne][3];
    message[indice_ligne][3] = temp;
    indice_ligne++;
    // Décalage de la ligne 2
    temp = message[indice_ligne][0];
    message[indice_ligne][0] = message[indice_ligne][2];
    message[indice_ligne][2] = temp;
    temp = message[indice_ligne][1];
    message[indice_ligne][1] = message[indice_ligne][3];
    message[indice_ligne][3] = temp;
    indice_ligne++;
    // Décalage de la ligne 3
    temp = message[indice_ligne][3];
    message[indice_ligne][3] = message[indice_ligne][2];
    message[indice_ligne][2] = message[indice_ligne][1];
    message[indice_ligne][1] = message[indice_ligne][0];
    message[indice_ligne][0] = temp;
}

void mixColumns(unsigned char message[4][4]) {
    unsigned char tmp[4] = { 0, 0, 0, 0 };
    for (int c = 0; c < 4; c++) {
        for (int r = 0; r < 4; r++)
            tmp[r] = message[r][c];
        for (int r = 0; r < 4; r++) {
            message[r][c] = 0;
            for (int i = 0; i < 4; i++) {
                if (i == 0)
                    message[r][c] ^= (unsigned char)((int)tmp[i] * 2) ^ (unsigned char)((int)tmp[(i + 1) % 4] * 3);
                else if (i == 1)
                    message[r][c] ^= (unsigned char)((int)tmp[i] * 2) ^ tmp[(i + 1) % 4];
                else if (i == 2)
                    message[r][c] ^= tmp[i] ^ tmp[(i + 1) % 4];
                else
                    message[r][c] ^= (unsigned char)((int)tmp[i] * 3) ^ tmp[(i + 1) % 4];
            }
        }
    }
}

void MixColumns2(unsigned char message[4][4])
{
    unsigned char result[4][4];
    for (int i = 0; i < 4; i++)
    {
        result[0][i] = 0x02 ^ message[0][i] ^ 0x03 ^ message[1][i] ^ 0x01 ^ message[2][i] ^ 0x01 ^ message[3][i];
        result[1][i] = 0;
        result[2][i] = 0;
        result[3][i] = 0;
        cout << result[0][0];
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            message[i][j] = result[i][j];
        }
    }
}

