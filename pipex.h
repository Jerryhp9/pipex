/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 01:12:31 by jhor              #+#    #+#             */
/*   Updated: 2025/03/30 01:12:31 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/wait.h>
#include "./libft/libft.h"

typedef struct s_stack{
	int		outfile;
	int		pid2;
	char	**fetchcmd1;
} t_stack;

typedef struct p_list{
	int		infile;
	int		pid1;
	char	**fetchcmd;
} t_list;

typedef struct p_cato{
	int		i;
	char	*execmd;
	char	**cmds;
} t_cato;

// static int	wordcount(char *str, char c);
char		**ft_split(char *s, char c);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoinv(int nbr, ...);
char		*fetchpath(char **envp)
char		**cmd_arg(int argc, char *argv);
char		**cmd_path(char **envp);
int			check_cmd_path(char **concat, int argc, char *argv, char **envp);
void 		freefunc(char **concat);
int			pipex(int argc, char **argv, char **envp);
pid_t		secondchild(int argc, char **argv, char **envp, int fd2, int fd1);
pid_t		firstchild(int argc, char **argv, char **envp, int fd1, int fd0);

#endif