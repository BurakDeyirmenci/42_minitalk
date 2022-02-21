/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeyirme <rdeyirme@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:31:25 by rdeyirme          #+#    #+#             */
/*   Updated: 2022/01/03 19:58:04 by rdeyirme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = dst;
	s = (char *)src;
	if (n == 0)
		return (ft_strlen(src));
	while (i < n - 1 && s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	if (i < n)
		dst[i] = '\0';
	return (ft_strlen(src));
}
