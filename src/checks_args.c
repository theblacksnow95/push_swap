/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:57:16 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/21 17:32:45 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

void	set_index(t_stack *stack, int stack_len)
{
	t_stack	*max;
	t_stack	*temp;

	while (stack_len-- > 0)
	{
		max = NULL;
		temp = stack;
		while (temp)
		{
			if (!temp->index && (max == NULL || temp->num > max->num))
				max = temp;
			temp = temp->next;
		}
		if (max)
			max->index = stack_len;
	}
}

int	error_syntax(char *str)
{
	if (!(*str == '-' \
				|| *str == '+' \
				|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '-' || *str == '+') \
		&& !(ft_isdigit(str[1])))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	duplicates(t_stack *a, long num)
{
	if (!a)
		return (0);
	if (a->prev)
	{
		while (a->prev != NULL)
			a = a->prev;
	}
	while (a)
	{
		if (a->num == num)
			return (1);
		a = a->next;
	}
	return (0);
}

