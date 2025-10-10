/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:52:45 by kyanagis          #+#    #+#             */
/*   Updated: 2025/10/07 10:42:33 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	put_err_msg(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	return (EXIT_FAILURE);
}

static void	shared_destroy(t_shared *box)
{
	pthread_mutex_destroy(&box->state_mutex);
	pthread_mutex_destroy(&box->print_mutex);
}

static void	forks_destroy(t_fork *forks, int count)
{
	int	i;

	if (!forks)
		return ;
	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&forks[i].mtx);
		++i;
	}
	free(forks);
}

static int	fail_cleanup_and_exit(t_fork *forks, t_shared *box, int count,
		int flag)
{
	if (flag >= 2)
		shared_destroy(box);
	if (flag >= 1)
		forks_destroy(forks, count);
	return (put_err_msg(ERR_INIT));
}

static int	philos_destroy(t_philo **philo, t_fork *forks, t_shared *box,
		int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&philo[i]->meal_mutex);
		++i;
	}
	return (fail_cleanup_and_exit(forks, box, count, 2));
}

static bool philosophers(int argc,char **argv)
{
	t_config	config;
	t_philo		*philo;
	t_fork		*forks;
	t_shared	box;

	philo = NULL;
	if (!parse_config(argc, argv, &config))
		return (put_err_msg(ERR_USAGE));
	if (!validate_config(&config))
		return (put_err_msg(ERR_INIT));
	if (!forks_init(&forks, config.philo_count))
		return (put_err_msg(ERR_INIT));
	if (!shared_init(&box, &config))
		return (fail_cleanup_and_exit(forks, &box, config.philo_count, 1));
	box.start_ms = now_ms() + 50;
	if (!philos_init(&philo, &box, forks))
		return (fail_cleanup_and_exit(forks, &box, config.philo_count, 2));
	if (!philos_start(philo, &box))
		return (philos_destroy(&philo, forks, &box, config.philo_count));
	printf("%lld\n", box.start_ms);
	return (EXIT_SUCCESS);


}

int main(int argc,char **argv)
{
	return philosophers(argc,argv);
}


// int	main(int argc, char **argv)
// {
	// t_config	config;
	// t_philo		*philo;
	// t_fork		*forks;
	// t_shared	box;

	// philo = NULL;
	// if (!parse_config(argc, argv, &config))
	// 	return (put_err_msg(ERR_USAGE));
	// if (!validate_config(&config))
	// 	return (put_err_msg(ERR_INIT));
	// if (!forks_init(&forks, config.philo_count))
	// 	return (put_err_msg(ERR_INIT));
	// if (!shared_init(&box, &config))
	// 	return (fail_cleanup_and_exit(forks, &box, config.philo_count, 1));
	// box.start_ms = now_ms() + 50;
	// if (!philos_init(&philo, &box, forks))
	// 	return (fail_cleanup_and_exit(forks, &box, config.philo_count, 2));
	// if (!philos_start(philo, &box))
	// 	return (philos_destroy(&philo, forks, &box, config.philo_count));
	// printf("%lld\n", box.start_ms);
	// return (EXIT_SUCCESS);
// }
