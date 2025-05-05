/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:38:13 by jhor              #+#    #+#             */
/*   Updated: 2024/11/15 12:38:13 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//convert character into intergers
//line 23 - condition within the isspace characters then means its true;
//line 38 - if check whether it is + or -, if true then check if its - then change positive to negative sign;
//line 44 - loop to change characters using dec 48 to get the remaining as the integer then + num to combine the integers;

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}
// int main()
// {
// 	char str1[] = "   +1234a567";

// 	printf("%d\n", ft_atoi(str1));
// }