#include "philo.h"

void	print_state(t_shared *box, int philo_id, const char *msg,
		bool important)
{
	long long	now;
	long long	elapsed;
	int			should_block;

	if (!box || !msg)
		return ;
	pthread_mutex_lock(&box->state_mutex);
	should_block = (box->stop && !important);
	pthread_mutex_unlock(&box->state_mutex);
	if (should_block)
		return ;
	now = now_ms();
	if (now < 0)
		return ;
	elapsed = now - box->start_ms;
	pthread_mutex_lock(&box->print_mutex);
	printf("%lld %d %s\n", elapsed, philo_id + 1, msg);
	pthread_mutex_unlock(&box->print_mutex);
}
