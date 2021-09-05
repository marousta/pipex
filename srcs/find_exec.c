/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:24:22 by marousta          #+#    #+#             */
/*   Updated: 2021/09/05 19:52:52 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_string	executable_get(t_p *pipex, t_string exec_name)
{
	t_string	exec_path;
	t_i32		i;

	i = -1;
	while (pipex->path[++i])
	{
		exec_path = ft_strjoin(pipex->path[i], exec_name);
		if (!exec_path)
			return (NULL);
		if (check_fd(exec_path))
			return (exec_path);
		free(exec_path);
	}
	return (NULL);
}

t_i8	executable_set(t_p *pipex, t_string *cmd_exec)
{
	const t_i8	fd = check_fd(*cmd_exec);
	t_string	exec;

	if (!*cmd_exec)
	{
		printstr(BRED"No executable provided.\n"END);
		return (FALSE);
	}
	if ((*cmd_exec[0] == '/' && fd) || fd)
		return (TRUE);
	exec = executable_get(pipex, *cmd_exec);
	if (!exec)
	{
		printstr(BRED"Executable not found.\n"END);
		return (FALSE);
	}
	free(*cmd_exec);
	*cmd_exec = exec;
	return (TRUE);
}
