/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int number = 2;
    
    while (true)
    {
        bool found = true;
        for (int i = 1; i <= 20; i++)
        {
            if (number % i != 0)
            {
                found = false;
                number++;
            }
        }
        if (found)
        {
            break;
        }

    }
    printf("Answer: %d\n", number);

    return 0;
}