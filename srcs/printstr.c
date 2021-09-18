/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:56:27 by marousta          #+#    #+#             */
/*   Updated: 2021/09/18 19:56:47 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	printstr(t_string str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

void	printstr_debug(t_string head, t_string str)
{
	if (!DEBUG)
		return ;
	if (str)
	{
		write(1, head, ft_strlen(head));
		write(1, str, ft_strlen(str));
	}
	else
	{
		write(1, head, ft_strlen(head));
		write(1, "(null)", 7);
	}
	write(1, END"\n", 6);
}
