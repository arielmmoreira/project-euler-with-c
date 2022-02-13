/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n);

int main()
{
    int limit = 2 * pow(10, 6);
    long long int sum = 0;
    int prime_number = 2;
    
    while (prime_number <= limit)
    {
        if (is_prime(prime_number))
        {
            sum += prime_number;
        }
        prime_number++;
    }
    printf("Answer: %lld\n", sum);

    return 0;
}

bool is_prime(int n)
{
    int limit = round(pow(n, 0.5));

    for (int i = 2; i < limit + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}