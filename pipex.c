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

// void stdinfile(int infile)
// {
// 	int infile = open("file1", O_WRONLY | O_CREAT, 0777);
// 	dup2(infile, STDIN_FILENO);
// 	close(infile);
// }

char *cmd1(const char *argc, char const *argv[], char *envp)
{
	char *PATH;
	char *path;
	
	PATH = "PATH=";
	while (*envp)
	{
		if (*envp && ft_strncmp(*envp, PATH, 6))
			path = ft_strdup(*envp);
		envp++;
	}
}

// int main(argc, char *argv[], char *envp[])