#include <iostream>
#include <string>
#include <algorithm>

std::string encrypt(std::string plaintext, std::string key);
std::string decrypt(std::string ciphertext, std::string key);

int main() {
    std::string plaintext, key;
    std::cout << "Enter the plaintext: ";
    std::getline(std::cin, plaintext);
    std::cout << "Enter the key: ";
    std::getline(std::cin, key);
    
    std::string ciphertext = encrypt(plaintext, key);
    std::cout << "Ciphertext: " << ciphertext << std::endl;
    
    std::string decryptedText = decrypt(ciphertext, key);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;
    
    return 0;
}

std::string encrypt(std::string plaintext, std::string key) {
    std::transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);
    std::string ciphertext = "";
    int j = 0;
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        if (c >= 'A' && c <= 'Z') {
            int shift = key[j] - 'A';
            char encrypted = (((c - 'A' + shift) % 26) + 'A');
            ciphertext += encrypted;
            j = (j + 1) % key.length();
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

std::string decrypt(std::string ciphertext, std::string key) {
    std::transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), ::toupper);
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);
    std::string plaintext = "";
    int j = 0;
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        if (c >= 'A' && c <= 'Z') {
            int shift = key[j] - 'A';
            char decrypted = (((c - 'A' - shift + 26) % 26) + 'A');
            plaintext += decrypted;
            j = (j + 1) % key.length();
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}
