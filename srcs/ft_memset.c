/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:49:42 by marousta          #+#    #+#             */
/*   Updated: 2021/09/04 19:29:55 by marousta         ###   ########lyon.fr   */
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
