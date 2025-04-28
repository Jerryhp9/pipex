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
		infile = open("infile", O_RDONLY | O_CREAT, 0777); //cmd reading from infile
		if (infile == -1)
			printf("infile error\n");
		dup2(infile, 0);
		close(infile);
		dup2(fd1, 1);
		close(fd1);
		fetchcmd = cmd_path(envp);
		check_cmd_path(fetchcmd, argc, argv[2], envp);
		exit(1);
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
		outfile = open("outfile", O_WRONLY | O_CREAT, 0777);
		dup2(outfile, 1);
		close(outfile);
		dup2(fd2, 0);
		close(fd2);
		check_cmd_path(fetchcmd1, argc, argv[3], envp);
		exit(1);
	}
	return (pid2);
}

void pipex(int argc, char **argv, char **envp)
{
	int	pid1;
	int	pid2;
	int	fd[2];
	int	pipes;

	pipes = pipe(fd);
	if (pipes == -1)
		exit(1);

	pid1 = firstchild(argc, argv, envp, fd[1]);
	close(fd[1]);
	
	pid2 = secondchild(argc, argv, envp, fd[0]);
	close(fd[0]);
	waitpid(pid2, NULL, 0);
	waitpid(pid1, NULL, 0);

}

int main(int argc, char **argv, char** envp)
{
	if (argc == 1)
	{
		printf("error\n");
		return (1);
	}
	pipex(argc, argv, envp);
	return (0);
}