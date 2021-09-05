/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:50:37 by marousta          #+#    #+#             */
/*   Updated: 2021/09/05 21:29:01 by marousta         ###   ########lyon.fr   */
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
	if (!str || !DEBUG)
		return ;
	write(1, head, ft_strlen(head));
	write(1, str, ft_strlen(str));
	write(1, END"\n", 6);
}

// t_i8	check_executable(t_p *pipex)
// {

// 	exec1 = get_executable(pipex->path, pipex->cmd[1].exec);
// 	if (!exec1)
// 	{
// 		printstr(BRED"\nExecutable not found.\n"END);
// 		return (FALSE);
// 	}
// 	return (TRUE);
// }

t_i32	free_exit(t_p *pipex, t_i32 ret)
{
	t_i32	i;

	i = -1;
	while (pipex->path[++i])
	{
		printstr_debug("["BYEL"FREE"END"] ", pipex->path[i]);
		free(pipex->path[i]);
	}
	free(pipex->path);
	printstr_debug("["BYEL"FREE"END"] ", pipex->cmd[0].exec);
	free(pipex->cmd[0].exec);
	printstr_debug("["BYEL"FREE"END"] ", pipex->cmd[0].args);
	free(pipex->cmd[0].args);
	printstr_debug("["BYEL"FREE"END"] ", pipex->cmd[1].exec);
	free(pipex->cmd[1].exec);
	printstr_debug("["BYEL"FREE"END"] ", pipex->cmd[1].args);
	free(pipex->cmd[1].args);
	if (pipex->file_fd[0])
		close(pipex->file_fd[0]);
	if (pipex->file_fd[1])
		close(pipex->file_fd[1]);
	return (ret);
}

int	main(int ac, char **av, char **env)
{
	t_p	pipex;

	if (ac != 5)
	{
		if (ac < 5)
			printstr("Missing arguments\nPlease run with ./pipex [file1] [cmd1] [cmd2] [file2]\n");
		if (ac > 5)
			printstr("Too many arguments\nPlease run with ./pipex [file1] [cmd1] [cmd2] [file2]\n");
		return (EXIT_FAILURE);
	}

	ft_memset(&pipex, 0, sizeof(t_p));
	pipex.env = env;

	if (!path_set(&pipex))
	{
		return (free_exit(&pipex, EXIT_FAILURE));
	}

	if (!parse_cmd(&pipex, av[2]))
	{
		return (free_exit(&pipex, EXIT_FAILURE));
	}
	if (!parse_cmd(&pipex, av[3]))
	{
		return (free_exit(&pipex, EXIT_FAILURE));
	}

	if (!executable_set(&pipex, &pipex.cmd[0].exec))
	{
		return (free_exit(&pipex, EXIT_FAILURE));
	}
	if (!executable_set(&pipex, &pipex.cmd[1].exec))
	{
		return (free_exit(&pipex, EXIT_FAILURE));
	}

	if (!infile_set(&pipex, av[1]))
	{
		return (free_exit(&pipex, EXIT_FAILURE));
	}

	if (!outfile_set(&pipex, av[4]))
	{
		return (free_exit(&pipex, EXIT_FAILURE));
	}

	printstr_debug("["BGRN"OK"END"]", "");

	return (free_exit(&pipex, EXIT_SUCCESS));
}
