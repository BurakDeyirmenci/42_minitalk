/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeyirme <rdeyirme@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:01:12 by rdeyirme          #+#    #+#             */
/*   Updated: 2022/01/09 15:44:24 by rdeyirme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1 || !set)
		return (0);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1) - 1;
	while (len >= i && ft_strchr(set, s1[len]))
		len--;
	if (len == i + 1)
		return (ft_strdup(""));
	return (ft_substr(s1, i, len - i + 1));
}
