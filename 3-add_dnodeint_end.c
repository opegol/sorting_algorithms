#include <stdlib.h>
#include <string.h>
#include "lists.h"


/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head : old dlistint_t head
 * @n : dlistint_t list int element
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *cur;
	dlistint_t *temp;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if ((*head) == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	else
	{
		cur = *head;
		while (cur != NULL)
		{
			temp = cur;
			cur = cur->next;
		}
	}
	new->prev = temp;
	temp->next = new;
	return (new);
}
