// This program work for Array of objects.

#include <iostream>
#include <string>
using namespace std;
class Bank
{
private:
    string name;
    long account_number;
    string type_of_account;
    double balance;

public:
    void assignValues()
    {
        cout << "\nEnter Account Holder&#39;s Name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);
        cout << "Enter Account Number: ";
        cin >> account_number;
        cout << "Enter Type of Account (Saving/Current): ";
        cin >> type_of_account;
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "Account created successfully!\n";
    }

    void deposit()
    {
        double amount;
        cout << "\nEnter amount to deposit: ";
        cin >> amount;
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully!\n";
        }
        else
        {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw()
    {
        double amount;
        cout << "\nEnter amount to withdraw: ";
        cin >> amount;
        if (amount <= balance && amount > 0)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
        }
        else
        {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void display()
    {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    int choice;
    const int MAX = 100;
    int count = 0;
    Bank X[MAX];

    do
    {
        cout << "\n====== Bank Account Menu ======";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Amount";
        cout << "\n3. Withdraw Amount";
        cout << "\n4. Display Name and Balance";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            X[count].assignValues();
            count = count + 1;
            break;
        case 2:
            X[count].deposit();
            break;
        case 3:
            X[count].withdraw();
            break;
        case 4:

            for (int i = 0; i < count; i++)
                X[i].display();
            break;
        case 5:
            cout << "Exiting program. Thank you!\n";
            break;
        default:

            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}