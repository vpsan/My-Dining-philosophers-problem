/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_4_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:04:43 by bhatches          #+#    #+#             */
/*   Updated: 2021/08/23 00:46:23 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_current_action(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("\033[0;3%dm", philo->id_philo + 1);
	if (str != NULL)
	{
		printf("%lld %d %s\n",
			   time_now() - (philo->time_start), (philo->id_philo + 1), str);
	}
	printf("\033[0m");
	pthread_mutex_unlock(philo->print_mutex);
}

int	death_checker(t_main_strct *mainStrct, int i)
{
	if (mainStrct->philo[i].time_die < time_now() - (
			mainStrct->philo[i].time_last_meal))
	{
		pthread_mutex_lock(mainStrct->print_mutex);
		if (mainStrct->philo[0].time_die < 100)
			printf("%lld %d died\n", mainStrct->philo[0].time_die,
				   mainStrct->philo[i].id_philo);
		else
			printf("%lld %d died\n",
				   time_now() - (mainStrct->philo[0].time_start) - 1,
				   mainStrct->philo[i].id_philo);
		return (0);
	}
	else if (mainStrct->philo[i].started == true
		&& mainStrct->philo[i].finished == true)
		return (0);
	return (1);
}

void	*deathchecker_routine(void *argv)
{
	t_main_strct	*mainStrct;
	int				i;

	go_to_sleep(100);
	mainStrct = (t_main_strct *)argv;
	i = 0;
	while (true)
	{
		i = 0;
		while (i < mainStrct->nb_philo)
		{
			if (death_checker(mainStrct, i) != 1)
				return (NULL);
			++i;
		}
	}
	return (NULL);
}

void	*philo_routine(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	philo->time_start = time_now();
	philo->time_last_meal = time_now();
	if ((philo->id_philo + 1) % 2 == 0)
		go_to_sleep(philo->time_eat / 2);
	philo->started = true;
	while (philo->nb_meals)
	{
		pthread_mutex_lock(philo->right_fork_mutex);
		print_current_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork_mutex);
		print_current_action(philo, "has taken a fork");
		philo->time_last_meal = time_now();
		print_current_action(philo, "is eating");
		go_to_eat(philo);
		pthread_mutex_unlock(philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
		print_current_action(philo, "is sleeping");
		go_to_sleep(philo->time_sleep);
		print_current_action(philo, "is thinking");
	}
	philo->finished = true;
	return (NULL);
}

int	create_threads(t_main_strct *mainStrct, int nb_philo)
{
	int	i;

	if (pthread_create(mainStrct->death_theard, NULL,
			deathchecker_routine, (void *) mainStrct))
		return (ERROR);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_create(&mainStrct->philo->thread_philo, NULL,
				philo_routine, (void *)(&(mainStrct->philo[i]))))
			return (ERROR);
		pthread_detach((mainStrct->philo)->thread_philo);
		i++;
	}
	pthread_join(*mainStrct->death_theard, NULL);
	return (0);
}
