#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //ask user for card number
    long num = get_long("Enter a credit card number ");
    //count the digits
    int dig = 0;
    long card = num;
    while (card > 0)
    {
        card = card / 10;
        dig++;
    }

    if (dig != 13 && dig != 15 && dig != 16) //check the lenght of number to see if it could be a credit card
    {
        printf("INVALID\n");
        return 0;
    }

    //calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long x = num;
    int totalSum = 0;
    int rem1;
    int rem2;
    int dig1;
    int dig2;

    do
    {
        //get every other digit starting from the last digit
        rem1 = x % 10;
        x = x / 10;
        sum1 = sum1 + rem1;

        //get second to last digit
        rem2 = x % 10;
        x = x / 10;

        //double digits and add to sum
        rem2 = rem2 * 2;
        dig1 = rem2 % 10;
        dig2 = rem2 / 10;
        sum2 = sum2 + dig1 + dig2;
    }
    while (x > 0);
    totalSum = sum1 + sum2;
    //check if last digit of sum equals 0
    if (totalSum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    //check for starting digits
    long firstDigits = num;
    do
    {
        firstDigits /= 10;
    }
    while (firstDigits > 100);
    if (firstDigits == 37 || firstDigits == 34)
    {
        printf("AMEX\n");
    }

    else if (firstDigits > 50 && firstDigits <= 55)
    {
        printf("MASTERCARD\n");
    }

    else if ((firstDigits / 10) == 4)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}