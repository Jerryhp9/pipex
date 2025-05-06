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
	char	*path;
	
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
	int	i;
	
	i = 0;
	if (!concat)
		return;
	while(concat[i])
	{
		free(concat[i]);
		i++;
	}
	free(concat);
}

int	check_cmd_path(char **concat, int argc, char *argv, char **envp)
{
	t_cato	*cmdpath;
	
	cmdpath = &(t_cato){0};
	cmdpath->i = 0;
	cmdpath->cmds = cmd_arg(argc, argv);
	if (!cmdpath->cmds || !*cmdpath->cmds)
		{
			freefunc(cmdpath->cmds);
			return (1);
		}
	if (*cmdpath->cmds && **cmdpath->cmds != '\0' && access(cmdpath->cmds[0], F_OK | X_OK) == 0)
		execve(cmdpath->cmds[0], cmdpath->cmds, envp);
	while (concat[cmdpath->i])
	{
		if (cmdpath->cmds[0] && concat[cmdpath->i])
		{
			cmdpath->execmd = ft_strjoinv(3, concat[cmdpath->i], "/", cmdpath->cmds[0]);
			if (cmdpath->execmd != NULL && access(cmdpath->execmd, F_OK | X_OK) == 0)
				execve(cmdpath->execmd, cmdpath->cmds, envp);
			free(cmdpath->execmd);
		}
		cmdpath->i++;
	}
	(freefunc(concat), perror(cmdpath->cmds[0]));
	(freefunc(cmdpath->cmds), exit(127));
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
