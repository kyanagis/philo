/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:53:32 by kyanagis          #+#    #+#             */
/*   Updated: 2025/09/21 18:00:46 by kyanagis         ###   ########.fr       */
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

# define ERR_USAGE "Usage:./philo n_philo t_die t_eat t_sleep [must_eat]\n"
# define ERR_INIT "Error: init\n"
# define ERR_START "Error: start\n"

typedef struct s_config
{
	int				philo_count;
	int				die_timeout_ms;
	int				eat_duration_ms;
	int				sleep_duration_ms;
	int				meals_required;
}					t_config;

typedef struct s_fork
{
	pthread_mutex_t	mtx;
}					t_fork;

typedef struct s_shared
{
	t_config		config;
	long long		start_ms;
	int				stop;
	int				full_count;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;

}					t_shared;

typedef struct s_philo
{
	int				id;
	t_shared		*shared;
	t_fork			*left;
	t_fork			*right;
	pthread_mutex_t	meal_mutex;
	long long		last_meal_ms;
	int				meals_done;
	int				first_left;
}					t_philo;

bool				parse_config(int argc, char **argv, t_config *config);
bool				validate_config(const t_config *config);
bool				shared_init(t_shared *box, const t_config *config);
bool				forks_init(t_fork **out, int count);

bool				philos_init(t_philo **out, t_shared *box, t_fork *forks);
bool				safe_mutex_init(pthread_mutex_t *mutex, int index);
bool				parse_pos_int(const char *s, int *out_value);
long long			now_ms(void);

bool				philos_start(t_philo *philo, t_shared *box);

bool				ft_isdigit(int c);
int					ft_strlen(const char *s);

#endif
