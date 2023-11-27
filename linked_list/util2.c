#include "list.h"

void delete_node_at_head(node_t **head)
{
	node_t *tmp;

	if (!head || !*head)
		return;
	tmp = *head;
	*head = tmp->next;
	printf("This is the deleted value, %d\n", tmp->data);
	free(tmp);

}

void delete_node_at_tail(node_t **head)
{
	node_t *tmp;

	if (!head || !*head)
		return;
	tmp = *head;
	printf("Deleting at tail\n");
	fflush(stdout);
	if (!tmp->next)
	{
		free(tmp);
		*head = NULL;
		return;
	}
	while (tmp)
	{
		if (tmp->next && !tmp->next->next)
		{
			free(tmp->next);
			tmp->next = NULL;
			break;
		}
		tmp = tmp->next;
	}
	printf("tail\n");
}

void delete_node_at_index(node_t **head, int idx)
{
	node_t *tmp, *del_node;
	int i = 0;

	if (!head || !*head)
		return;
	tmp = *head;
	if (idx == 0)
	{
		*head = (*head)->next;
		free(tmp);
	}
	while (tmp && tmp->next)
	{
		if (i == idx - 1)
		{
			del_node = tmp->next;
			tmp->next = del_node->next;
			free(del_node);
		}
		i++;
		tmp = tmp->next;
	}

	printf("index\n");
}
