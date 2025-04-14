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
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int file = open("test.txt", O_WRONLY, 0777);
	printf("the number for this is %d\n", file);
	int file2 = dup2(file, STDOUT_FILENO);
	printf("the number for this is %d\n", file2);
	close(file);
}


// static int	wordcount(char *str, char c)
// {
	// int words;
	// int j;

	// words = 0;
	// j = 0;
	// while (str[j])
	// {
		// if (str[j] == c)
			// word++;
		// if (str[j] != c && str[j] != '\0')
			// j++;
		// j++;
	// }
	// return (words);
// }

// char **splitcmd(const char *str, char c)
// {
	// char **s;
	// int i;

	// i = 0;
	// if (!str)
		// return (NULL);
	// if (str[i] != c)
		// return (str);
	// while (str[i])
	// {
		// if(str[i] == c)
			// s = malloc(sizeof(char *) ) 
	// }
// }

// char *ft_cmdfound(char *paths)
// {
// 	int fd;
	
// 	fd = access("", F_OK);
// 	if (fd == -1)
// 	{
// 		printf("%d\n", errno);
// 		perror("Error");
// 	}
// 	printf("%d\n", fd);
// }
