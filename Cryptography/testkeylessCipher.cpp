#include <iostream>
#include <string>

using namespace std;

// Function to encrypt the message using keyless transposition cipher
string keylessTranspositionCipher(string message)
{
    // Remove spaces and convert to lowercase
    string processedMessage = "";
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] != ' ')
        {
            processedMessage += tolower(message[i]);
        }
    }

    // Calculate the number of rows and columns required for the grid
    int length = processedMessage.length();
    int rows = (length + 4) / 5;
    int columns = 5;

    // Calculate the number of padding 'x' characters required
    int padding = rows * columns - length;

    // Create a 2D grid to store the message
    char grid[rows][columns];

    // Fill the grid with the message
    int index = 0;
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (index < length)
            {
                grid[i][j] = processedMessage[index];
                index++;
            }
            else
            {
                grid[i][j] = 'x'; // Pad with 'x' if necessary
            }
        }
    }

    // Read the message from the grid column-wise
    string encryptedMessage = "";
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (padding > 0 && i == rows - 1 && grid[i][j] == 'x')
            {
                padding--;
            }
            else
            {
                encryptedMessage += grid[i][j];
            }
        }
    }

    return encryptedMessage;
}

// Function to decrypt the message using keyless transposition cipher
string keylessTranspositionDecipher(string message)
{
    // Calculate the number of rows and columns required for the grid
    int length = message.length();
    int rows = (length + 4) / 5;
    int columns = 5;

    // Calculate the number of padding 'x' characters
    int padding = rows * columns - length;

    // Create a 2D grid to store the message
    char grid[rows][columns];

    // Fill the grid with the message
    int index = 0;
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (padding > 0 && i == rows - 1 && j >= columns - padding)
            {
                grid[i][j] = 'x'; // Pad with 'x' if necessary
                padding--;
            }
            else
            {
                grid[i][j] = message[index];
                index++;
            }
        }
    }

    // Read the message from the grid row-wise
    string decryptedMessage = "";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (grid[i][j] != 'x')
            {
                decryptedMessage += grid[i][j];
            }
        }
    }

    return decryptedMessage;
}

int main()
{
    string message;

    cout << "Enter the message to encrypt: ";
    getline(cin, message);

    string encryptedMessage = keylessTranspositionCipher(message);
    string decryptedMessage = keylessTranspositionDecipher(encryptedMessage);

    cout << "Encrypted Message: " << encryptedMessage << endl;
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}