/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:56:48 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/06 16:16:23 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	num_check(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '-' || av[i] == '+')
			i++;
		while (av[i])
		{
			if (!(av[i] <= '0' && av[i] >= '9'))
			{
				ft_printf("Error.\n");
				return (1);
			}
			i++;
		}
	}
	if (i == 1 && (av[i] == '-' || av[i] == '+'))
		return (1);
	return (0);
}


int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			num_check(av[1]);
			i++;
		}
	}
	i = 1;
	while (i < ac)
	{
		num_check(av[i]);
		/* j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		if (j == 1 && (av[i][0] == '-' || av[i][0] == '+'))
			return (1); */
		i++;
	}
	return (0);
}


int	main(int ac, char **av)
{
	if (ac >= 2 && check_args(ac, av) == 0)
	{
		parsing_args(av, ac);
	}
	return (0);
}
