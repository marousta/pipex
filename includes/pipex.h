/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:38:09 by marousta          #+#    #+#             */
/*   Updated: 2021/09/18 20:11:40 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef char			t_i8;
typedef short			t_i16;
typedef int				t_i32;
typedef long			t_i64;
typedef unsigned char	t_u8;
typedef unsigned short	t_u16;
typedef unsigned int	t_u32;
typedef unsigned long	t_u64;
typedef float			t_f32;
typedef double			t_f64;
typedef char*			t_string;

# define BBLK	"\e[1;30m"
# define BRED	"\e[1;31m"
# define BGRN	"\e[1;32m"
# define BYEL	"\e[1;33m"
# define BBLU	"\e[1;34m"
# define BMAG	"\e[1;35m"
# define BCYN	"\e[1;36m"
# define BWHT	"\e[1;37m"
# define END	"\e[0m"
# define ERASE	"\033[2K"

# define DEBUG	0

# define TRUE	1
# define FALSE	0
# define ERROR	-1

typedef struct s_parse_cmd {
	t_string	exec;
	t_string	*args;
}	t_parse_cmd;

typedef struct s_p {
	t_i32		file_fd[2];
	t_i32		pipe_fd[2];
	t_string	*path;
	t_parse_cmd	cmd[2];
	t_string	*env;
}	t_p;

/*
**  ------------------------------- libft_lite.c -------------------------------
*/
t_i32		ft_strlen(t_string str);
void		*ft_calloc(t_u64 count, t_u64 size);
void		*ft_memset(void *b, t_i32 c, t_u64 len);
/*
**  ---------------------------- libft_lite_addons.c ---------------------------
*/
t_string	ft_substr(const t_string s, t_u32 start, size_t len);
t_string	*ft_split(const t_string s, char c);
t_string	ft_strjoin(const t_string s1, const t_string s2);
/*
**  ---------------------------------- file.c ----------------------------------
*/
t_i8		check_fd(t_string file);
t_i8		infile_set(t_p *pipex, t_string filename);
t_i8		outfile_set(t_p *pipex, t_string filename);
/*
**  ---------------------------------- path.c ----------------------------------
*/
t_i8		path_set(t_p *pipex);
/*
**  -------------------------------- parse_cmd.c -------------------------------
*/
t_i8		parse_cmd(t_p *pipex, t_string cmd);
/*
**  -------------------------------- find_exec.c -------------------------------
*/
t_string	executable_get(t_p *pipex, t_string exec_name);
t_i8		executable_set(t_p *pipex, t_string *exec_name);
/*
**  ---------------------------------- exec.c ----------------------------------
*/
t_i8		fork_first(t_p *p, t_i32 *pid);
t_i8		exec_pipe(t_p *p);
/*
**  ---------------------------------- free.c ----------------------------------
*/
t_i32		free_exit(t_p *pipex, t_i32 ret);
/*
**  -------------------------------- printstr.c --------------------------------
*/
void		printstr(t_string str);
void		printstr_debug(t_string head, t_string str);

#endif
