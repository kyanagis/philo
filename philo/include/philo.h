/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 00:53:36 by kyanagis          #+#    #+#             */
/*   Updated: 2025/10/16 03:48:16 by kyanagis         ###   ########.fr       */
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

typedef struct s_shared
{
	t_config		cfg;
	long long		start_ms;
	int				stop;
	int				full_count;
	pthread_mutex_t	state_mutex;
	pthread_mutex_t	print_mutex;
}					t_shared;

typedef struct s_philo
{
	int				id;
	t_shared		*box;
	t_fork			*left;
	t_fork			*right;

	t_fork			*first;
	t_fork			*second;
}					t_philo;

int					put_err_msg(const char *msg);
size_t				ft_strlen(const char *msg);

bool				forks_init(t_fork **out_forks, int count);
bool				parse_config(int argc, char **argv, t_config *config);
bool				validate_config(const t_config *config);
#endif