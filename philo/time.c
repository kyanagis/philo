/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:53:08 by kyanagis          #+#    #+#             */
/*   Updated: 2025/09/21 16:53:09 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	now_ms(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL))
		return (0);
	return ((long long)now.tv_sec * 1000LL + (long long)now.tv_usec / 1000LL);
}
