#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to encrypt a message using a keyed transposition cipher
string keyedTranspositionCipher(string message, string key)
{
    // Remove spaces and non-alphabetic characters from the message
    message.erase(remove_if(message.begin(), message.end(), [](char c) { return !isalpha(c); }), message.end());

    // Calculate the number of columns in the transposition grid
    int numCols = key.length();

    // Calculate the number of rows in the transposition grid
    int numRows = (message.length() + numCols - 1) / numCols;

    // Pad the message with random characters to fill the grid
    int numPadChars = numRows * numCols - message.length();
    for (int i = 0; i < numPadChars; i++)
    {
        message += rand() % 26 + 'A';
    }

    // Create the transposition grid
    char grid[numRows][numCols];
    int index = 0;
    for (char c : key)
    {
        int col = index++;
        for (int row = 0; row < numRows; row++)
        {
            grid[row][col] = c;
        }
    }

    // Fill the transposition grid with the message
    index = 0;
    for (int col = 0; col < numCols; col++)
    {
        int keyIndex = key.find_first_of(key[col]);
        if (keyIndex == col)
        {
            for (int row = 0; row < numRows; row++)
            {
                grid[row][col] = message[index++];
            }
        }
    }

    // Read the encrypted message from the transposition grid
    string encryptedMessage;
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            encryptedMessage += grid[row][col];
        }
    }

    return encryptedMessage;
}

// Function to decrypt a message using a keyed transposition cipher
string keyedTranspositionDecipher(string encryptedMessage, string key)
{
    // Calculate the number of columns in the transposition grid
    int numCols = key.length();

    // Calculate the number of rows in the transposition grid
    int numRows = encryptedMessage.length() / numCols;

    // Create the transposition grid
    char grid[numRows][numCols];
    int index = 0;
    for (char c : key)
    {
        int col = index++;
        for (int row = 0; row < numRows; row++)
        {
            grid[row][col] = c;
        }
    }

    // Fill the transposition grid with the encrypted message
    index = 0;
    for (int col = 0; col < numCols; col++)
    {
        int keyIndex = key.find_first_of(key[col]);
        if (keyIndex == col)
        {
            for (int row = 0; row < numRows; row++)
            {
                grid[row][col] = encryptedMessage[index++];
            }
        }
    }

    // Read the decrypted message from the transposition grid
    string decryptedMessage;
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            decryptedMessage += grid[row][col];
        }
    }

    // Remove any padding characters from the decrypted message
    decryptedMessage.erase(remove_if(decryptedMessage.begin(), decryptedMessage.end(), [](char c) { return !isalpha(c); }), decryptedMessage.end());

    return decryptedMessage;
}

int main()
{
    string message, key;

    cout << "Enter the message to encrypt: ";
    getline(cin, message);

    cout << "Enter the key: ";
    getline(cin, key);

    string encryptedMessage = keyedTranspositionCipher(message, key);
    string decryptedMessage = keyedTranspositionDecipher(encryptedMessage, key);

    cout << "Encrypted Message: " << encryptedMessage << endl;
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}