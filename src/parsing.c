/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:07:37 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/06 16:13:19 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse_array(char *arg, t_node **list)
{
	long	num;

	num = 0;
	while (*arg)
	{
		while (*arg == ' ')
			arg++;
		if (*arg == '\0' || !(*arg >= '0' && *arg <= '9'))
			break ;
		num = ft_atol(arg);
		end_insert(list, num);
		while (*arg && *arg != ' ')
			arg++;
	}
}

void	print_nodes(t_node *curr)
{
	while (curr != NULL)
	{
		ft_printf("Node value: | %d |\n", curr->x);
		curr = curr->next;
	}
}

int	max_check(long num, t_node *list)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_printf("Error.\n");
		deallocate(&list);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	parsing_args(char **av, int ac)
{
	t_node	*list ;
	t_node	*curr;
	int		i;
	long	num;
	char	*arg;

	list = NULL;
	if (ac > 2)
	{
		i = 1;
		while (i < ac)
		{
			num = ft_atol(av[i]);
			max_check(num, list);
			end_insert(&list, ft_atol(av[i]));
			i++;
		}
	}
	else if (ac == 2)
	{
		arg = av[1];
		parse_array(arg, &list);
	}
	curr = list;
	print_nodes(curr);
	deallocate(&list);
	return (0);
}


