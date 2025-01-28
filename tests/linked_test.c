/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linke_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:44:13 by emurillo          #+#    #+#             */
/*   Updated: 2025/01/27 14:57:15 by emurillo         ###   ########.fr       */
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
	t_Node	first;

	if (ac == 3)
	{
		first.num = atoi(av[1]);
		first.next = malloc(sizeof(t_Node));
		first.next->num = atoi(av[2]);
		first.next->next = NULL;

		printf("first: %d\n", first.num);
		printf("Second: %d\n", first.next->num);
	}
}
