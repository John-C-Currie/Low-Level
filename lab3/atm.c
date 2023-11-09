#include <stdio.h>
#include <stdlib.h>
//John Currie
//CIS 2107
//9/17/2023
//Lab3
//Simulate an ATM for a particular user "Nana" who has a pin of 3014 and a balance of $5000
//Nana can only input numbers, has 3 tries for her pin and has a withdraw limit or $1000/deposit limit of $10000

// Function to display the welcome message
void displayWelcomeMessage() 
{
    puts("Welcome to the ATM!");
}

// Function to validate PIN with three attempts
int validatePIN() 
{
    int attempts = 3;
    int pin = 3014;
    int enteredPin;

    while (attempts > 0) 
    {
        printf("%s", "Please enter your PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) 
        {
           puts("PIN accepted.");
            return 1; // PIN validation successful
        } 
        else 
        {
            printf("Invalid PIN. %d attempts remaining.\n", attempts - 1);
            attempts--;
        }
    }

    puts("Maximum attempts reached. Logging off.");
    return 0; // PIN validation failed
}

// Function to display the ATM menu
void displayMenu() 
{
    puts("\nATM Menu:");
    puts("1. Balance");
    puts("2. Cash withdrawal");
    puts("3. Cash deposition");
    puts("4. Quit");
}

// Function to perform balance inquiry
void checkBalance(int balance) 
{
    printf("Your balance is $%d\n", balance);
}

// Function to perform cash withdrawal
int withdrawCash(int balance, int totalWithdrawn) 
{
    int attempts = 0;
    int withdrawalAmount = 0;
    printf("%s", "Enter the amount to withdraw (in multiples of 20s): $");
    scanf("%d", &withdrawalAmount);

    if (withdrawalAmount <= 0 || withdrawalAmount % 20 != 0) 
    {
        puts("Invalid withdrawal amount. Please enter a valid amount in multiples of 20s.");
        return balance;
    }
    if() && if()
    {
        
    }
    if (withdrawalAmount + totalWithdrawn > 1000) 
    {
        puts("Withdrawal limit exceeded. Maximum withdrawal amount is $1000.");
        return balance;
    }

    if (withdrawalAmount > balance) 
    {
        puts("Insufficient balance.");
        return balance;
    }

    balance -= withdrawalAmount;
    printf("Withdrawal successful. New balance: $%d\n", balance);
    return balance;
}

// Function to perform cash deposition
int depositCash(int balance, int totalDeposited) 
{
    int depositAmount = 0;
    printf("%s", "Enter the amount to deposit: $");
    scanf("%d", &depositAmount);

    if (depositAmount <= 0 || depositAmount + totalDeposited > 10000) 
    {
        puts("Invalid deposit amount. Please enter a valid amount (up to $10000).");
        return balance;
    }

    balance += depositAmount;
    printf("Deposit successful. New balance: $%d\n", balance);
    return balance;
}

int quit(int transactions)
{
    printf("Total transactions: %d\n", transactions);
    puts("Thank you for using the ATM.");
    return 0;
}

int main() 
{
    int choice;
    int balance = 5000;
    int transactions = 0;
    int totalWithdrawn = 0;
    int totalDeposited = 0;

    displayWelcomeMessage();
    if (!validatePIN()) 
    {
        return 0; // Exit program if PIN validation fails
    }

    while (1) 
    {
        displayMenu();
        printf("%s", "Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                checkBalance(balance);
                break;
            case 2: 
            {
                if (totalWithdrawn >= 1000) 
                {
                    puts("Withdrawal limit reached for this session. Maximum withdrawal amount is $1000.");
                } 
                else 
                {
                    int newBalance = withdrawCash(balance, totalWithdrawn);
                    transactions++;
                    totalWithdrawn += balance - newBalance;
                    balance = newBalance;
                }
                break;
            }
            case 3: {
                if (totalDeposited >= 10000) 
                {
                    puts("Deposit limit reached for this session. Maximum deposit amount is $10000.");
                } 
                else 
                {
                    int newBalance = depositCash(balance, totalDeposited);
                    transactions++;
                    totalDeposited += newBalance - balance;
                    balance = newBalance;
                }
                break;
            }
            case 4:
                return quit(transactions);
            default:
                puts("Invalid choice. Please select a valid option.");
        }
        
        if(choice >= 1 && choice <= 4)
        {
            int printReceiptChoice;
            printf("%s","Do you want to print a receipt? (1 for Yes, 2 for No): ");
            scanf("%d", &printReceiptChoice);

            if (printReceiptChoice == 1) 
            {
                puts("Printing receipt.");
            }
        }
    }

    return 0;
}