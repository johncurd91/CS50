#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    long cc_num = get_long("Number: ");
    
    long x = cc_num;
    int sum1 = 0;
    int sum2 = 0;
    while (x)
    {
        // Get sum1
        int z = x % 10;
        sum1 += z;
        
        // Get sum2
        // Get second to last digit
        int y = x % 100 / 10;
        
        // Multiply second to last digit
        y = y * 2;
        
        // Add those digits together
        sum2 += y % 10;
        sum2 += y % 100 / 10;
        
        // Remove last two digits from x
        x = x / 100;
        
    }
    
    // Perform checksum
    int sum3 = sum1 + sum2;
    sum3 = sum3 % 10;
    bool checksum = (sum3 % 10 == 0);
    
    // Check number of digits
    long n = cc_num;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    
    // Check if valid
    if (checksum)
    {
        // Get first two digits of cc_num
        long first = cc_num;
        while (first >= 100)
        {
            first = first / 10;
        }
        
        // Check what type of card it is
        // Check if its a MasterCard
        if (first <= 55 && first >= 51 && count == 16)
        {
            printf("MASTERCARD\n");
        }
        // Else check if its an Amex
        else if ((first == 34 || first == 37) && count == 15)
        {
            printf("AMEX\n");
        }
        // Else check if it is a Visa
        else if (first <= 49 && first >= 40 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}