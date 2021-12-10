/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int get_length(int number);
bool is_palindrome(char str[], int length);
void int_to_char_array(int number, int length, char str[]);

int main()
{
    int length, product, digits, limit, biggest;
    digits = 3;
    limit = pow(10, digits) - 1;
    biggest = 0;
    
    for (int i = limit; i > 0; i--)
    {
        for (int j = limit; j > 0; j--)
        {
            product = i * j;
            length = get_length(product);
            char str[length];
            int_to_char_array(product, length, str);
            
            if (is_palindrome(str, length) && product > biggest)
            {
                biggest = product;
            }
        }
    }
    printf("biggest: %d\n", biggest);

    return 0;
}

void int_to_char_array(int number, int length, char str[])
{
    for (int i = length - 1; i >= 0; i--)
    {
        str[i] = number % 10 + '0';
        number = number / 10;
    }
}

int get_length(int number)
{
    int length = 0;

    while (number != 0)
    {
        number = number / 10;
        length++;
    }

    return length;
}

bool is_palindrome(char str[], int length)
{
    int aux = 1;
    for (int i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - aux])
        {
            return false;
        }
        aux++;
    }

    return true;
}