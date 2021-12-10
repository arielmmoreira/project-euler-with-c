/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n);

int main()
{
    int position, number, target;
    position = 0;
    number = 2;
    target = 10001;

    while (true)
    {
        if (is_prime(number))
        {
            position++;
        }

        if (position == target)
        {
            break;
        }
        number++;
    }
    printf("Answer: %d\n", number);

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