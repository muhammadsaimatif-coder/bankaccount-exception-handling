#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    string holderName;
    double balance;

public:
    BankAccount(string name, double initialBalance)
    {
        cout << "Constructor called." << endl;

        if (initialBalance < 0)
        {
            throw "Invalid account creation: Balance cannot be negative.";
        }

        holderName = name;
        balance = initialBalance;
        cout << "Account created successfully." << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            throw "Withdrawal failed: Insufficient balance.";
        }

        balance = balance - amount;
        cout << "Withdrawal successful. Remaining balance: " << balance << endl;
    }

    ~BankAccount()
    {
        cout << "Destructor called. Account object destroyed." << endl;
    }
};

int main()
{
    BankAccount* account = NULL;

    try
    {
        account = new BankAccount("Ali", 500);
    }
    catch (const char* msg)
    {
        cout << "Exception caught in main: " << msg << endl;
    }

    if (account != NULL)
    {
        try
        {
            account->withdraw(500);
        }
        catch (const char* msg)
        {
            cout << "Exception caught in main: " << msg << endl;
        }

        delete account;
    }

    cout << "Program ended normally." << endl;
    return 0;
}
