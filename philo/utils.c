/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:53:11 by kyanagis          #+#    #+#             */
/*   Updated: 2025/09/21 16:59:26 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	parse_pos_int(const char *s, int *out_value)
{
	long		value;
	const char	*cursor;

	if (!s || !*s)
		return (false);
	cursor = s;
	while (*cursor == ' ' || (*cursor >= 9 && *cursor <= 13))
		++cursor;
	if (*cursor == '+')
		++cursor;
	if (!ft_isdigit(*cursor))
		return (false);
	value = 0;
	while (ft_isdigit(*cursor))
	{
		if (value > (INT_MAX - (*cursor - '0')) / 10)
			return (false);
		value = value * 10 + (*cursor - '0');
		++cursor;
	}
	if (*cursor != '\0' || value < 1)
		return (false);
	*out_value = (int)value;
	return (true);
}
