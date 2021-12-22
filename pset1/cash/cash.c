#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Get dollar amount
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);
    
    // Convert to cents
    int cents = round(dollars * 100);
    
    printf("%i\n", cents);
    
    // Get quarters
    int quarters = cents / 25;
    cents -= (quarters * 25);
    
    // Get dimes
    int dimes = cents / 10;
    cents -= (dimes * 10);
    
    // Get nickels
    int nickels = cents / 5;
    cents -= (nickels * 5);
    
    // Get pennies
    int pennies = cents;
    
    // Coins
    int coins = quarters + dimes + nickels + pennies;
    
    // Print result
    printf("%i\n", coins);
    
}