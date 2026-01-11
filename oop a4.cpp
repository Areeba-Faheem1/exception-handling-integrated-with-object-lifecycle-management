#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    //constructor
    BankAccount(const string& name, double initialBalance) : accountHolder(name), balance(initialBalance) {

        cout << "Constructor called for " << accountHolder << endl;

        if (initialBalance < 0) {
            throw invalid_argument("Error: Initial balance cannot be negative!");
        }
    }

    //Destructor
    ~BankAccount() {
        cout << "Destructor called for " << accountHolder << endl;
    }

    // withdraw function
    void withdraw(double amount) {
        if (amount > balance) {
            throw runtime_error("Error: Insufficient funds for withdrawal!");
        }
        balance -= amount;
        cout << "Withdrawal successful. New balance: " << balance << endl;
    }

    // display balance
    void displayBalance() const {
        cout << "Account: " << accountHolder << ", Balance: " << balance << endl;
    }
};

int main() {
    cout << "    (Testing BankAccount Exception Handling)    " << endl;

    // account with negative balance
    cout << "  Creating account with negative balance:  " << endl;
    BankAccount* account1 = nullptr;
    try {
        account1 = new BankAccount("Sana", -100.0);
        // this line will not execute if exception is thrown
        cout << "Account created successfully!" << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
        cout << "No memory leak - constructor didn't complete successfully!" << endl;
    }

    // valid account withdrawal
    cout << "  Creating valid account and testing withdrawal:  " << endl;
    BankAccount* account2 = nullptr;
    try {
        account2 = new BankAccount("Ali", 500.0);
        account2->displayBalance();

        // Try to withdraw more than available balance
        account2->withdraw(600.0);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    // clean up 
    if (account2 != nullptr) {
        delete account2;
        account2 = nullptr;
    }

    //  valid account successful withdrawal
    cout << "  creating Successful withdrawal:  " << endl;
    BankAccount* account3 = nullptr;
    try {
        account3 = new BankAccount("Areeba", 800.0);
        account3->withdraw(100.0);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    delete account3;

    return 0;
}