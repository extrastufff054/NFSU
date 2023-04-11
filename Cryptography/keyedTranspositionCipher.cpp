#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string encrypt(string plaintext, string key) {
    // Remove any non-alphabetic characters from the key
    key.erase(remove_if(key.begin(), key.end(), [](char c) { return !isalpha(c); }), key.end());

    // Generate permutation from key
    string permutation = key + "abcdefghijklmnopqrstuvwxyz";
    sort(permutation.begin(), permutation.end());
    permutation.erase(unique(permutation.begin(), permutation.end()), permutation.end());

    int len = plaintext.length();
    int columns = permutation.length();
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

    // Rearrange columns of matrix based on permutation
    for (int j = 0; j < columns; j++) {
        char c = permutation[j];
        int index = find(permutation.begin(), permutation.end(), c) - permutation.begin();
        for (int i = 0; i < rows; i++) {
            ciphertext += matrix[i][index];
        }
    }

    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    // Remove any non-alphabetic characters from the key
    key.erase(remove_if(key.begin(), key.end(), [](char c) { return !isalpha(c); }), key.end());

    // Generate permutation from key
    string permutation = key + "abcdefghijklmnopqrstuvwxyz";
    sort(permutation.begin(), permutation.end());
    permutation.erase(unique(permutation.begin(), permutation.end()), permutation.end());

    int len = ciphertext.length();
    int columns = permutation.length();
    int rows = (len + columns - 1) / columns;
    string plaintext = "";
    plaintext.reserve(len);
    char matrix[rows][columns];

    // Rearrange columns of matrix based on permutation
    for (int j = 0; j < columns; j++) {
        char c = permutation[j];
        int index = find(permutation.begin(), permutation.end(), c) - permutation.begin();
        for (int i = 0; i < rows; i++) {
            matrix[i][index] = ciphertext[i * columns + j];
        }
    }

    // Read matrix by rows
    for (int i = 0; i < rows; i++) {
        plaintext.append(matrix[i], columns);
    }

    // Remove trailing spaces
    size_t pos = plaintext.find_last_not_of(' ');
    if (pos != string::npos) {
        plaintext.erase(pos + 1);
    }

    return plaintext;
}

int main() {
    string plaintext, key;

    // Get plaintext input
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    
    // Get key input
    cout << "Enter key: ";
    getline(cin, key);

    // Encrypt
    string ciphertext = encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    // Decrypt
    string decryptedtext = decrypt(ciphertext, key);
    cout << "Decrypted text: " << decryptedtext << endl;

    return 0;
}
