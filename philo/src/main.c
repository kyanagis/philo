/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:24:49 by kyanagis          #+#    #+#             */
/*   Updated: 2025/10/16 04:38:21 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define ERR_PARSE_MSG "parase:error"
#define ERR_VALID_MSG "validate:error"
#define ERR_FORKS_MSG "forks:error"

void	print_config(t_config config)
{
	// test config
	printf("%d\n", config.philo_count);
	printf("%d\n", config.die_ms);
	printf("%d\n", config.eat_ms);
	printf("%d\n", config.sleep_ms);
	printf("%d\n", config.must_eat);
}

bool	shared_init(t_shared *box, t_config *config)
{
	if (!box || !config)
		return (false);
	box->cfg = *config;
	box->stop = 0;
	box->full_count = 0;
	if (pthread_mutex_init(&box->print_mutex, NULL))
		return (false);
	if (pthread_mutex_init(&box->state_mutex, NULL))
	{
		pthread_mutex_destroy(&box->print_mutex);
		return (false);
	}
	return (true);
}

static int	philosophers(int argc, char **argv)
{
	t_config	config;
	t_fork		*forks;
	t_shared	*box;

	box = NULL;
	if (!parse_config(argc, argv, &config))
		return (put_err_msg(ERR_PARSE_MSG));
	if (!validate_config(&config))
		return (put_err_msg(ERR_VALID_MSG));
	if (!forks_init(&forks, config.philo_count))
		return (put_err_msg(ERR_FORKS_MSG));
	if (!shared_init(box, &config))
		print_config(config);
	return (0);
}

int	main(int argc, char **argv)
{
	return (philosophers(argc, argv));
}