#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a doubly circular linked list
 * @list: Pointer to the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
List *new_node, *tail;

if (!list || !str)
return (NULL);

new_node = malloc(sizeof(List));
if (!new_node)
return (NULL);

new_node->str = strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
if (*list == NULL)  /* Empty list case */
{
new_node->next = new_node->prev = new_node;
*list = new_node;
}
else
{
tail = (*list)->prev;  /* Last node in the list */
new_node->next = *list;
new_node->prev = tail;
tail->next = new_node;
(*list)->prev = new_node;
}
return (new_node);
}

/**
 * add_node_begin - Adds a new node to the beg of a doubly circular lk list
 * @list: Pointer to the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
List *new_node;

new_node = add_node_end(list, str);  /* Reuse add_node_end to add node */
if (!new_node)
return (NULL);

*list = new_node;  /* Update head to point to new node */
return (new_node);
}
