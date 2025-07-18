/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:15:17 by jhor              #+#    #+#             */
/*   Updated: 2025/07/18 17:32:44 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	freefunc(char **concat)
{
	int	i;

	i = 0;
	if (!concat)
		return ;
	while (concat[i])
	{
		free(concat[i]);
		i++;
	}
	free(concat);
}

void	init_status(t_status *status)
{
	status->status1 = 0;
	status->status2 = 0;
}
