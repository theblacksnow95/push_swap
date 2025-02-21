/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:56:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/21 17:30:01 by emurillo         ###   ########.fr       */
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

typedef struct s_Node
{
	long int		num;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_Node	*target;
	struct s_Node	*next;
	struct s_Node	*prev;
}					t_stack;

int			parse_array(char **argv, t_stack **list, int check_ac);
void		end_insert(t_stack **root, int value);
void		start_insert(t_stack **root, int value);
long		ft_atol(char *str);
int			error_syntax(char *str);
int			duplicates(t_stack *a, long num);
void		error_free(t_stack **a, char **args, int check_ac);
void		free_array(char **argv);
void		free_stack(t_stack **stack);
t_stack		*find_last(t_stack *stack);
int			sorted(t_stack *stack);
void		set_index(t_stack *stack, int stack_len);

void		print_stack(t_stack *curr);
int			stack_len(t_stack *stack);

#endif
