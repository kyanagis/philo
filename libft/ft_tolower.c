/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:34:47 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 17:16:02 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// int	main(void)
// {
// 	printf("%c\n", ft_tolower('a'));
// 	printf("%c\n", ft_tolower('z'));
// 	printf("%c\n", ft_tolower('A'));
// 	printf("%c\n", ft_tolower('0'));
// 	printf("%c\n", ft_tolower('1'));
// 	printf("%c\n\n", ft_tolower('\0'));

// 	printf("%c\n", tolower('a'));
// 	printf("%c\n", tolower('z'));
// 	printf("%c\n", tolower('A'));
// 	printf("%c\n", tolower('0'));
// 	printf("%c\n", tolower('1'));
// 	printf("%c\n\n", tolower('\0'));
// 	return (0);
// }