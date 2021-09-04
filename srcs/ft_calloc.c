/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:48:51 by marousta          #+#    #+#             */
/*   Updated: 2021/09/04 19:29:11 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(t_u64 count, t_u64 size)
{
	void	*memory;

	memory = malloc(count * size);
	if (!memory)
		return (0);
	return (ft_memset(memory, 0, count * size));
}
