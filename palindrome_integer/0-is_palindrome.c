#include "palindrome.h"

int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0, original = n;

    while (n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }

    if (original == reversed) {
        return 1;
    } else {
        return 0;
    }
}
