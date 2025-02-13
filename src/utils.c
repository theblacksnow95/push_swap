/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:13:40 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/13 15:40:55 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_len(t_stack *stack)
{
	int	count;
	t_stack	*curr;

	count = 0;
	curr = stack;
	if (!stack)
		return (0);
	while (curr)
	{
		curr = curr->next;
		count++;
	}
	return (count);
}

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

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}


void	end_insert(t_stack **head, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	if (!head)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->num = value;
	new_node->next = NULL;
	new_node->cheapest = 0;
	if (!*head)
	{
		new_node->prev = *head;
		*head = new_node;
	}
	else
	{
		last = find_last(*head);
		last->next = new_node;
		new_node->prev = last;
	}
}

int	sorted(t_stack *stack)
{
	t_stack *curr;

	curr = stack;
	if (!stack)
		return (0);
	while (curr->next)
	{
		if (curr->num > curr->next->num)
			return (0);
		curr = curr->next;
	}
	return (1);
}
