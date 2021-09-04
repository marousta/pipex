/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:10:54 by marousta          #+#    #+#             */
/*   Updated: 2021/09/04 19:44:24 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_i8	check_infile(t_string filename)
{
	const t_i32 fd = open(filename, O_RDONLY);

	if (fd == ERROR)
	{
		printstr(BRED"Unable to open input file.\n");
		printstr("File doesn't exist or it has insufficient permissions.\n"END);
		return (FALSE);
	}
	if (read(fd, NULL, 0) == ERROR)
	{
		close(fd);
		printstr(BRED"Input file is a directory.\n"END);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

t_i8	write_oufile(t_string filename, t_string text)
{
	const t_i32 fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 644);

	if (fd == ERROR)
	{
		printstr(BRED"Unable to open output file.\n");
		printstr("A folder with the same name may already exist..\n"END);
		return (FALSE);
	}
	if (write(fd, text, ft_strlen(text)) == ERROR)
	{
		close(fd);
		printstr(BRED"A write error occured when writting output file.\n"END);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}