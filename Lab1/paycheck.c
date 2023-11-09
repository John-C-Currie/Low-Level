#include <stdio.h>
#include <stdlib.h>
// John Currie
// 9/10/2023
// CIS 2107
// Lab 2
// This program calculates the net pay of an employee based on their hourly salary and weekly time.

int main()
{
    // Welcome message
    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n\n");

    // Input employee number
    double employeeNumber;
    printf("Enter Employee Number: ");
    if (scanf("%lf", &employeeNumber) != 1 || employeeNumber <= 0 || (double)(int)employeeNumber != employeeNumber)
    {
        printf("This is not a valid Employee Number.\nPlease run the program again\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }

    // Input hourly salary
    double hourlySalary;
    printf("Enter Hourly Salary: ");
    if (scanf("%lf", &hourlySalary) != 1 || hourlySalary <= 0)
    {
        printf("This is not a valid hourly salary amount.\nPlease run the program again\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }

    // Input weekly time
    double weeklyTime;
    printf("Enter Weekly Time: ");
    if (scanf("%lf", &weeklyTime) != 1 || weeklyTime <= 0 || (double)(int)weeklyTime != weeklyTime)
    {
        printf("This is not a weekly time.\nPlease run the program again\n\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }

    // Calculate regular pay and overtime pay
    double regularPay, overtimePay, netPay;
    if (weeklyTime <= 40)
    {
        regularPay = weeklyTime * hourlySalary;
        overtimePay = 0.0;
    }
    else
    {
        regularPay = 40 * hourlySalary;
        overtimePay = (weeklyTime - 40) * 1.5 * hourlySalary;
    }

    // Calculate net pay
    netPay = regularPay + overtimePay;

    // Display results
    printf("==============================\n");
    printf("Employee #: %.0lf\n", employeeNumber);
    printf("Hourly Salary: $%.1lf\n", hourlySalary);
    printf("Weekly Time: %.1lf\n", weeklyTime);
    printf("Regular Pay: $%.1lf\n", regularPay);
    printf("Overtime Pay: $%.1lf\n", overtimePay);
    printf("Net Pay: $%.1lf\n", netPay);
    printf("==============================\n\n");

    // Closing message
    printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");

    exit(0);
}