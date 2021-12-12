/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
    a² + b² = c²
For example, 3² + 4² = 9 + 16 = 25 = 5².
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int target = 1000;
    
    for (int i = 0; i < target; i++)
    {
        for (int j = i + 1; j < target; j++)
        {
            for (int k = j + 1; k < target; k++)
            {
                if ((i + j + k == target) && (pow(i, 2) + pow(j, 2) == pow(k, 2)))
                {   
                    printf("Answer: %lld\n", i * j * k);
                    break;
                }
            }
        }
    }

    return 0;
}