/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeyirme <rdeyirme@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:59:42 by rdeyirme          #+#    #+#             */
/*   Updated: 2022/01/07 11:37:11 by rdeyirme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				neg;
	long long int	num;

	neg = 1;
	num = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		num = (num * 10) + (*str - 48) * neg;
		str++;
		if (num > 2147483647)
			return (-1);
		if (num < -2147483648)
			return (0);
	}
	return (num);
}
