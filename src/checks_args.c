/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:57:16 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/11 16:46:01 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

int	error_syntax(char *str)
{
	if (!(*str == '-' \
				|| *str == '+' \
				|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '-' || *str == '+') \
		&& !(str[1] >= '0' && str[1] <= '9'))
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

