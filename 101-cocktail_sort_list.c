#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void cocktail_sort_list(listint_t **list);

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *			order using the Insertion sort algorithm
 * @list : doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp1, *temp2, *cur, *pv, *nx, *temp3, *temp4, *temp5;
	int ind, i = 0, j;

	if (!list)
		return;
	temp1 = *list;
	while (temp1)
	{
		cur = temp1;
		ind = i;
		j = 0;
		while (cur && cur->next)
		{
			i = 0;
			if (cur->n > cur->next->n)
			{
				nx = cur->next;
				temp2 = cur;
				temp3 = cur->prev;
				cur = nx;
				nx = temp2;
				nx->prev = cur;
				if (cur->next)
				{
					nx->next = cur->next;
					nx->next->prev = nx;
				}
				else
					nx->next = NULL;
				cur->next = nx;
				cur->prev = temp3;
				if (cur->prev)
					cur->prev->next = cur;
				j++;
				print_list(*list);
			}
			temp4 = cur;
			cur = cur->next;
			i++;
			if (ind == 0)
				continue;
			if (i > ind)
				break;
		}

		while (cur && cur->prev)
		{
			if (cur->n < cur->prev->n)
			{
				pv = cur->prev;
				temp2 = cur;
				temp4 = cur->next;
				cur = pv;
				pv = temp2;
				pv->next = cur;
				if (cur->prev)
				{
					pv->prev = cur->prev;
					pv->prev->next = pv;
				}
				else
					pv->prev = NULL;
				cur->prev = pv;
				cur->next = temp4;
				if (cur->next)
					cur->next->prev = cur;

				if (pv->prev == NULL)
					*list = pv;
				j++;
				print_list(*list);
			}
			temp5 = cur;
			cur = cur->prev;
			if (cur == temp1)
				break;
		}
		temp1 = temp5;
		if (j == 0)
			break;
	}
}
