/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:50:37 by marousta          #+#    #+#             */
/*   Updated: 2021/09/18 20:02:28 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_p	pipex;

	if (ac != 5)
	{
		if (ac < 5)
			printstr("Missing arguments\nPlease run with " \
			"./pipex [file1] [cmd1] [cmd2] [file2]\n");
		if (ac > 5)
			printstr("Too many arguments\nPlease run with " \
			"./pipex [file1] [cmd1] [cmd2] [file2]\n");
		return (EXIT_FAILURE);
	}
	ft_memset(&pipex, 0, sizeof(t_p));
	pipex.env = env;
	if (!path_set(&pipex)
		|| !parse_cmd(&pipex, av[2])
		|| !parse_cmd(&pipex, av[3])
		|| !executable_set(&pipex, &pipex.cmd[0].exec)
		|| !executable_set(&pipex, &pipex.cmd[1].exec)
		|| !infile_set(&pipex, av[1])
		|| !outfile_set(&pipex, av[4])
		|| !exec_pipe(&pipex))
		return (free_exit(&pipex, EXIT_FAILURE));
	return (free_exit(&pipex, EXIT_SUCCESS));
}
