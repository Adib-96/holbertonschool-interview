#include "holberton.h"

/**
 * wildcmp - Compares two strings, accounting for wildcard '*' in s2.
 * @s1: The first string.
 * @s2: The second string (may contain wildcard '*').
 *
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
if (*s2 == '\0')
return (*s1 == '\0');

if (*s2 == '*')
{
while (*(s2 + 1) == '*')
s2++;

return (wildcmp(s1, s2 + 1) || (*s1 && wildcmp(s1 + 1, s2)));
}

if (*s1 == *s2)
return (wildcmp(s1 + 1, s2 + 1));

return (0);
}
