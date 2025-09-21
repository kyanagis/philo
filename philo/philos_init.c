/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:13:39 by kyanagis          #+#    #+#             */
/*   Updated: 2025/09/21 17:14:04 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	setup_one(t_philo *one, t_shared *box, t_fork *forks, int i)
{
	int	count;

	count = box->config.philo_count;
	one->id = i + 1;
	one->shared = box;
	one->left = &forks[i];
	one->right = &forks[(i + 1) % count];
	one->meals_done = 0;
	one->last_meal_ms = box->start_ms;
	one->first_left = ((one->id % 2) == 1);
	if (pthread_mutex_init(&one->meal_mutex, NULL) != 0)
		return (false);
	return (true);
}

static void	rollback_meals(t_philo *ph, int last)
{
	while (last >= 0)
	{
		pthread_mutex_destroy(&ph[last].meal_mutex);
		--last;
	}
}

bool	philos_init(t_philo **out, t_shared *box, t_fork *forks)
{
	int		count;
	int		i;
	t_philo	*ph;

	if (!out || !box || !forks)
		return (false);
	count = box->config.philo_count;
	ph = (t_philo *)malloc(sizeof(*ph) * count);
	if (!ph)
		return (false);
	i = 0;
	while (i < count)
	{
		if (!setup_one(&ph[i], box, forks, i))
		{
			rollback_meals(ph, i - 1);
			free(ph);
			return (false);
		}
		++i;
	}
	*out = ph;
	return (true);
}
