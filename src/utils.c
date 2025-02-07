/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:13:40 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/07 16:08:21 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	start_insert(t_stack **tail, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->num = value;
	new_node->prev = NULL;
	new_node->next = *tail;
	if (*tail != NULL)
		(*tail)->prev = new_node;
	*tail = new_node;
}

void	end_insert(t_stack **tail, int value)
{
	t_stack	*new_node;
	t_stack	*curr;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->num = value;
	if (*tail == NULL)
	{
		*tail = new_node;
		return ;
	}
	curr = *tail;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	deallocate(t_stack **tail, t_stack **head)
{
	t_stack	*curr;

	curr = *tail;
	if (!curr)
		return ;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);

	}
	free(curr);
	*tail = NULL;
	*head = NULL;
}
