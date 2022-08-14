#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // declare variable to output
    int cents_res;
    // prompt user for cents value, continue asking if they input a negative number
    do
    {
        cents_res = get_int("How many cents is the customer owed? ");
    }
    while (cents_res < 0);

    return cents_res;
}

int calculate_quarters(int cents)
{
    // division in C is automatically floor division
    int quarters_res = (cents / 25);
    return quarters_res;
}

int calculate_dimes(int cents)
{
    int dimes_res = (cents / 10);
    return dimes_res;
}

int calculate_nickels(int cents)
{
    int nickels_res = (cents / 5);
    return nickels_res;
}

int calculate_pennies(int cents)
{
    int pennies_res = (cents);
    return pennies_res;
}
