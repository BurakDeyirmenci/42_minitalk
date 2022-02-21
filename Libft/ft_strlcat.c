/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeyirme <rdeyirme@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:39:47 by rdeyirme          #+#    #+#             */
/*   Updated: 2022/01/06 09:48:47 by rdeyirme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	total;
	size_t	i;

	i = n;
	total = ft_strlen(dst) + ft_strlen(src);
	while (*dst != 0 && n > 0)
	{
		dst++;
		n--;
	}
	if (n == 0)
		return (ft_strlen(src) + i);
	while (*src != 0 && n > 1)
	{
		*dst++ = *src++;
		n--;
	}
	*dst = 0;
	return (total);
}
