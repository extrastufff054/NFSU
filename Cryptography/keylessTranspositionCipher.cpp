#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string encrypt(string plaintext) {
    int len = plaintext.length();
    int columns = ceil(sqrt(len));
    int rows = (len + columns - 1) / columns;
    string ciphertext = "";
    ciphertext.reserve(len);
    char matrix[rows][columns];

    // Fill matrix with plaintext
    for (int i = 0, k = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++, k++) {
            if (k < len) {
                matrix[i][j] = plaintext[k];
            } else {
                matrix[i][j] = ' ';
            }
        }
    }

    // Read matrix by columns
    for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            ciphertext += matrix[i][j];
        }
    }

    return ciphertext;
}

string decrypt(string ciphertext) {
    int len = ciphertext.length();
    int columns = ceil(sqrt(len));
    int rows = (len + columns - 1) / columns;
    string plaintext = "";
    plaintext.reserve(len);
    char matrix[rows][columns];

    // Fill matrix with ciphertext by columns
    for (int j = 0, k = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++, k++) {
            if (k < len) {
                matrix[i][j] = ciphertext[k];
            } else {
                matrix[i][j] = ' ';
            }
        }
    }

    // Read matrix by rows
    for (int i = 0; i < rows; i++) {
        plaintext.append(matrix[i], columns);
    }

    return plaintext;
}

int main() {
    string plaintext;

    // Get plaintext input
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    // Encrypt
    string ciphertext = encrypt(plaintext);
    cout << "Ciphertext: " << ciphertext << endl;

    // Decrypt
    string decryptedtext = decrypt(ciphertext);
    cout << "Decrypted text: " << decryptedtext << endl;

    return 0;
}
