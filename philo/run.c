/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:58:29 by kyanagis          #+#    #+#             */
/*   Updated: 2025/09/21 17:58:55 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
}

static bool	philos_start(t_philo *philo, t_shared *box)
{
	int i;
	int n;

	i = 0;
	n = box->config.philo_count;
	while (i < n)
	{
		if (pthread_create(&philo[i].meal_mutex, NULL, routine, philo) != 0)
			return (false);
		++i;
	}
	if (pthread_create(&philo[i].meal_mutex, NULL, routine, philo) != 0)
		return (false);
	return (true);
}