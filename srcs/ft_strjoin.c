/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:04:15 by marousta          #+#    #+#             */
/*   Updated: 2021/09/04 19:38:24 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
