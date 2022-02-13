/*
The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
    source\8.txt
Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char str[1038];
    int number_array[1038], number, count, index;
    long long int product, greatest_product;

    // Try to open file
    FILE* file = fopen("../source/8.txt", "r");
    if (file == NULL)
    {
        printf("Error.\n");
        exit(-1);
    }

    // Read and assign to str array the chars in file
    for (int i = 0; i < 1038; i++)
    {
        fscanf(file, "%c", &str[i]);
    }


    // Assign to number_array the chars of str
    index = 0;
    for (int i = 0; i < 1038; i++)
    {
        if (isdigit(str[i]))
        {
            number_array[index] = str[i] - '0';
            index++;
        }
    }

    // Check the greatest product
    greatest_product = 0;
    product = 1;
    for (int i = 0; i < 1038 - 13; i++)
    {
        for (int j = i; j < 13 + i; j++)
        {
            number = number_array[j];
            product *= number;     
        }

        if (product > greatest_product)
        {
            greatest_product = product;
        }

        product = 1;
    }
    

    printf("Answer: %lld\n", greatest_product);

    fclose(file);

    return 0;
}
