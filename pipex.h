/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 01:12:31 by jhor              #+#    #+#             */
/*   Updated: 2025/03/30 01:12:31 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdarg.h>
#include "./libft/libft.h"

static int	wordcount(char *str, char c);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif