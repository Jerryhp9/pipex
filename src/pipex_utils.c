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

static int	wordcount(char *str, char c)
{
	int words;
	int j;

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

char *	ft_strjoinv(int nbr, ...)
{
	va_list p;
	char *str;
	char *temp;

	va_start(p, nbr);
	str = ft_strdup("");
	while (nbr--)
	{
		temp = str;
		str = ft_strjoin(str, va_arg(p, char *));
		free(temp);
	}
	// free(temp);
	return (str);
}
