#include "account.h"

BankAccount::BankAccount(int accNumber, std::string holderName, double initialBalance) : accountNumber(accNumber), accountHolderName(holderName), balance(initialBalance) {}

BankAccount::~BankAccount() {}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful. Updated balance: " << balance << endl;
    }
    else {
        cout << "Invalid deposit amount." << endl;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful. Updated balance: " << balance << endl;
    }
    else {
        cout << "Invalid withdrawal amount or insufficient balance." << endl;
    }
}

double BankAccount::getBalance()
{
    return balance;
}

int main() {
    int accountNumber;
    string accountHolderName;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accountNumber;

    // Consume the newline character
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Enter account holder name: ";

    // Clear the newline character left in the buffer
    cin.ignore();

    getline(std::cin, accountHolderName);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(accountNumber, accountHolderName, initialBalance);

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            double depositAmount;
            cout << "Enter the amount to deposit: ";
            cin >> depositAmount;
            account.deposit(depositAmount);
            break;
        case 2:
            double withdrawAmount;
            cout << "Enter the amount to withdraw: ";
            cin >> withdrawAmount;
            account.withdraw(withdrawAmount);
            break;
        case 3:
            cout << "Current balance: " << account.getBalance() << endl;
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
