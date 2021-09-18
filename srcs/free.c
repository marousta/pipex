/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:52:16 by marousta          #+#    #+#             */
/*   Updated: 2021/09/18 19:58:21 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_dstr(t_string *dstr)
{
	t_i32	i;

	i = -1;
	while (dstr[++i])
	{
		printstr_debug("["BYEL"FREE"END"] ", dstr[i]);
		free(dstr[i]);
	}
}

t_i32	free_exit(t_p *pipex, t_i32 ret)
{
	free_dstr(pipex->path);
	free_dstr(pipex->cmd[0].args);
	free_dstr(pipex->cmd[1].args);
	printstr_debug("["BYEL"FREE"END"] ", pipex->cmd[0].exec);
	free(pipex->cmd[0].exec);
	printstr_debug("["BYEL"FREE"END"] ", pipex->cmd[1].exec);
	free(pipex->cmd[1].exec);
	if (pipex->file_fd[0])
		close(pipex->file_fd[0]);
	if (pipex->file_fd[1])
		close(pipex->file_fd[1]);
	return (ret);
}
