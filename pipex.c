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

char*ft_splitpath()
{
		
}

char *ft_cmdfound(char *paths)
{
	int fd;
	
	fd = access("", F_OK);
	if (fd == -1)
	{
		printf("%d\n", errno);
		perror("Error");
	}
	printf("%d\n", fd);
}