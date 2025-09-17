#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

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

long long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000LL + (long long)tv.tv_usec / 1000LL);
}
static int	get_stop(const t_shared *sh)
{
	int	value;

	pthread_mutex_lock((pthread_mutex_t *)&sh->stop_mtx);
	value = sh->stop;
	pthread_mutex_unlock((pthread_mutex_t *)&sh->stop_mtx);
	return (value);
}

void	sleep_ms_precise(t_shared *sh, int ms)
{
	long long	start_ms;
	long long	target_ms;

	start_ms = now_ms();
	target_ms = start_ms + (long long)ms;
	while (!get_stop(sh) && now_ms() < target_ms)
		usleep(100);
}

static void	set_stop(t_shared *sh, int v)
{
	pthread_mutex_lock(&sh->stop_mtx);
	sh->stop = v;
	pthread_mutex_unlock(&sh->stop_mtx);
}

int	main(void)
{
	t_shared sh;
	long long t0;
	long long t1;

	sh.stop = 0;
	pthread_mutex_init(&sh.stop_mtx, NULL);

	t0 = now_ms();
	sleep_ms_precise(&sh, 200);
	t1 = now_ms();
	printf("sleep no-stop: ~%lld ms\n", t1 - t0);

	set_stop(&sh, 1);
	t0 = now_ms();
	sleep_ms_precise(&sh, 200);
	t1 = now_ms();
	printf("sleep stopped: ~%lld ms\n", t1 - t0);

	pthread_mutex_destroy(&sh.stop_mtx);
	return (0);
}