
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERR_USAGE "Usage:./philo n_philo t_die t_eat t_sleep [must_eat]\n"
# define ERR_INIT "Error: init\n"
# define ERR_START "Error: start\n"
typedef struct s_config
{
	int philo_count;       // 哲学者
	int die_timeout_ms;    // 食べ始められないと死ぬ
	int eat_duration_ms;   // 食事にかける時間
	int sleep_duration_ms; // 睡眠にかける時間
	int meals_required;    // 全員が食べるべき回数
}					t_config;

typedef struct s_fork
{
	pthread_mutex_t	mtx;
}					t_fork;

struct s_shared;

typedef struct s_philo
{
	int				id;
	t_fork			*left;
	t_fork			*right;
	int				meals_eaten;
	long long		last_meal_ms;
	pthread_t		thread;
	struct s_shared	*shared;
}					t_philo;

typedef struct s_shared
{
	t_config		conf;
	long long		start_ms;
	int				stop;
	pthread_mutex_t	stop_mtx;
	pthread_mutex_t	print_mtx;
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		monitor_thread;
}					t_shared;

bool				parse_config(int argc, char **argv, t_config *conf);

long long			now_ms(void);
void				sleep_ms_precise(t_shared *sh, int ms);

void				print_state(t_shared *sh, int id, const char *msg);
void				print_death(t_shared *sh, int id);

bool				init_shared(t_shared *sh, const t_config *conf);
void				destroy_shared(t_shared *sh);

bool				sim_start(t_shared *sh);
void				sim_join(t_shared *sh);

#endif
