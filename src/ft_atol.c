/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:17:03 by emurillo          #+#    #+#             */
/*   Updated: 2025/02/06 15:42:30 by emurillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(char *str)
{
	long long int	num;
	int			sign;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||*str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if(*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (num > (LONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}
