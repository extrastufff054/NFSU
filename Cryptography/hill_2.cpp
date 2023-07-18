#include<bits/stdc++.h>
using namespace std;

// Function to encrypt the message
void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageMatrix[][1], int messageSize)
{
    int i, j, k;
    for (i = 0; i < messageSize; i++)
    {
        for (j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;

            for (k = 0; k < 3; k++)
            {
                cipherMatrix[i][j] += keyMatrix[i][k] * messageMatrix[k][j];
            }

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

// Function to implement Hill Cipher
string HillCipher(string message, int keyMatrix[][3])
{
    int messageSize = message.size();
    int messageMatrix[messageSize][1];

    // Generate vector for the message
    for (int i = 0; i < messageSize; i++)
        messageMatrix[i][0] = (message[i]) % 65;

    int cipherMatrix[messageSize][1];
    encrypt(cipherMatrix, keyMatrix, messageMatrix, messageSize);

    string CipherText;
    for (int i = 0; i < messageSize; i++)
        CipherText += cipherMatrix[i][0] + 65;

    return CipherText;
}

int main()
{
    string message;
    int keyMatrix[3][3];

    cout << "Enter the message to encrypt: ";
    getline(cin, message);

    cout << "Enter the key matrix (3x3): " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> keyMatrix[i][j];
        }
    }

    string encryptedMessage = HillCipher(message, keyMatrix);

    cout << "Encrypted Message: " << encryptedMessage << endl;

    return 0;
}
