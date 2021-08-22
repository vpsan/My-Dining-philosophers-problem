/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 21:39:12 by bhatches          #+#    #+#             */
/*   Updated: 2021/08/23 00:46:20 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_threads_mutexes(t_prsng_strct *prsngstrct, t_main_strct **mainstrct)
{
	(*mainstrct)->philo_theard = (pthread_t *)
		malloc(sizeof(pthread_t) * prsngstrct->nb_philo);
	if ((*mainstrct)->philo_theard == NULL)
		return (ERROR);
	(*mainstrct)->death_theard = (pthread_t *)
		malloc(sizeof(pthread_t) * 1);
	if ((*mainstrct)->death_theard == NULL)
		return (ERROR);
	(*mainstrct)->forks_mutex = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * prsngstrct->nb_philo);
	if ((*mainstrct)->forks_mutex == NULL)
		return (ERROR);
	(*mainstrct)->print_mutex = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * 1);
	if ((*mainstrct)->print_mutex == NULL)
		return (ERROR);
	return (0);
}

int	init_mutex(t_prsng_strct *prsngstrct, t_main_strct **mainstrct)
{
	int	i;

	i = 0;
	while (i < prsngstrct->nb_philo)
	{
		pthread_mutex_init(&((*mainstrct)->forks_mutex[i]), NULL);
		++i;
	}
	pthread_mutex_init((*mainstrct)->print_mutex, NULL);
	return (0);
}

int	init_each_philo(t_prsng_strct *prsngstrct, t_main_strct **mainstrct)
{
	int	i;

	i = 0;
	while (i < prsngstrct->nb_philo)
	{
		(*mainstrct)->philo[i].id_philo = i;
		(*mainstrct)->philo[i].thread_philo = (*mainstrct)->philo_theard[i];
		(*mainstrct)->philo[i].left_fork_mutex = &(
				(*mainstrct)->forks_mutex[i]);
		(*mainstrct)->philo[i].right_fork_mutex = &(
				(*mainstrct)->forks_mutex[(i + 1) % prsngstrct->nb_philo]);
		(*mainstrct)->philo[i].print_mutex = (*mainstrct)->print_mutex;
		(*mainstrct)->philo[i].started = false;
		(*mainstrct)->philo[i].finished = false;
		(*mainstrct)->philo[i].nb_meals = prsngstrct->nb_meals;
		(*mainstrct)->philo[i].time_start = time_now();
		(*mainstrct)->philo[i].time_die = prsngstrct->time_die;
		(*mainstrct)->philo[i].time_eat = prsngstrct->time_eat;
		(*mainstrct)->philo[i].time_sleep = prsngstrct->time_sleep;
		i++;
	}
	return (0);
}

int	init_main_strct(t_prsng_strct *prsngstrct, t_main_strct *mainstrct)
{
	if (malloc_threads_mutexes(prsngstrct, &mainstrct) == ERROR)
		return (ERROR);
	init_mutex(prsngstrct, &mainstrct);
	mainstrct->nb_philo = prsngstrct->nb_philo;
	mainstrct->philo = (t_philo *) malloc(
			sizeof(t_philo) * prsngstrct->nb_philo);
	if (mainstrct->philo == NULL)
		return (ERROR);
	init_each_philo(prsngstrct, &mainstrct);
	return (0);
}
