#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
public:
    BankAccount(int, string, double);
    ~BankAccount();
    
    void deposit(double);
    void withdraw(double);
    double getBalance();
};

#endif