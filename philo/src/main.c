/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:24:49 by kyanagis          #+#    #+#             */
/*   Updated: 2025/10/17 06:27:21 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define ERR_PARSE_MSG "parase:error"
#define ERR_VALID_MSG "validate:error"
#define ERR_FORKS_MSG "forks:error"

void	print_debug(t_config config)
{
	// test config
	printf("%d\n", config.philo_count);
	printf("%d\n", config.die_ms);
	printf("%d\n", config.eat_ms);
	printf("%d\n", config.sleep_ms);
	printf("%d\n", config.must_eat);
	printf("%lld\n", now_ms());
}

static int	philosophers(int argc, char **argv)
{
	t_config	config;
	t_fork		*forks;
	t_shared	box;
	t_philo		*philos;

	philos = NULL;
	if (!parse_config(argc, argv, &config))
		return (put_err_msg(ERR_PARSE_MSG));
	if (!validate_config(&config))
		return (put_err_msg(ERR_VALID_MSG));
	if (!forks_init(&forks, config.philo_count))
		return (put_err_msg(ERR_FORKS_MSG));
	if (!shared_init(&box, &config))
		return (1);
	if (!philos_init(&philos, &box, forks))
		return (1);
	print_debug(config);
	return (0);
}

int	main(int argc, char **argv)
{
	return (philosophers(argc, argv));
}