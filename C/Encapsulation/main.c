#include <stdio.h>
#include "account.h"

int main(void)
{
    Account *myAccount = createAccount(1000);

    if (myAccount == NULL)
        return 1;

    deposit(myAccount, 500);
    withdraw(myAccount, 200);

    printf("Balance = %d\n", getBalance(myAccount));

    myAccount->balance = 100000; /// Not allowed
    /* Why?
       Because the definition of struct Account is hidden
       inside account.c.
    */

    destroyAccount(myAccount);

    return 0;
}