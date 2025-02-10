/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:56:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/10 18:13:32 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../lib/libft/libft.h"

typedef struct Node
{
	long int	num;
	struct Node	*next;
	struct Node	*prev;
}				t_stack;

int		check_args(int ac, char **av, t_stack **a);
int		parse_array(char **argv, t_stack **list);
void	deallocate(t_stack **tail, t_stack **head);
void	end_insert(t_stack **root, int value);
void	start_insert(t_stack **root, int value);
long	ft_atol(char *str);
int		error_syntax(char *str);
int		duplicates(t_stack *a, long num);
void	error_free(t_stack **a);

void	print_stack_as(t_stack *curr);

#endif
