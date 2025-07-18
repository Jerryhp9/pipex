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

# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int		outfile;
	int		pid2;
	char	**fetchcmd1;
}	t_stack;

typedef struct s_list
{
	int		infile;
	int		pid1;
	char	**fetchcmd;
}	t_list;

typedef struct s_cato
{
	int		i;
	char	*execmd;
	char	**cmds;
}	t_cato;

typedef struct s_status
{
	int	status1;
	int	status2;
}	t_status;

// static int	wordcount(char *str, char c);
char		**ft_split(char *s, char c);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoinv(int nbr, ...);
char		*fetchpath(char **envp);
char		**cmd_arg(int argc, char *argv);
char		**cmd_path(char **envp);
int			check_cmd_path(char **concat, int argc, char *argv, char **envp);
int			check_cmd_paths(char **concat, int argc, char *argv, char **envp);
void		error_printing(char **s);
void		exec_cmd(char **concat, t_cato *cdph, char **envp);
void		freefunc(char **concat);
int			pipex(int argc, char **argv, char **envp);
pid_t		secondchild(int argc, char **argv, char **envp, int *fd);
pid_t		firstchild(int argc, char **argv, char **envp, int *fd);
void		init_status(t_status *status);

#endif