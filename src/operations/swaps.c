/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:46:34 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/22 13:43:45 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*second;

	if (!*head || !(*head)->next)
		return ;
	second = (*head)->next;
	(*head)->next = second->next;
	if (second->next)
		second->next->prev = *head;
	second->prev = NULL;
	(*head)->prev = second;
	*head = second;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
