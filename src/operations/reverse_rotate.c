/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:25:35 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/22 16:47:56 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*curr;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	curr = *stack;
	last = find_last(curr);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = curr;
	curr->prev = last;
	*stack = last;
}

void	rra(t_stack **a, bool check)
{
	reverse_rotate(a);
	if (!check)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool check)
{
	reverse_rotate(b);
	if (!check)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool check)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!check)
		write(1, "rrr\n", 4);
}
