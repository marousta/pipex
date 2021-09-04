/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:04:28 by marousta          #+#    #+#             */
/*   Updated: 2021/09/04 19:31:02 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*ft_memmove(void *dest, const void *src, size_t len)
{
	t_i32	i;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < (int)len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
		return (dest);
	}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
		return (dest);
	}
}

t_string	ft_substr(const t_string s, t_u32 start, size_t len)
{
	t_string	str;

	if (!s)
		return (NULL);
	str = ft_calloc(sizeof(char), (len + 1));
	if (!str)
		return (NULL);
	if (start > (t_u32)ft_strlen(s))
		return (str);
	ft_memmove(str, &s[start], len);
	return (str);
}
