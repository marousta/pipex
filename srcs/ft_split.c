/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:04:10 by marousta          #+#    #+#             */
/*   Updated: 2021/09/18 20:02:17 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_i32	ft_tab_size(const t_string s, char c)
{
	t_i32		i;
	t_i32		size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		size++;
	}
	return (size);
}

static t_string	*free_tab(t_string *tab, t_i32 index)
{
	t_i32		i;

	i = 0;
	while (i < index)
		free(tab[i++]);
	free(tab);
	return (0);
}

static t_string	*put_word(const t_string s, char c, t_string *tab, t_i32 i)
{
	t_i32		y;
	t_i32		index;

	index = 0;
	while (s[i])
	{
		y = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			y++;
		}
		if (y > 0)
		{
			tab[index] = ft_substr(s, i - y, y);
			if (!tab[index])
				return (free_tab(tab, index));
		}
		while (s[i] && s[i] == c)
			i++;
		index++;
	}
	return (tab);
}

t_string	*ft_split(const t_string s, char c)
{
	t_string	*tab;
	t_i32		tab_size;
	t_i32		i;

	if (!s || !s[0])
		return (NULL);
	i = 0;
	tab_size = ft_tab_size(s, c);
	tab = ft_calloc(sizeof(t_string), (tab_size + 1));
	if (!tab)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	tab = put_word(&s[i], c, tab, 0);
	return (tab);
}
