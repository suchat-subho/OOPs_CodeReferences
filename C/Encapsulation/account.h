#ifndef ACCOUNT_H
#define ACCOUNT_H

// Opaque structure: internal members are hidden
typedef struct Account Account;

// Public operations
Account *createAccount(int initialBalance);
void deposit(Account *account, int amount);
void withdraw(Account *account, int amount);
int getBalance(const Account *account);
void destroyAccount(Account *account);

#endif