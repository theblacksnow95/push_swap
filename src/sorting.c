/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:02:28 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/24 14:49:48 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	int	max;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	max = find_biggest(*stack);
	if ((*stack)->index == max)
		ra(stack, false);
	else if ((*stack)->next->index == max)
		rra(stack, false);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack, false);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b, false);
		else
			ra(a, false);
	}
	sort_three(a);
	pa(a, b, false);
	pa(a, b, false);
	if ((*a)->index > (*a)->next->index)
		sa(a, false);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_idx;
	int	max_bits;
	int	i;
	int	size;

	if (!a || !*a || !b)
		return ;
	max_idx = find_biggest(*a);
	max_bits = find_bits(max_idx);
	i = 0;
	while (i < max_bits)
	{
		size = stack_len(*a);
		while (size--)
		{
			if (((*a)->index >> i) & 1)
				ra(a, false);
			else
				pb(a, b, false);
		}
		while (*b)
			pa(a, b, false);
		i++;
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a || !b)
		return ;
	size = stack_len(*a);
	if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
