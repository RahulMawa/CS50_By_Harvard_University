#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //input function
    long cardNumber = get_long("What's your credit card number: ");
    long x = cardNumber;
    int length = 0;
    int sum1 = 0;
    int sum2 = 0;
    int temp = 0;
    long power = cardNumber;
    long visa = 0;
    int check = 0; //for card Numbers with last digit zero, but dont qualify other checks

    //finding length of credict card number algorithm
    for (long count = 1; count <= cardNumber; count *= 10)
        {
        length++;
        }

    if(length < 13 || length > 16)
        {
        printf("EOF\n");
        }

    //checksum algorithm
    for (int i = 0; i <= (length / 2) + 1; i++)
        {
        sum1 = sum1 + (x % 10);
        x = x / 10;
        int twoDigits = (2 * (x % 10));
        
        if (twoDigits > 9)
            {
            temp = temp + (twoDigits % 10);
            twoDigits /= 10;
            temp = temp + twoDigits;
            sum2 = sum2 + temp;
            temp = 0;
            }
        
        else
            {
            sum2 = sum2 + twoDigits;
            }

        x = x / 10;   
    }
        
    int sumfinal = sum1 + sum2;

    if (sumfinal % 10 == 0)
        {
        visa = power / (pow (10, (length - 1)));
        power = power / (pow (10, (length - 2)));
        
        //American Express
        if (length == 15 && (power == 34 || power == 37)) 
            {
            printf("AMEX\n");
            check ++;
            }

        //MasterCard
        if (length == 16 && (power == 51 || power == 52 || power == 53 || power == 54 || power == 55))
            {
            printf("MASTERCARD\n");
            check++;
            }

        //Visa
        if  (visa == 4 && (length == 13 || length == 16))
            {
            printf("VISA\n");
            check++;
            }        
        }
        
        else
            {
            printf("INVALID\n");
            }

        if  (check == 0)
            {
            printf("INVALID\n");
            }
}
