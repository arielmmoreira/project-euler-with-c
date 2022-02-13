/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
    source\13.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE* file = fopen("../source/13.txt", "r");
    if (file == NULL)
    {
        printf("Error.\n");
        exit(-1);
    }

    fseek(file, 0L, SEEK_END);
    fseek(file, 0, SEEK_SET);

    // length of nuber * rows + rows ('\n')
    int file_size = 5100;
    
    char input[file_size];

    // Read and assign to input the chars in file
    for (int i = 0; i < file_size; i++)
    {
        fscanf(file, "%c", &input[i]);
    }


    int total_numbers = 100;
    int number_digits = 50;
    int limit = total_numbers * number_digits;
    int numbers[limit];
    int sum[1000] = {0};
    int index = 0;
    int number;

    for (int i = 0; i < file_size; i++)
    {
        if (isdigit(input[i]) > 0)
        {
            numbers[index] = input[i] - '0';
            index++;
        } 
    }

    index = 0;
    int count = 0;

    for (int i = number_digits - 1; i >= 0; i--)
    {
        number = sum[index];
        for (int j = 0; j < limit; j+=number_digits)
        {
            number += numbers[i + j];
            
        }

        if (number / 100 > 0)
        {
            
            sum[index] = number % 10;
            index++;
            sum[index] += (number / 10) % 10;
            index++;
            sum[index] += number / 100;          
            index--;
            
        }

        else if (number / 10 > 0)
        {
            sum[index] = number % 10;
            index++;
            sum[index] = number / 10;
        }
        else
        {
            
            sum[index] = number / 10;
            index++;
        }        
    }
    index++;
    
    printf("Answer: ");
    for (int i = index; i > index - 10; i--)
    {
        printf("%d", sum[i]);
    }   
   
}