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

pid_t firstchild(int argc, char **argv, char **envp, int fd1)
{
	int		infile;
	int		pid1;
	char	**fetchcmd;

	pid1 = fork();
	if (pid1 == -1)
	return -1;
	else if (pid1 == 0) //scope of child process
	{
		infile = open(argv[1], O_RDONLY); //cmd reading from infile
		if (infile == -1)
		{
			perror(argv[1]);
			exit(1);
		}
		dup2(infile, 0);
		close(infile);
		dup2(fd1, 1);
		close(fd1);
		fetchcmd = cmd_path(envp);
		check_cmd_path(fetchcmd, argc, argv[2], envp);
	}
	return (pid1);
}

pid_t secondchild(int argc, char **argv, char **envp, int fd2)
{
	int		outfile;
	int		pid2;
	char	**fetchcmd1;
	
	fetchcmd1 = cmd_path(envp);
	pid2 = fork();
	if (pid2 == -1)
		return -1;
	else if (pid2 == 0)
	{
		outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (outfile == -1)
		{
			perror(argv[4]);
			exit(1);
		}
		dup2(outfile, 1);
		close(outfile);
		dup2(fd2, 0);
		close(fd2);
		check_cmd_path(fetchcmd1, argc, argv[3], envp);
		freefunc(fetchcmd1);
	}
	freefunc(fetchcmd1);
	return (pid2);
}

int	pipex(int argc, char **argv, char **envp)
{
	int	pid1;
	int	pid2;
	int	status1;
	int	status2;
	int	fd[2];
	int	pipes;

	pipes = pipe(fd);
	if (pipes == -1) //pass into a variable to check gaurd
		exit(1);

	pid1 = firstchild(argc, argv, envp, fd[1]);
	close(fd[1]);
	
	pid2 = secondchild(argc, argv, envp, fd[0]);
	close(fd[0]);
	waitpid(pid2, &status2, 0);
	waitpid(pid1, &status1, 0);
	// printf("%d\n", status1);
	// printf("%d\n", status2);
	if (WIFEXITED(status2))
		return WEXITSTATUS(status2);
	else
		return (1);
}

int main(int argc, char **argv, char** envp)
{
	int	exit_code;

	if (argc == 1)
	{
		printf("error\n");
		return (1);
	}
	if (argc != 5)
		return (1);
	exit_code = pipex(argc, argv, envp);
	return (exit_code);
}