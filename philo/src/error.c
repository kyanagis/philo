#include "philo.h"

size_t	ft_strlen(const char *msg)
{
	const char	*head;

	head = msg;
	while (*msg)
		++msg;
	return ((size_t)(msg - head));
}

int	put_err_msg(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}