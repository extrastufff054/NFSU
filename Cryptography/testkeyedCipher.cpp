#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to encrypt the message using keyed transposition cipher
string keyedTranspositionCipher(string message, string key)
{
    // Remove spaces and convert to lowercase
    message.erase(remove_if(message.begin(), message.end(), ::isspace), message.end());
    transform(message.begin(), message.end(), message.begin(), ::tolower);

    // Create a vector of pairs to store the message and its corresponding index
    vector<pair<char, int>> messageVector;
    for (int i = 0; i < message.size(); i++)
    {
        messageVector.push_back(make_pair(message[i], i));
    }

    // Sort the vector based on the key
    sort(messageVector.begin(), messageVector.end(), [key](pair<char, int> a, pair<char, int> b) {
        return key.find(a.first) < key.find(b.first);
    });

    // Create a new string with the sorted message
    string sortedMessage;
    for (int i = 0; i < messageVector.size(); i++)
    {
        sortedMessage += messageVector[i].first;
    }

    return sortedMessage;
}

// Function to decrypt the message using keyed transposition cipher
string keyedTranspositionDecipher(string message, string key)
{
    // Create a vector of pairs to store the message and its corresponding index
    vector<pair<char, int>> messageVector;
    for (int i = 0; i < message.size(); i++)
    {
        messageVector.push_back(make_pair(message[i], i));
    }

    // Sort the vector based on the key
    sort(messageVector.begin(), messageVector.end(), [key](pair<char, int> a, pair<char, int> b) {
        return key.find(a.first) < key.find(b.first);
    });

    // Create a new string with the original message
    string originalMessage(message.size(), ' ');
    for (int i = 0; i < messageVector.size(); i++)
    {
        originalMessage[messageVector[i].second] = messageVector[i].first;
    }

    return originalMessage;
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