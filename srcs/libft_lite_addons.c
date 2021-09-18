/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lite_addons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:37:02 by marousta          #+#    #+#             */
/*   Updated: 2021/09/18 19:49:23 by marousta         ###   ########lyon.fr   */
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

t_string	ft_strjoin(const t_string s1, const t_string s2)
{
	t_i32		i;
	t_string	str;
	t_i32		str_len;
	t_i32		s1_len;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	str_len = s1_len + ft_strlen(s2);
	str = ft_calloc(sizeof(char), (str_len + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[s1_len + i] = s2[i];
		i++;
	}
	return (str);
}
