#include "philo.h"

long long	now_ms(void)
{
	struct timeval tv;
	long long sec_ms;
	long long usec_ms;

	if (gettimeofday(&tv, NULL))
		return (-1);
	sec_ms = (long long)tv.tv_sec * 1000;
	usec_ms = (long long)(tv.tv_usec / 1000);
	return (sec_ms + usec_ms);
}