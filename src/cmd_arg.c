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

char **cmd_arg(int argc, char *argv)
{
	char	**cmds;

	if (argc > 1)
		cmds = ft_split(argv, ' ');
	else 
		return NULL;
	return (cmds);
}
// int main(int argc, char **argv)
// {
// 	int i;

// 	i = 0;
	
// 	char **example = cmd_arg(argc, argv);
// 	while (example[i])
// 	{
// 		printf("%s", example[i]);
// 		i++;
// 	}
// 	return 0;
// }