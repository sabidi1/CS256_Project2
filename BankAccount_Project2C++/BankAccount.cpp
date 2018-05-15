//
//  BankAccount.hpp
//
//
//  Created by Zeeshan Abidi on 5/13/18.
//

#ifndef BankAccount_hpp
#define BankAccount_hpp

#include <stdio.h>

class BankAccount
{
    protected:
    double balance;
    int numOfDeposit;
    int numOfWithdrawl;
    double AnnualInterestRate;
    double monthlyCharge;

    public:
    BankAccount(double bal, double interestRate)
    {
        balance = bal;
        AnnualInterestRate = interestRate;
        numOfDeposit = 0;
        numOfWithdrawl = 0;
        monthlyCharge = 0;
    }

    virtual void deposit(double amount)
    {
        balance += amount;
        numOfDeposit++;
    }
    virtual void withdraw(double amount)
    {
        balance -= amount;
        numOfWithdrawl++;
    }
    virtual void calcInt()
    {
        double MonthlyInterestRate = (AnnualInterestRate/12);
        double MonthlyInterest = (balance * MonthlyInterestRate)
        balance = balance + MonthlyInterest;
    }

    virtual void monthlyProc()
    {
        balance -= monthlyCharge;
        calcInt();
        numOfDeposit = 0;
        numOfWithdrawl = 0;
        monthlyCharge = 0;
    }

    double getbalance ()
    {
        return balance
    }
    int getNumOfDeposit()
    {
        return numOfDeposit;
    }
    int getNumOfWithdrawl()
    {
        return numOfWithdrawl;
    }
    double getMonthlyCharge()
    {
        return monthlyCharge;
    }
};

#endif /* BankAccount_hpp */
