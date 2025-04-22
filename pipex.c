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
	dup2(infile, STDIN_FILENO);
	close(infile);
}


int main()
{
	pid_t pid = fork();

	if (pid < 0)
	{
		printf ("Error message: %d", errno);
		perror("Error:" );
		return 1;
	} 
	else if (pid == 0)
	{
		printf("This is the child: %d\n", getpid());
	} else 
	{
		printf("This is the child: %d\n This is the parent: %d\n", pid, getpid());
	}
	return 0;
}