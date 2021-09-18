/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc_lite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:27:36 by marousta          #+#    #+#             */
/*   Updated: 2021/09/18 19:29:40 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memset(void *b, t_i32 c, t_u64 len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = b;
	if (!b)
		return (NULL);
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

void	*ft_calloc(t_u64 count, t_u64 size)
{
	void	*memory;

	memory = malloc(count * size);
	if (!memory)
		return (0);
	return (ft_memset(memory, 0, count * size));
}

t_i32	ft_strlen(t_string str)
{
	t_i32	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}
