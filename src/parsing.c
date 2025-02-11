/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:07:37 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/11 17:38:50 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *tail)
{
	t_stack		*curr;

	curr = tail;
	while (curr->prev != NULL)
	{
		curr = curr->prev;
	}
	while (curr != NULL)
	{
		ft_printf("Node value: | %d |\n", curr->num);
		curr = curr->next;
	}
}

int	parse_array(char **argv, t_stack **a, int check_ac)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, check_ac);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_free(a, argv, check_ac);
		if (duplicates(*a, num))
			error_free(a, argv, check_ac);
		end_insert(a, (int)num);
		i++;
	}
	return (0);
}
