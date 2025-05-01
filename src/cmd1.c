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

char	*fetchpath(char **envp)
{
	char *path;
	
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path = (*envp + 5);
		}
		envp++;
	}
	return (path);
}

char	**cmd_path(char **envp)
{
	char	**concat;
	char	*paths;
	
	paths = fetchpath(envp);
	concat = ft_split(paths, ':');
	if (!concat)
		return NULL;
	return(concat);
}
void freefunc(char **concat)
{
	int i;

	i = 0;
	while(concat[i])
	{
		free(concat[i]);
		i++;
	}
	free(concat);
}

int	check_cmd_path(char **concat, int argc, char *argv, char **envp)
{
	int		i;
	char	*execmd;
	char	**cmds;

	i = 0;
	cmds = cmd_arg(argc, argv);
	if (access(cmds[0], F_OK | X_OK) == 0)
		execve(cmds[0], cmds, envp);
	while (concat[i])
	{
		execmd = ft_strjoinv(3, concat[i], "/", cmds[0]);
		if (access(execmd, F_OK | X_OK) == 0)
			execve(execmd, cmds, envp);
		free(execmd);
		i++;
	}
	freefunc(concat);
		perror(argv);
		exit(127);
}


// int main(int argc, char *argv[], char *envp[])
// {
// 	char **dirs;
// 	int i;

// 	i = 0;
// 	dirs = cmd_path(envp);
// 	if(!dirs)
// 	{
// 		printf("%d", errno);
// 		perror("Path not found");
// 	}
// 	check_cmd_path(dirs, argc, argv, envp);
// }
