/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeyirme <rdeyirme@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:33:50 by rdeyirme          #+#    #+#             */
/*   Updated: 2022/01/20 10:58:48 by rdeyirme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	sj = (char *)malloc (ft_strlen(s1) + ft_strlen(s2));
	if (!sj)
		return (0);
	i = 0;
	while (*s1 != 0)
	{
		sj[i] = *s1++;
		i++;
	}
	while (*s2 != 0)
	{
		sj[i] = *s2++;
		i++;
	}
	sj[i] = '\0';
	return (sj);
}
