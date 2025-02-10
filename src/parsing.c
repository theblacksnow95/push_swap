/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:07:37 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/10 18:14:57 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack_as(t_stack *tail)
{
	t_stack		*curr;

	curr = tail;
	while (curr != NULL)
	{
		ft_printf("Node value: | %d |\n", curr->num);
		curr = curr->next;
	}
}

int	parse_array(char **argv, t_stack **a)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a);
		num = atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_free(a);
		if (duplicates(*a, num))
			error_free(a);
		end_insert(a, (int)num);
		i++;
	}
	return (0);
}
