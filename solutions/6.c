/*
The sum of the squares of the first ten natural numbers is
    1² + 2² + ... + 10² = 385

The square of the sum of the first ten natural numbers is,
    (1 + 2 + ... + 10)² = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
    3025 - 385 = 2640

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <stdio.h>
#include <math.h>

int sum_of_squares(int limit);
int square_of_sum(int limit);

int main()
{
    int limit = 100;
    printf("Answer: %d\n", square_of_sum(limit) - sum_of_squares(limit));

    return 0;
}

int sum_of_squares(int limit)
{
    int sum = 0;

    for (int i = 1; i <= limit; i++)
    {
        sum += pow(i, 2);
    }

    return sum;
}


int square_of_sum(int limit)
{
    int square, sum = 0;

    for (int i = 1; i <= limit; i++)
    {
        sum += i;
    }
    square = pow(sum, 2);

    return square;
}