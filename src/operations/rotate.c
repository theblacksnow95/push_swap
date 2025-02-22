/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:47:11 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/22 16:34:29 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*old;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	old = *stack;
	last = find_last(*stack);
	last->next = old;
	old->prev = last;
	*stack = old->next;
	(*stack)->prev = NULL;
	old->next = NULL;
}

void	ra(t_stack **a, bool check)
{
	rotate(a);
	if (!check)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool check)
{
	rotate(b);
	if (!check)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool check)
{
	rotate(a);
	rotate(b);
	if (!check)
		write(1, "rr\n", 3);
}
