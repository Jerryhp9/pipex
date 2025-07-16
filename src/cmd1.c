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
		return (NULL);
	return (concat);
}

void	error_printing(char **s)
{
	char	*error;
	char	*message;
	char	*string;
	char	*tmp;

	message = NULL;
	string = ft_strdup("");
	while (*s != NULL)
	{
		tmp = ft_strjoin(string, *s);
		free(string);
		string = tmp;
		tmp = ft_strjoin(string, " ");
		free(string);
		string = tmp;
		s++;
	}
	if (string[ft_strlen(string) - 1] == ' ')
		string[ft_strlen(string) - 1] = '\0';
	error = ft_strdup(": command not found\n");
	message = ft_strjoin(string, error);
	free(string);
	free(error);
	ft_putstr_fd(message, 2);
	free(message);
}

int	check_cmd_path(char **concat, int argc, char *argv, char **envp)
{
	t_cato	*cdph;

	cdph = &(t_cato){0};
	cdph->i = 0;
	cdph->cmds = cmd_arg(argc, argv);
	if (!cdph->cmds || !*cdph->cmds)
	{
		freefunc(cdph->cmds);
		return (1);
	}
	if (*cdph->cmds && **cdph->cmds != '\0'
		&& access(cdph->cmds[0], F_OK | X_OK) == 0)
		execve(cdph->cmds[0], cdph->cmds, envp);
	exec_cmd(concat, cdph, envp);
	freefunc(concat);
	error_printing(cdph->cmds);
	(freefunc(cdph->cmds), exit(127));
}
