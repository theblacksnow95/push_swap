/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:56:48 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/07 15:47:18 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || ac == 2 && !av[1][0])
		return (1);
	else if (ac == 2)
	{
		av = split(av[1], ' ');
	}
	parse_array(av + 1, &a);
	print_stack_as(a);
	deallocate(&a, );
	return (0);
}
