/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:50:37 by marousta          #+#    #+#             */
/*   Updated: 2021/09/04 20:37:02 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	printstr(t_string str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

t_i8	check_executable(char **env, t_string cmd_exec0, t_string cmd_exec1)
{
	t_string	path;
	t_string	exec0;
	t_string	exec1;

	path = get_path(env);
	if (!path)
	{
		printstr(BRED"Unable to get PATH for env.\n"END);
		return (FALSE);
	}
	exec0 = get_executable(path, cmd_exec0);
	if (!exec0)
	{
		free(path);
		printstr(cmd_exec0);
		printstr(BRED"\nExecutable not found.\n"END);
		return (FALSE);
	}
	exec1 = get_executable(path, cmd_exec1);
	if (!exec1)
	{
		free(path);
		printstr(cmd_exec1);
		printstr(BRED"\nExecutable not found.\n"END);
		return (FALSE);
	}
	free(path);
	return (TRUE);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;


	if (ac != 5)
	{
		if (ac < 5)
			printstr("Missing arguments\nPlease run with ./pipex [file1] [cmd1] [cmd2] [file2]\n");
		if (ac > 5)
			printstr("Too many arguments\nPlease run with ./pipex [file1] [cmd1] [cmd2] [file2]\n");
		return (EXIT_ERROR);
	}


//
	// if (!check_infile(av[1]))
	// {
		// return (EXIT_ERROR);
	// }
//
	// if (!write_oufile(av[4], "CHOCOLAT\n"))
	// {
		// return (EXIT_ERROR);
	// }
	return (EXIT_SUCCESS);
}
