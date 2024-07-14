#include "lists.h"

listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return *head;
}

int is_palindrome(listint_t **head)
{
    if (!head || !*head)
        return 1;

    listint_t *slow = *head, *fast = *head, *first_half = *head, *second_half;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    second_half = reverse_listint(&slow);

    listint_t *temp_second_half = second_half;
    while (second_half)
    {
        if (first_half->n != second_half->n)
        {
            reverse_listint(&temp_second_half); // Restore original list
            return 0;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    reverse_listint(&temp_second_half);

    return 1;
}
