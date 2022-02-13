/*
The following iterative sequence is defined for the set of positive integers:
    n → n/2 (n is even)
    n → 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int get_length_of_collatz_sequence(long long n, long long array[], int limit);
void populate_array(long long array[], int limit);

int main()
{
    int current_length = 0;
    int biggest_sequence = 0;
    long number_biggest_sequence = 0;
    int limit = pow(10, 6);
    long long *collatz_sequence = malloc(limit * sizeof(long long));
    
    populate_array(collatz_sequence, limit);
 
    for (long long i = 1; i <= limit; i++)
    {
        current_length = get_length_of_collatz_sequence(i, collatz_sequence, limit);
        if (current_length > biggest_sequence)
        {
            biggest_sequence = current_length;
            number_biggest_sequence = i;
        }
    }

    free(collatz_sequence);

    printf("Answer: %ld\n", number_biggest_sequence);

    return 0;
}

void populate_array(long long array[], int limit)
{
    for (long long i = 0; i < limit; i++)
    {
        array[i] = 0;
    }
}

int get_length_of_collatz_sequence(long long n, long long array[], int limit)
{
    long long current_number = n;
    int count = 1;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n >> 1;
        }
        else
        {
            n = ((3 * n) + 1);
        }

        if (n < limit && array[n] > 0)
        {
            count += array[n];
            array[current_number] = count;
            return count;
        }
        count++;              
    }   
    
    if (current_number < limit)
    {
        array[current_number] = count;
    }
    
    return count;
}

/* get time of execution

    clock_t begin = clock();
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%2f\n", time_spent);
*/