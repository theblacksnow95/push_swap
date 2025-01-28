/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:28:05 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/28 15:14:30 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int			num;
	struct Node	*next;
}	t_Node;

int	main(int ac, char **av)
{
	t_Node	root;
	t_Node	*curr;

	if (ac == 4)
	{
		root.num = atoi(av[1]);
		root.next = malloc(sizeof(root));
		root.next->num = atoi(av[2]);
		root.next->next = malloc(sizeof(root));
		root.next->next->num = atoi(av[3]);
		curr = &root;
		while (curr != NULL)
		{
			printf("Node value: %d |\n", curr->num);
			curr = curr->next;
		}
	}
	free(root.next);
	return (0);
}
