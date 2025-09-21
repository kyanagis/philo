/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:52:57 by kyanagis          #+#    #+#             */
/*   Updated: 2025/09/21 17:14:14 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	parse_config(int argc, char **argv, t_config *config)
{
	if (!(argc == 5 || argc == 6))
	{
		return (false);
	}
	if (!parse_pos_int(argv[1], &config->philo_count))
		return (false);
	if (!parse_pos_int(argv[2], &config->die_timeout_ms))
		return (false);
	if (!parse_pos_int(argv[3], &config->eat_duration_ms))
		return (false);
	if (!parse_pos_int(argv[4], &config->sleep_duration_ms))
		return (false);
	if (argc == 6)
	{
		if (!parse_pos_int(argv[5], &config->meals_required))
			return (false);
	}
	else
		config->meals_required = -1;
	return (true);
}

bool	forks_init(t_fork **out, int count)
{
	t_fork	*forks;
	int		i;

	i = 0;
	if (!out || count <= 0)
		return (false);
	forks = malloc(sizeof(t_fork) * count);
	if (!forks)
		return (false);
	while (i < count)
	{
		if (pthread_mutex_init(&forks[i].mtx, NULL))
		{
			while (i-- > 0)
				pthread_mutex_destroy(&forks[i].mtx);
			free(forks);
			return (false);
		}
		++i;
	}
	*out = forks;
	return (true);
}

bool	shared_init(t_shared *box, const t_config *config)
{
	box->config = *config;
	box->stop = 0;
	box->full_count = 0;
	if (pthread_mutex_init(&box->print_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&box->state_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&box->print_mutex);
		return (false);
	}
	return (true);
}

bool	validate_config(const t_config *config)
{
	if (config->philo_count < 1)
		return (false);
	if (config->die_timeout_ms < 1 || config->eat_duration_ms < 1
		|| config->sleep_duration_ms < 1)
		return (false);
	if (!(config->meals_required == -1 || config->meals_required >= 1))
		return (false);
	return (true);
}
