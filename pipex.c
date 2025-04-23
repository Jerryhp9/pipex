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

void stdinfile(int file)
{
	int infile = open("infile", O_WRONLY | O_CREAT, 0777);
	dup2(infile, 0);
	close(infile);
}
pid_t firstchild(int pid1)
{
	fork();
	if (pid1 == -1)
		return 1;
	else if (pid1 == 0)
		return (pid1);
}
pid_t secondchild(int pid2)
{
	fork();
	if (pid2 == -1)
		return 1;
	else if (pid2 == 0)
		return (pid2);
}
void pipex(int pid1, int pid2, int fd)
{
	int fd[2];
	if (pipe(fd) == -1)
		return 1;
	if (firstchild(pid1) == 0)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
		
		check_cmd_path(dirs, argc, argv, envp);
	}
}
