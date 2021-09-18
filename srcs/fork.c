/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:23:58 by marousta          #+#    #+#             */
/*   Updated: 2021/09/18 20:01:51 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_i8	fork_dup2(t_p *p, t_i32 index)
{
	if (index)
	{
		if (dup2(p->file_fd[1], 1) == ERROR
			|| dup2(p->pipe_fd[0], 0) == ERROR)
		{
			printstr(BRED"dup21 failed.\n"END);
			return (FALSE);
		}
	}
	else
	{
		if (dup2(p->file_fd[0], 0) == ERROR
			|| dup2(p->pipe_fd[1], 1) == ERROR)
		{
			printstr(BRED"dup20 failed.\n"END);
			return (FALSE);
		}
	}
	return (TRUE);
}

static t_i8	fork_check(t_i32 *pid, t_i32 index)
{
	pid[index] = fork();
	if (pid[index] == ERROR)
	{
		if (index)
			printstr(BRED"Fork1 failed.\n"END);
		else
			printstr(BRED"Fork0 failed.\n"END);
		return (FALSE);
	}
	return (TRUE);
}

static t_i8	fork_last(t_p *p, t_i32 *pid)
{
	if (!fork_check(pid, 1))
		return (FALSE);
	if (!pid[1])
	{
		if (!fork_dup2(p, 1))
			return (FALSE);
		close(p->file_fd[0]);
		close(p->file_fd[1]);
		close(p->pipe_fd[0]);
		close(p->pipe_fd[1]);
		execve(p->cmd[1].exec, p->cmd[1].args, p->env);
	}
	else
	{
		close(p->file_fd[0]);
		close(p->file_fd[1]);
		close(p->pipe_fd[0]);
		close(p->pipe_fd[1]);
	}
	return (TRUE);
}

t_i8	fork_first(t_p *p, t_i32 *pid)
{
	if (!fork_check(pid, 0))
		return (FALSE);
	if (!pid[0])
	{
		if (!fork_dup2(p, 0))
			return (FALSE);
		close(p->file_fd[0]);
		close(p->file_fd[1]);
		close(p->pipe_fd[0]);
		close(p->pipe_fd[1]);
		execve(p->cmd[0].exec, p->cmd[0].args, p->env);
	}
	else if (!fork_last(p, pid))
		return (FALSE);
	return (TRUE);
}
