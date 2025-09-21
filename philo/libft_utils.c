/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:52:54 by kyanagis          #+#    #+#             */
/*   Updated: 2025/09/21 16:52:55 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *s)
{
	const char	*start = s;

	while (*s)
		++s;
	return ((int)(s - start));
}
bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
