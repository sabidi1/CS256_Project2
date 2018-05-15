/*
 * SavingsAccount.cpp
 *
 *  Created on: May 15, 2018
 *      Author: Zeeshan
 */

#include <stdio.h>
#include<iostream>
#include<stdbool.h>
#include "BankAccount.h"

using namespace std;

/***********************************************************************
 status (to represent an active or inactive account)
 If the account Balance of a savings account falls below $25,
 it becomes inactive. (The status member could be a flag variable.)
 No more withdrawals may be made until the bal- ance is raised above
 $25, at which time the account becomes active again.
 The savings account class should have the following member functions:
 **********************************************************************/
class SavingAccount : public BankAccount

{
    private:
    bool status;        //to see if account is active

    public:
    SavingAccount(double b, double r): BankAccount(b,r)
    {

    }

    bool checkStatus()
    {
        if (BankAccount::accountBalance < 25.0)        //accountBalance less than $25
            return false;                               //account inactive
        else
            return true;
    }


    void withdraw(double amount)
    {
        if (checkStatus())        //checks to see if account is inactive
        {
            BankAccount::withdraw(amount)
        }
        else{
            cout << "\nNo withdrawl can be made, not enough funds. " << endl;
        }
    }
    //
    void deposit(double amount)
    {
        if (checkStatus() == false)     //check to see if the account is inactive before a deposit
        {
            ////No more withdrawls may be made until accountBalance is greater than 25
            if (BankAccount::accountBalance + amount > 25)
            status = true;
        }
        BankAccount::deposit(amount);
    }

    void monthlyProc()
    {
        if (BankAccount::numOfWithdrawl > 4)     //if number of withdrawls is more than 4
        {
            BankAccount::monthlyServiceCharge += 1;         //service charge of $1
            BankAccount::accountBalance -= 1;
            if (BankAccount::accountBalance < 25)              //check to see if accountBalance after service charge
            status = false;                             //account inactive
        }

    }
};

/********************************************************************
 Next, design a checking account class
 withdraw:
 monthlyProc:
 ***********************************************************************/
class CheckingAccount :public BankAccount
{
    public:
    CheckingAccount(double b, double r) : BankAccount(b, r)
    {

    }

    void withdraw(double amount)
    {
        //check if accountBalance goes below $0
        if (accountBalance - amount < 0)
        {
            //if less than 0, add service charge of $15
            monthlyServiceCharge += 15;
            accountBalance -= 15;
        }
        else
        BankAccount::withdraw(amount);
    }

    void monthlyProc()
    {
        //adds the monthly fee of $5 plus $0.10 per withdrawal
        monthlyServiceCharge += 5;
        monthlyServiceCharge += 0.10 * numOfWithdrawl;
    }
};

int main()
{
     double depositAmount, withdrawAmount;

    //Savings Account
    BankAccount *saving = new SavingAccount(100,15);
    cout << "Please enter amount to deposit in saving account: ";
    cin >> depositAmount;

    saving->deposit(depositAmount);

    double monthStartBalance = depositAmount;

    cout << "Enter amount to withdraw from saving account: ";
    cin >> withdrawAmount;
    saving->withdraw(withdrawAmount);

    //Print output for saaving account
    cout << "Month start balance: " << monthStartBalance << endl;
    cout << "Total No of depost: " << saving->getNoOfDeposit() << endl;
    cout << "Total no of withdrawl: " << saving->getNoOfWithdrawl() << endl;
    cout << "Monthly service charge: " << saving->getMonthleServiceCharge() << endl;
    cout << "Month Ending balance: " << saving->getbalance() << endl;

    //Checkingaccount
    BankAccount *checking = new CheckingAccount(500, 10);

    cout << "Enter amount to deposit in checking account: ";
    cin >> depositAmount;
    checking->deposit(depositAmount);

    monthStartBalance = depositAmount;

    cout << "Enter amount to withdraw from checking account: ";
    cin >> withdrawAmount;

    checking->withdraw(withdrawAmount);
    //Print output for checkings account
    cout << "Month start balance: " << monthStartBalance << endl;
    cout << "Total No of depost: " << checking->getNoOfDeposit() << endl;
    cout << "Total no of withdrawl: " << checking->getNoOfWithdrawl() << endl;
    cout << "Monthly service charge: " << checking->getMonthleServiceCharge() << endl;
    cout << "Month Ending balance: " << checking->getbalance() << endl;
    getchar();

    return 0;

}


