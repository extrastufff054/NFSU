#include <iostream>

using namespace std;

// Function to calculate the additive inverse of a number
int additiveInverse(int num, int mod)
{
    return (mod - num) % mod;
}

// Function to calculate the multiplicative inverse of a number
int multiplicativeInverse(int num, int mod)
{
    for (int i = 1; i < mod; i++)
    {
        if ((num * i) % mod == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int choice, num, mod, inverse;

    do
    {
        cout << "Choose an option:" << endl;
        cout << "1. Additive Inverse" << endl;
        cout << "2. Multiplicative Inverse" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the number: ";
                cin >> num;
                cout << "Enter the modulus: ";
                cin >> mod;
                cout << "Additive Inverse: " << additiveInverse(num, mod) << endl;
                break;
            case 2:
                cout << "Enter the number: ";
                cin >> num;
                cout << "Enter the modulus: ";
                cin >> mod;
                inverse = multiplicativeInverse(num, mod);
                if (inverse == -1)
                {
                    cout << "Multiplicative Inverse does not exist." << endl;
                }
                else
                {
                    cout << "Multiplicative Inverse: " << inverse << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 3);

    return 0;
}