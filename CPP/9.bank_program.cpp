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
    static int count;
    static const int MAX = 100; // max number of accounts
    void assignValues()
    {
        cout << "\nEnter Account Holder's Name: ";
        cin.ignore(); // clear buffer
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
        if (amount > 0 && amount <= balance)
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
        cout << "\nAccount Holder: " << name;
        cout << "\nAccount Number: " << account_number;

        cout << "\nType of Account: " << type_of_account;
        cout << "\nBalance: Rs. " << balance << "\n";
    }

    void static menu()
    {

        cout << "\n====== Bank Account Menu ======";
        cout << "\n1. Create New Account";
        cout << "\n2. Deposit Amount";
        cout << "\n3. Withdraw ";
        cout << "\n4. Display Account Details";
        cout << "\n5. Search Account by Account Number";
        cout << "\n6. Exit";
    }
    friend int find(Bank X[], int n, long ano);
};
int find(Bank X[], int n, long accno)
{
    bool found;
    int i;
    i = 0;
    found = false;
    while (i < n && found == false)
    {
        if (X[i].account_number == accno)
            return i;
        else
            i = i + 1;
    }
    if (found == false)
        return -1;
}

int Bank::count = 0;
int main()
{
    Bank accounts[Bank::MAX];
    long accNo;
    int choice, idx;

    do
    {
        Bank::menu();
        cout << "\nEnter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (Bank::count < Bank::MAX)
            {
                accounts[Bank::count].assignValues();
                Bank::count = Bank::count + 1;
            }
            else
            {
                cout << "Cannot create more accounts. Limit reached.\n";
            }
            break;

        case 2:
            cout << "\nEnter Account Number to deposit into: ";
            cin >> accNo;
            idx = find(accounts, Bank::count, accNo);
            if (idx >= 0)
                accounts[idx].deposit();

            else
                cout << "Account does not exist!";

            break;

        case 3:
            cout << "\nEnter Account Number to withdraw from: ";
            cin >> accNo;
            idx = find(accounts, Bank::count, accNo);
            if (idx >= 0)
                accounts[idx].withdraw();
            else
                cout << "Account does not exist!";

            break;

        case 4:
            for (int i = 0; i < Bank::count; i++)
            {
                cout << "\n--- Account " << (i + 1) << " ---";
                accounts[i].display();
            }
            if (Bank::count == 0)
                cout << "\nNo accounts to display.\n";
            break;

        case 5:
            cout << "\nEnter Account Number to search: ";
            cin >> accNo;
            idx = find(accounts, Bank::count, accNo);

            if (idx >= 0)
                accounts[idx].display();
            else
                cout << "Account does not exist!";

            break;
            break;

        case 6:
            cout << "Exiting program. Thank you!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}