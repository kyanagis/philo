/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 04:32:49 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/28 21:43:34 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	size_t			len;
	unsigned int	un;

	len = ft_numlen(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		un = -n;
	else
		un = n;
	while (len--)
	{
		res[len] = (char)((un % 10) + '0');
		un /= 10;
		if (len == 0 && n < 0)
			res[0] = '-';
	}
	return (res);
}

// int	main(void)
// {
// 	int tests[] = {0, 1, -1, 42, -42, 123456, -123456, INT_MAX, INT_MIN};
// 	int i = 0;
// 	char *result;

// 	while (i < (int)(sizeof(tests) / sizeof(tests[0])))
// 	{
// 		result = ft_itoa(tests[i]);
// 		if (result)
// 		{
// 			printf("Test %d: %d → \"%s\"\n", i + 1, tests[i], result);
// 			free(result);
// 		}
// 		else
// 		{
// 			printf("Test %d: %d → NULL (allocation failed)\n", i + 1, tests[i]);
// 		}
// 		++i;
// 	}
// 	return (0);
// }