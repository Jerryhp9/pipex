/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetchpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:38:55 by jhor              #+#    #+#             */
/*   Updated: 2025/04/17 14:38:55 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h" 

char *fetchpath(char **envp)
{
	char *path;
	
	while (*envp)
	{
		if (*envp && ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path = *envp;
		}
		envp++;
	}
	return (path);
}

char **cmd_path(char *paths)
{
	char **concat;
	char **envp;

	paths = fetchpath(envp);
	concat = ft_split(paths, ':');
	return(concat);
}

int main(int argc, char *argv[], char *envp[])
{
	char *cmd = "ls";
	

	printf("%s", cmd_path(cmd));
}

