/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:38:46 by kyanagis          #+#    #+#             */
/*   Updated: 2025/10/16 01:41:54 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	validate_config(const t_config *config)
{
	if (config->philo_count < 1)
		return (false);
	if (config->die_ms < 1 || config->eat_ms < 1 || config->sleep_ms < 1)
		return (false);
	if (!(config->must_eat == -1 || config->must_eat >= 1))
		return (false);
	return (true);
}