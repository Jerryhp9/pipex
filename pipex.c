/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:19:36 by jhor              #+#    #+#             */
/*   Updated: 2025/04/01 16:19:36 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

pid_t	firstchild(int argc, char **argv, char **envp, int *fd)
{
	t_list	*child1;

	child1 = &(t_list){0};
	child1->pid1 = fork();
	if (child1->pid1 == -1)
		return (-1);
	else if (child1->pid1 == 0)
	{
		child1->fetchcmd = cmd_path(envp);
		child1->infile = open(argv[1], O_RDONLY);
		if (child1->infile == -1)
		{
			perror(argv[1]);
			freefunc(child1->fetchcmd);
			exit(1);
		}
		dup2(child1->infile, 0);
		close(child1->infile);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		check_cmd_path(child1->fetchcmd, argc, argv[2], envp);
		freefunc(child1->fetchcmd);
	}
	return (child1->pid1);
}

pid_t	secondchild(int argc, char **argv, char **envp, int *fd)
{
	t_stack	*child2;

	child2 = &(t_stack){0};
	child2->pid2 = fork();
	if (child2->pid2 == -1)
		return (-1);
	else if (child2->pid2 == 0)
	{
		child2->fetchcmd1 = cmd_path(envp);
		child2->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (child2->outfile == -1)
		{
			perror(argv[4]);
			freefunc(child2->fetchcmd1);
			exit(1);
		}
		dup2(child2->outfile, 1);
		close(child2->outfile);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		check_cmd_paths(child2->fetchcmd1, argc, argv[3], envp);
		freefunc(child2->fetchcmd1);
	}
	return (child2->pid2);
}

int	pipex(int argc, char **argv, char **envp)
{
	int			pid1;
	int			pid2;
	t_status	status;
	int			fds[2];

	init_status(&status);
	if (pipe(fds) == -1)
		exit(1);
	pid1 = firstchild(argc, argv, envp, fds);
	close(fds[1]);
	pid2 = secondchild(argc, argv, envp, fds);
	close(fds[0]);
	waitpid(pid2, &status.status2, 0);
	waitpid(pid1, &status.status1, 0);
	if (WIFEXITED(status.status1) && WEXITSTATUS(status.status1) == 127)
		return (127);
	if (WIFEXITED(status.status2) && WEXITSTATUS(status.status2) == 127)
		return (127);
	if (WIFEXITED(status.status2))
		return (WEXITSTATUS(status.status2));
	else if (WIFEXITED(status.status1))
		return (WEXITSTATUS(status.status1));
	else
		return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int	exit_code;

	if (argc == 1)
	{
		ft_printf("error\n");
		return (1);
	}
	if (argc != 5)
		return (1);
	if (argv[2][0] == '\0')
		exit(0);
	exit_code = pipex(argc, argv, envp);
	return (exit_code);
}
