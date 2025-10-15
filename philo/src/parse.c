/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:28:31 by kyanagis          #+#    #+#             */
/*   Updated: 2025/10/16 01:44:14 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (0x30 <= c && c <= 0x39);
}

bool	parse_int(const char *s, int *out_value)
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

bool	parse_config(int argc, char **argv, t_config *config)
{
	if (!(argc == 5 || argc == 6))
		return (false);
	if (!parse_int(argv[1], &config->philo_count))
		return (false);
	if (!parse_int(argv[2], &config->die_ms))
		return (false);
	if (!parse_int(argv[3], &config->eat_ms))
		return (false);
	if (!parse_int(argv[4], &config->sleep_ms))
		return (false);
	if (argc == 6)
	{
		if (!parse_int(argv[5], &config->must_eat))
			return (false);
	}
	else
		config->must_eat = -1;
	return (true);
}