/*
In the 20×20 grid below, four numbers along a diagonal line have been marked in red.
    source/11.txt
The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int max(int number1, int number2, int number3);

int main()
{   
    // Try to open file
    FILE* file = fopen("../source/11.txt", "r");
    if (file == NULL)
    {
        printf("Error.\n");
        exit(-1);
    }

    // fseek(file, 0L, SEEK_END);
    // int size = (int)ftell(file);
    // printf("size: %d\n", size);
    

    char input[1200];
    int numbers[1200], index;
    int rows = 20, greatest_product = 0;

    // Read and assign to input the chars in file
    for (int i = 0; i < 1200; i++)
    {
        fscanf(file, "%c", &input[i]);
    }

    //Assign to numbers the chars of input
    index = 0;
    for (int i = 0; i < 1200; i++)
    {
        if (isdigit(input[i]))
        {
            numbers[index] = ((input[i] - '0') * 10) + (input[i + 1] - '0');
            index++;
            i++;
        }
    }


    int horizontal_product, vertical_product, diagonal_product, diagonal1_product, diagonal2_product, max_product;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            index = (i * rows) + j;

            if (j < 17)
            {
                horizontal_product = numbers[index] * numbers[index + 1] * numbers[index + 2] * numbers[index + 3];
            }            

            if (i < 17)
            {
                vertical_product = numbers[index] * numbers[index + 20] * numbers[index + 40] * numbers[index + 60];
            }
            
            if (i < 17 && j < 17)
            {
                // top down
                diagonal1_product = numbers[index] * numbers[index + 21] * numbers[index + 42] * numbers[index + 63];

                // down top
                diagonal2_product = numbers[index + 60] * numbers[index + 41] * numbers[index + 22] * numbers[index + 3];

                diagonal_product = max(diagonal1_product, diagonal2_product, 0);
            }

            max_product = max(horizontal_product, vertical_product, diagonal_product);
            if (max_product > greatest_product)
            {
                greatest_product = max_product;
            }

        }        
        
    }
    printf("Answer: %d\n", greatest_product);


    return 0;
}

int max(int number1, int number2, int number3)
{
    if (number1 >= number2 && number1 >= number3)
    {
        return number1;
    }

    if (number2 >= number3)
    {
        return number2;
    }

    return number3;
}