/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:58:29 by kyanagis          #+#    #+#             */
/*   Updated: 2025/10/07 05:49:51 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*routine(void *arg)
// {
// }

 bool	philos_start(t_philo *philo, t_shared *box)
{
	int i;
	int n;
(void)philo;
(void)box;
	
	i = 0;
	n = box->config.philo_count;
	while (i < n)
	{
		// if (pthread_create(&philo[i].meal_mutex, NULL, routine, philo) != 0)
		// 	return (false);
		++i;
	}
	// if (pthread_create(&philo[i].meal_mutex, NULL, routine, philo) != 0)
	// 	return (false);
	return (true);
}