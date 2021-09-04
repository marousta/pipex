/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:38:09 by marousta          #+#    #+#             */
/*   Updated: 2021/09/04 20:25:00 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

typedef char t_i8;
typedef short t_i16;
typedef int t_i32;
typedef long t_i64;
typedef unsigned char t_u8;
typedef unsigned short t_u16;
typedef unsigned int t_u32;
typedef unsigned long t_u64;
typedef float t_f32;
typedef double t_f64;
typedef	char* t_string;

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

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define EXIT_SUCCESS 0
# define EXIT_ERROR 1

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

t_i32	ft_strlen(t_string str);
void	*ft_calloc(t_u64 count, t_u64 size);
void	*ft_memset(void *b, t_i32 c, t_u64 len);

t_string	ft_substr(const t_string s, t_u32 start, size_t len);
t_string	*ft_split(const t_string s, char c);

t_string	ft_strjoin(const t_string s1, const t_string s2);

void	printstr(t_string str);

t_i8	check_infile(t_string filename);
t_i8	write_oufile(t_string filename, t_string text);

t_string	get_path(char **env);
t_string	get_executable(t_string path, t_string exec_name);


#endif
