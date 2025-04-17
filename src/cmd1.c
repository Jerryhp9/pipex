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

char *fetchpath(char *envp)
{
	char *path;
	
	while (*envp)
	{
		if (*envp && ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path = *envp;
			return (path);
		}	
		envp++;
	}
}

char *cmd_path(char *path)
{
	char *concat;
	char *path = fetchpath("PATH=");

	concat = ft_strjoinv();
	if (access(path, F_OK | X_OK) == 0)
	while (path)
	{
			
	}
}

int main(int argc, char *argv[], char *envp[])
{
	printf("%s", fetchpath(envp));
}

