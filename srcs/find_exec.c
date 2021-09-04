/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:24:22 by marousta          #+#    #+#             */
/*   Updated: 2021/09/04 20:24:30 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_string	get_path(char **env)
{
	t_i32		i;
	t_string	path;

	i = -1;
	while (env[++i])
	{
		if (!env[i][0] || !env[i][1] || !env[i][2] || !env[i][3] || !env[i][4])
			continue ;
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=')
		{
			path = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
			if (!path)
				return (NULL);
			return (path);
		}
	}
	return (NULL);
}

t_string	get_executable(t_string path, t_string exec_name)
{
	t_string	*bin_path;
	t_string	exec_path;
	t_i32		fd;
	t_i32		i;

	bin_path = ft_split(path, ':');
	if (!bin_path)
		return (NULL);
	i = -1;
	while (bin_path[++i])
	{
		exec_path = ft_strjoin(bin_path[i], exec_name);
		if (!exec_path)
		{
			free(bin_path);
			return (NULL);
		}
		fd = open(exec_path, O_RDONLY);
		if (fd != ERROR)
		{
			close(fd);
			return (exec_path);
		}
		free(exec_path);
		close(fd);
	}
	return (NULL);
}
