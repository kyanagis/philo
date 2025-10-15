/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:24:49 by kyanagis          #+#    #+#             */
/*   Updated: 2025/10/16 02:43:41 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_config(t_config config)
{
	// test config
	printf("%d\n", config.philo_count);
	printf("%d\n", config.die_ms);
	printf("%d\n", config.eat_ms);
	printf("%d\n", config.sleep_ms);
	printf("%d\n", config.must_eat);
}

static bool	forks_init(t_fork **out_forks, int count)
{
	int		i;
	t_fork	*forks;

	i = 0;
	if (!out_forks || count < 1)
		return (false);
	forks = malloc(sizeof(t_fork) * count);
	if (!forks)
		return (false);
	while (i < count)
	{
		forks[i].id = i;
		if (pthread_mutex_init(&forks[i].mtx, NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&forks[i].mtx);
			free(forks);
			return (false);
		}
		++i;
	}
	*out_forks = forks;
	return (true);
}

static int	philosophers(int argc, char **argv)
{
	t_config	config;
	t_fork		*forks;

	if (!parse_config(argc, argv, &config))
		return (1);
	if (!validate_config(&config))
		return (1);
	if (!forks_init(&forks, config.philo_count))
		return (1);
	print_config(config);
	return (0);
}

int	main(int argc, char **argv)
{
	return (philosophers(argc, argv));
}