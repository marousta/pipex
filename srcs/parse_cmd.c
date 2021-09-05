/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:01:56 by marousta          #+#    #+#             */
/*   Updated: 2021/09/05 19:04:16 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_i8	parse_cmd_loop(t_string cmd, t_i32 i, t_parse_cmd *alt)
{
	if (cmd[i] == 32)
	{
		alt->exec = ft_substr(cmd, 0, i);
		alt->args = ft_substr(cmd, i, ft_strlen(cmd) - i);
		if (!alt->exec || !alt->args)
		{
			printstr(BRED"Error happened when parsing command with args.\n"END);
			return (ERROR);
		}
		return (TRUE);
	}
	else if (!cmd[i + 1])
	{
		alt->exec = ft_substr(cmd, 0, i + 1);
		if (!alt->exec)
		{
			printstr(BRED"Error happened when parsing command.\n"END);
			return (ERROR);
		}
		return (TRUE);
	}
	return (FALSE);
}

t_i8	parse_cmd(t_p *pipex, t_string cmd)
{
	t_i8		ret;
	t_i32		i;
	t_parse_cmd	*alt;

	i = -1;
	if (!pipex->cmd[0].exec)
		alt = &pipex->cmd[0];
	else if (!pipex->cmd[1].exec)
		alt = &pipex->cmd[1];
	else
	{
		printstr(BRED"All exectuables are already set. This is bad.\n"END);
		return (FALSE);
	}
	while (cmd && cmd[++i])
	{
		ret = parse_cmd_loop(cmd, i, alt);
		if (ret == TRUE)
			return (TRUE);
		else if (ret == ERROR)
			return (FALSE);
	}
	printstr(BRED"Unable to find executable in command.\n"END);
	return (FALSE);
}
