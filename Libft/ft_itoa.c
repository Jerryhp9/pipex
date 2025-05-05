/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:48:57 by jhor              #+#    #+#             */
/*   Updated: 2024/11/21 20:48:57 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Handle edge cases '0'
//Calculate digits and handle negative value
//Allocate memory with malloc
//Convert the number into string

#include "libft.h"
//calculate length of integers
static int	numlen(int n)
{
	int	nbr;
	int	len;

	len = 0;
	nbr = n;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	if (n == 0)
		len++;
	if (n < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	len = numlen(n); //the total length of integers
	str = (char *)malloc((sizeof(char)) * (len + 1)); //memory allocation for str
	if (str == NULL)
		return (NULL);
	nbr = n; //set nbr to value of n
	str[len] = '\0'; //add null terminator to end of str
	if (nbr == 0)
		*str = '0';
	if (nbr < 0) // change value into - value by adding sign -
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0) //condition nbr > 0 then decrement from the end, 
	{
		str[--len] = (nbr % 10) + '0'; //decremen then get the modulo of nbr then input it into str
		nbr /= 10; //get the divided value of nbr
	}
	return (str);
}

// int main()
// {
// 	int num = 0;
// 	printf("%s", ft_itoa(num));
// }