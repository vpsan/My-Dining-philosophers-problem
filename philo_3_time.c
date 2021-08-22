/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:01:15 by bhatches          #+#    #+#             */
/*   Updated: 2021/08/19 23:44:48 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	time_now(void)
{
	struct timeval	time_now;
	uint64_t		seconds_now;
	uint64_t		milliseconds_now;
	uint64_t		microseconds_now;

	gettimeofday(&time_now, NULL);
	seconds_now = time_now.tv_sec;
	microseconds_now = time_now.tv_usec;
	milliseconds_now = seconds_now * 1000 + microseconds_now / 1000;
	return (milliseconds_now);
}

void	go_to_sleep(uint64_t microseconds_to_sleep)
{
	uint64_t		microseconds_till;

	microseconds_till = time_now() + microseconds_to_sleep;
	while (time_now() < microseconds_till)
		usleep(600);
	return ;
}

void	go_to_eat(t_philo *philo)
{
	uint64_t	time_saved;

	time_saved = time_now();
	if (philo->nb_meals == MINIMUM_INT)
		philo->nb_meals = -1;
	philo->nb_meals--;
	while (time_now() - time_saved < philo->time_eat)
	{
		usleep(300);
	}
	return ;
}
