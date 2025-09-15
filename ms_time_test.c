#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

long long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (long long)tv.tv_sec * 100LL + (long long)(tv.tv_usec / 1000);
}

int	main(void)
{
	long long test;
	test = now_ms();
	printf("%lld\n", test);
}