#include <stdio.h>
#include <stdlib.h>
#include "account.h"

// The actual definition is hidden here
struct Account {
    int balance;
};

// Create an account
Account *createAccount(int initialBalance)
{
    Account *account = malloc(sizeof(Account));

    if (account == NULL)
        return NULL;

    account->balance = initialBalance;

    return account;
}

// Add money
void deposit(Account *account, int amount)
{
    if (amount > 0)
        account->balance += amount;
}

// Withdraw money
void withdraw(Account *account, int amount)
{
    if (amount > 0 && amount <= account->balance)
        account->balance -= amount;
}

// Access the balance through a controlled function
int getBalance(const Account *account)
{
    return account->balance;
}

// Destroy the account
void destroyAccount(Account *account)
{
    free(account);
}