/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n);


int main()
{
    long long int number = 600851475143;
    int divisor = 2;
    
    while (number != 1)
    {
        if (is_prime(divisor) && number % divisor == 0)
        {
            number = number / divisor;
            continue;
        }

        divisor++;
    }
    printf("largest prime factor: %d\n", divisor);

    return 0;
}

bool is_prime(int n)
{
    int limit = round(pow(n, 0.5));

    for (int i = 2; i < limit; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}