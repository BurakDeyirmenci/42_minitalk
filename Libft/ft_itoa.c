/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeyirme <rdeyirme@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:27:18 by rdeyirme          #+#    #+#             */
/*   Updated: 2022/01/09 15:34:23 by rdeyirme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		size;
	long int	num;

	num = n;
	size = get_size(n);
	if (n < 0)
	{
		num *= -1;
		size++;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	*(str + size) = 0;
	while (size-- > 0)
	{
		*(str + size) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
