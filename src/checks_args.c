/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:57:16 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/07 14:51:41 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

int	valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	duplicates(t_stack *a, long num)
{
	while (a)
	{
		if (a->num == num)
			return (1);
		a = a->next;
	}
	return (0);
}

int	check_args(int ac, char **av, t_stack **a)
{
	int		i;
	long	num;

	if (ac == 2)
	{
		return (parse_array(av[1], a));
	}
	i = 1;
	while (i < ac)
	{
		if (!valid_num(av[i]))
		{
			ft_printf("Error.\n");
			return (1);
		}
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error.\n");
			return (1);
		}
		end_insert(a, num);
		i++;
	}
	return (0);
}
