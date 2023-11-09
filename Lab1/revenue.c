#include <stdio.h>
#include <stdlib.h>
// John Currie
// 9/10/2023
// CIS 2107
// Lab 2
// This program calculates the revenue of a sale based on the item price and quantity ordered.

int main()
{
    // Welcome message
    printf("Welcome to \"Temple\" store\n\n");

    // Input item price
    double itemPrice;
    printf("Enter item price: ");
    if (scanf("%lf", &itemPrice) != 1 || itemPrice <= 0)
    {
        printf("This is not a valid item price.\nPlease run the program again\n\n");
        printf("Thank You for using \"Temple\" store\n");
        exit(1);
    }

    // Input quantity
    double quantity;
    printf("Enter quantity: ");
    if (scanf("%lf", &quantity) != 1 || quantity <= 0 || (double)(int)quantity != quantity)
    {
        printf("This is not a valid quantity order.\nPlease run the program again\n\n");
        printf("Thank You for using \"Temple\" store\n");
        exit(1);
    }

    // Calculate cost
    double cost = itemPrice * quantity;
    double discountRate;

    // Calculate discount rate and apply discount
    if (quantity >= 1 && quantity <= 49)
    {
        discountRate = 0.0;
    }
    else if (quantity >= 50 && quantity <= 99)
    {
        discountRate = 10.0;
    }
    else if (quantity >= 100 && quantity <= 149)
    {
        discountRate = 15.0;
    }
    else
    {
        discountRate = 25.0;
    }

    double discountAmount = (discountRate / 100.0) * cost;
    double total = cost - discountAmount;

    // Display results
    printf("\n");
    printf("The item price is: $%.1lf\n", itemPrice);
    printf("The order is: %.0lf item(s)\n", quantity);
    printf("The cost is: $%.1lf\n", cost);
    printf("The discount is: %.1lf%%\n", discountRate);
    printf("The discount amount is: $%.1lf\n", discountAmount);
    printf("The total is: $%.1lf\n\n", total);

    // Closing message
    printf("Thank You for using \"Temple\" store\n");

    return 0;
}