/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 00:53:36 by kyanagis          #+#    #+#             */
/*   Updated: 2025/10/16 02:40:27 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_config
{
	int				philo_count;
	int				die_ms;
	int				eat_ms;
	int				sleep_ms;
	int				must_eat;
}					t_config;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mtx;
}					t_fork;

bool				parse_config(int argc, char **argv, t_config *config);
bool				validate_config(const t_config *config);
#endif