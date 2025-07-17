/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:15:17 by jhor              #+#    #+#             */
/*   Updated: 2025/07/17 20:51:31 by jhor             ###   ########.fr       */
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
