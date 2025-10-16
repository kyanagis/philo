#include "philo.h"

bool	shared_init(t_shared *box, t_config *config)
{
	if (!box || !config)
		return (false);
	box->cfg = *config;
	box->start_ms = 0;
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