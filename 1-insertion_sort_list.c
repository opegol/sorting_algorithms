#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *			order using the Insertion sort algorithm
 * @list : doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp1, *temp2, *cur, *pv, *temp3;

	if (!list)
		return;
	temp1 = *list;
	while (temp1)
	{
		if ((temp1->prev) == NULL)
		{
			temp1 = temp1->next;
			continue;
		}
		cur = temp1;
		temp1 = temp1->next;
		while (cur && cur->prev && (cur->n < cur->prev->n))
		{
			pv = cur->prev;
			temp2 = cur;
			temp3 = cur->next;
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
			cur->next = temp3;
			if (cur->next)
				cur->next->prev = cur;
			cur = cur->prev;
			if (pv->prev == NULL)
				*list = pv;
			print_list(*list);
		}
	}
}
