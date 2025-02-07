/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:07:37 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/07 15:40:00 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack_as(t_stack *curr)
{
	while (curr != NULL)
	{
		ft_printf("Node value: | %d |\n", curr->num);
		curr = curr->next;
	}
}

int	parse_array(char *argv, t_stack **a)
{
	long	num;

	num = 0;
	while (*argv)
	{
		while (*argv == ' ')
			argv++;
		if (*argv == '\0' || !(*argv >= '0' && *argv <= '9'))
			break ;
		num = ft_atol(argv);
		end_insert(a, num);
		while (*argv && *argv != ' ')
			argv++;
	}
	return (0);
}
