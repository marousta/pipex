/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:22:41 by marousta          #+#    #+#             */
/*   Updated: 2021/09/18 19:23:37 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_i8	exec_waitpid(t_i32 *pid)
{
	t_i32	status;

	waitpid(pid[0], &status, 0);
	if (status)
	{
		printstr(BRED"execve0: command failed.\n"END);
		return (FALSE);
	}
	waitpid(pid[1], &status, 0);
	if (status)
	{
		printstr(BRED"execve1: command failed.\n"END);
		return (FALSE);
	}
	return (TRUE);
}

t_i8	exec_pipe(t_p *p)
{
	t_i32	pid[2];

	pipe(p->pipe_fd);
	if (!fork_first(p, pid))
		return (FALSE);
	return (exec_waitpid(pid));
}
