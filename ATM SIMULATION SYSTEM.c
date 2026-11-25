/* ATM Simulation System */
#include <stdio.h>

int balance = 10000;
int pin = 1428;

int checkBalance()
{
    printf("Your balance is: %d\n", balance);
    return 0;
}

int withdraw()
{
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);

    if (amount <= 0)
        printf("Invalid amount\n");
    else if (amount > balance)
        printf("Insufficient balance\n");
    else
    {
        balance = balance - amount;
        printf("Please collect your cash\n");
        printf("Remaining balance: %d\n", balance);
    }
    return 0;
}

int deposit()
{
    int amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);

    if (amount <= 0)
        printf("Invalid amount\n");
    else
    {
        balance = balance + amount;
        printf("Deposit successful\n");
        printf("New balance: %d\n", balance);
    }
    return 0;
}

int changePin()
{
    int oldPin, newPin;
    printf("Enter old PIN: ");
    scanf("%d", &oldPin);

    if (oldPin == pin)
    {
        printf("Enter new PIN: ");
        scanf("%d", &newPin);
        pin = newPin;
        printf("PIN changed successfully\n");
    }
    else
        printf("Wrong old PIN\n");
    return 0;
}

int main()
{
    int i, enteredPin, choice;
    int ok = 0;

    printf("***** WELCOME TO ATM *****\n");

    for (i = 1; i <= 3; i++)
    {
        printf("Enter PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin)
        {
            ok = 1;
            break;
        }
        else
            printf("Wrong PIN\n");
    }

    if (ok == 0)
    {
        printf("Too many wrong attempts. Card blocked.\n");
        return 0;
    }

    while (1)
    {
        printf("\n1. Balance Enquiry\n");
        printf("2. Withdraw Cash\n");
        printf("3. Deposit\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: checkBalance(); break;
            case 2: withdraw(); break;
            case 3: deposit(); break;
            case 4: changePin(); break;
            case 5: printf("Thank you!\n"); return 0;
            default: printf("Wrong choice\n");
        }
    }
}