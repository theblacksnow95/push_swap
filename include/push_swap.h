/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:56:54 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/06 12:35:06 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"

typedef struct Node
{
	long int	x;
	struct Node	*next;
}				t_node;

int		parsing_args(char **av, int ac);
void	deallocate(t_node **root);
void	end_insert(t_node **root, int value);
void	start_insert(t_node **root, int value);
long	ft_atol(char *str);

#endif
