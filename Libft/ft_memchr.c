/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:17:34 by jhor              #+#    #+#             */
/*   Updated: 2024/11/13 20:17:34 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check each bytes for occurence of a certain char and return a str starting from the occurence

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n) //n is to limit the bytes of memory to check
{
	const char	*p;
	size_t		i;

	p = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (char)c)
		{
			return (((char *)p) + i);
		}
		i++;
	}
	return (NULL);
}

/*int main()
{
	const char str[] = "Internationally responsive";

	char *ptr = ft_memchr(str, 'p', 23);

	if (*ptr != '\0') {
		printf("%s\n", ptr);
	}
}*/
