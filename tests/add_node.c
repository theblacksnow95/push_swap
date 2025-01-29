/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:14:53 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/29 12:55:58 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insert_node(t_node **head, int value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit (1);
	new_node->next = NULL;
	new_node->x = value;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	deallocate(t_node **root)
{
	t_node	*curr;
	t_node	*aux;

	curr = *root;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}

int	main(void)
{
	t_node	*head;
	t_node	*curr;

	head = NULL;
	insert_node(&head, -12);
	insert_node(&head, 8);
	insert_node(&head, 9);
	insert_node(&head, 53);
	insert_node(&head, 37);
	curr = head;
	while (curr != NULL)
	{
		printf("Value: %d\n", curr->x);
		curr = curr->next;
	}
	deallocate(&head);
	return (0);
}
