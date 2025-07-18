/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:34:05 by jhor              #+#    #+#             */
/*   Updated: 2025/04/22 11:34:05 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**cmd_arg(int argc, char *argv)
{
	char	**cmds;

	if (argc > 1)
		cmds = ft_split(argv, ' ');
	else
		return (NULL);
	if (cmds == NULL)
		exit(1);
	return (cmds);
}

void	exec_cmd(char **concat, t_cato *cdph, char **envp)
{
	while (concat[cdph->i])
	{
		if (cdph->cmds[0] && concat[cdph->i])
		{
			cdph->execmd = ft_strjoinv(3, concat[cdph->i], "/", cdph->cmds[0]);
			if (cdph->execmd != NULL && access(cdph->execmd, F_OK | X_OK) == 0)
				execve(cdph->execmd, cdph->cmds, envp);
			free(cdph->execmd);
		}
		cdph->i++;
	}
}

int	check_cmd_paths(char **concat, int argc, char *argv, char **envp)
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
