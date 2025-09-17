#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

long long	now_ms(void)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) != 0)
		return (-1);
	return ((long long)current.tv_sec * 1000LL + (long long)(current.tv_usec
			/ 1000));
	// imano jikoku ga deru rasii
}

long long	ramen_ms(long long start_ms)
{
	long long	current_ms;

	if (current_ms < 0)
		return (-1);
	return (current_ms - start_ms);
}

void	sleep_ms(long long tes_ms)
{
	long long	start_ms;

	start_ms = now_ms();
	if (start_ms < 0)
		return (-1);
	while (ramen_ms(start_ms) < tes_ms)
		usleep(200);
}

int	main(int argc, char **argv)
{
	struct timeval st;
	int rc = 0;
	printf("%ld\n", st.tv_sec);
	printf("%ld\n", st.tv_usec);
}