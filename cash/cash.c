#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents;
    do
    {

        cents = get_int("Enter the change owed: ");
    }
    while (0 > cents);

    int quaters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int count = 0;

    while (cents >= quaters)
    {
        cents -= quaters;
        count++;
    }
   
    while (cents >= dimes)
    {
        cents -= dimes;
        count++;
    }

    while (cents >= nickels)
    {
        cents -= nickels;
        count++;
    }
    while (cents >= pennies)
    {
        cents -= pennies;
        count++;
    }

    printf("%i\n", count);
}
