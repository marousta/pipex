/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:50:04 by marousta          #+#    #+#             */
/*   Updated: 2021/09/05 18:06:10 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_string	path_get(char **env)
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

static t_string	*path_split(t_string path)
{
	t_i32		i;
	t_string	tmp;
	t_string	*split;

	split = ft_split(path, ':');
	if (!split)
		return (NULL);
	i = -1;
	while (split[++i])
	{
		if (split[i][ft_strlen(split[i]) - 1] != '/')
		{
			tmp = ft_strjoin(split[i], "/");
			if (!tmp)
				return (NULL);
			free(split[i]);
			split[i] = tmp;
		}
	}
	return (split);
}

t_i8	path_set(t_p *pipex)
{
	t_string	path;

	path = path_get(pipex->env);
	if (!path)
	{
		printstr(BRED"Unable to get PATH from env.\n"END);
		return (FALSE);
	}
	pipex->path = path_split(path);
	free(path);
	if (!pipex->path)
	{
		printstr(BRED"Unable to split PATH.\n"END);
		return (FALSE);
	}
	return (TRUE);
}
