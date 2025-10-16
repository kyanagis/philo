#include "philo.h"

static void	set_fork_order(t_philo *list)
{
	if (!list || !list->left || !list->right)
		return ;
	if (list->left->id < list->right->id)
	{
		list->first = list->left;
		list->second = list->right;
	}
	else
	{
		list->first = list->right;
		list->second = list->left;
	}
}

bool	philos_init(t_philo **out_philo, t_shared *box, t_fork *forks)
{
	int		count;
	int		idx;
	t_philo	*list;

	idx = 0;
	if (!out_philo || !box || !forks)
		return (false);
	count = box->cfg.philo_count;
	list = malloc(sizeof(t_philo) * count);
	if (!list)
		return (false);
	while (idx < count)
	{
		list[idx].id = idx;
		list[idx].box = box;
		list[idx].left = &forks[idx];
		list[idx].right = &forks[(idx + 1) % count];
		set_fork_order(&list[idx]);
		++idx;
	}
	*out_philo = list;
	return (true);
}
