/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:56:48 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/24 14:53:52 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		**args;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		parse_array(args, &a, 1);
		free_array(args);
	}
	else
		parse_array(av + 1, &a, 0);
	if (!sorted(a))
	{
		set_index(a, stack_len(a));
		sort_stack(&a, &b);
		/* print_stack(a); */
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
