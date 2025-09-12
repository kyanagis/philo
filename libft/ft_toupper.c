/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:34:51 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 17:16:05 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// int	main(void)
// {
// 	printf("%c\n", ft_toupper('a'));
// 	printf("%c\n", ft_toupper('z'));
// 	printf("%c\n", ft_toupper('A'));
// 	printf("%c\n", ft_toupper('0'));
// 	printf("%c\n", ft_toupper('1'));
// 	printf("%c\n\n", ft_toupper('\0'));

// 	printf("%c\n", toupper('a'));
// 	printf("%c\n", toupper('z'));
// 	printf("%c\n", toupper('A'));
// 	printf("%c\n", toupper('0'));
// 	printf("%c\n", toupper('1'));
// 	printf("%c\n\n", toupper('\0'));
// 	return (0);
// }