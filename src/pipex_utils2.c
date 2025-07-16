/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:15:17 by jhor              #+#    #+#             */
/*   Updated: 2025/07/16 22:26:52 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoinv(int nbr, ...)
{
	va_list	p;
	char	*str;
	char	*temp;

	va_start(p, nbr);
	str = ft_strdup("");
	while (nbr--)
	{
		temp = str;
		str = ft_strjoin(str, va_arg(p, char *));
		free(temp);
	}
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (n > i && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i >= n)
		return (0);
	else
		return ((unsigned char)s1[i] - s2[i]);
}

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
