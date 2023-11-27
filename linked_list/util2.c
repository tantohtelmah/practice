#include "list.h"

void delete_node_at_head(node_t **head)
{
	node_t *node, *tmp;

	while (!head)
		return;
	tmp = *head;
	node = tmp->next;
	tmp->next = NULL;
	node = *head;
	printf("This is the deleted value, %d\n", tmp->data);

}

void delete_node_at_tail(node_t **head)
{
	node_t *node, *tmp;

	if (!head)
		return;
	if (!*head)
		return;
	tmp = *head;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp = NULL;

	printf("tail\n");
}

void delete_node_at_index(node_t **head, int idx)
{
	node_t *tmp, *prev_node = NULL;
	int i = 0;

	if (!head)
		return;
	tmp = *head;
	if (idx == 0)
	{
		printf("invalid index");
	}
	while (tmp)
	{
		i++;
		if (i == idx - 1)
		{
			prev_node = tmp;
			continue;
		}
		if (i == idx)
		{
			prev_node->next = tmp->next;
		}
		tmp = tmp->next;
	}

	printf("index\n");
}