/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:20:49 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/12 17:15:28 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack		*temp;
	t_stack		*current;

	if (!stack)
		return ;
	if ((*stack)->prev != NULL)
	{
		while ((*stack)->prev)
			*stack = (*stack)->prev;
	}
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}


void	free_array(char **argv)
{
	int		i;

	i = 0;
	if (!argv || !*argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	error_free(t_stack **a, char **args, int check_c)
{
	if (a && *a)
		free_stack(a);
	if (args && check_c == 1)
		free_array(args);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
