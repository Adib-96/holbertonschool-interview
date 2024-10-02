#include "holberton.h"
#include <stdlib.h>

/**
 * is_digit - Checks if a string is composed only of digits.
 * @s: The string to check.
 *
 * Return: 1 if all characters are digits, otherwise 0.
 */
int is_digit(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string whose length to check.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
    int length = 0;

    while (s[length])
        length++;
    return (length);
}

/**
 * print_error_and_exit - Prints error message and exits with status 98.
 */
void print_error_and_exit(void)
{
    _putchar('E');
    _putchar('r');
    _putchar('r');
    _putchar('o');
    _putchar('r');
    _putchar('\n');
    exit(98);
}

/**
 * main - Multiplies two positive numbers.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
    char *num1, *num2;
    int len1, len2, len, i, j, carry, n1, n2, *result;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
        print_error_and_exit();

    num1 = argv[1];
    num2 = argv[2];
    len1 = _strlen(num1);
    len2 = _strlen(num2);
    len = len1 + len2;

    result = calloc(len, sizeof(int));
    if (result == NULL)
        print_error_and_exit();

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = num1[i] - '0';
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            carry += result[i + j + 1] + (n1 * n2);
            result[i + j + 1] = carry % 10;
            carry /= 10;
        }
        result[i + j + 1] += carry;
    }

    i = 0;
    while (i < len && result[i] == 0)
        i++;
    if (i == len)
        _putchar('0');
    while (i < len)
        _putchar(result[i++] + '0');
    _putchar('\n');

    free(result);
    return (0);
}
