#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_config
{
	int philo_count;       // 哲学者
	int die_timeout_ms;    // 食べ始められないと死ぬまでの猶予(
	int eat_duration_ms;   // 食事にかける時間
	int sleep_duration_ms; // 睡眠にかける時間
	int meals_required;    // 全員が食べるべき回数
}			t_config;

static bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
static bool	parse_pos_int(const char *s, int *out_value)
{
	long		value;
	const char	*cursor;

	if (!s || !*s)
		return (false);
	cursor = s;
	while (*cursor == ' ' || (*cursor >= 9 && *cursor <= 13))
		++cursor;
	if (*cursor == '+')
		++cursor;
	if (!ft_isdigit(*cursor))
		return (false);
	value = 0;
	while (ft_isdigit(*cursor))
	{
		if (value > (INT_MAX - (*cursor - '0')) / 10)
			return (false);
		value = value * 10 + (*cursor - '0');
		++cursor;
	}
	if (*cursor != '\0' || value < 1)
		return (false);
	*out_value = (int)value;
	return (true);
}

bool	parse_config(int argc, char **argv, t_config *config)
{
	if (!(argc == 5 || argc == 6))
		return (false);
	if (!parse_pos_int(argv[1], &config->philo_count))
		return (false);
	if (!parse_pos_int(argv[2], &config->die_timeout_ms))
		return (false);
	if (!parse_pos_int(argv[3], &config->eat_duration_ms))
		return (false);
	if (!parse_pos_int(argv[4], &config->sleep_duration_ms))
		return (false);
	if (argc == 6)
	{
		if (!parse_pos_int(argv[5], &config->meals_required))
			return (false);
	}
	else
		config->meals_required = -1;
	return (true);
}

static bool	valdate_config(const t_config *config)
{
	if (config->philo_count < 1)
		return (false);
	if (config->die_timeout_ms < 1 || config->eat_duration_ms < 1
		|| config->sleep_duration_ms < 1)
		return (false);
	if (!(config->meals_required == -1 || config->meals_required >= 1))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_config	config;

	if (!parse_config(argc, argv, &config))
		return (EXIT_FAILURE);
	if (!valdate_config(&config))
		return (EXIT_FAILURE);
	printf("%d\n%d\n%d\n%d\n%d\n", config.philo_count, config.die_timeout_ms,
		config.eat_duration_ms, config.sleep_duration_ms,
		config.meals_required);
	return (EXIT_SUCCESS);
}
