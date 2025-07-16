/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:08:28 by jhor              #+#    #+#             */
/*   Updated: 2025/04/15 17:08:28 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	s1;
	char	*dup;
	int		i;

	s1 = ft_strlen(s);
	dup = (char *) malloc(sizeof(char) * (s1 + 1));
	i = 0;
	if (dup == 0)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	wordcount(char *str, char c)
{
	int	words;
	int	j;

	words = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] == c)
			j++;
		if (str[j] != c && str[j])
			words++;
		while (str[j] != c && str[j])
			j++;
	}
	return (words);
}

char	**ft_split(char *s, char c)
{
	int		wordlen;
	char	**str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			if (!ft_strchr(s, c))
				wordlen = ft_strlen(s);
			else
				wordlen = ft_strchr(s, c) - s;
			str[i] = ft_substr(s, 0, wordlen);
			i++;
			s += wordlen;
		}
	}
	str[i] = NULL;
	return (str);
}
