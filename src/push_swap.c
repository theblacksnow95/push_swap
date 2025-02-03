/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:56:48 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/03 18:02:22 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
		if (j == 1 && (av[i][0] == '-' || av[i][0] == '+'))
			return (1);
		i++;
	}
	return (0);
}


int	main(int ac, char **av)
{
	if (ac >= 2 && check_args(ac, av))
	{
		parsing_args(av, ac);
	}
	return (0);
}
