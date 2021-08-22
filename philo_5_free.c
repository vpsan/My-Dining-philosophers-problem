/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_5_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 21:43:39 by bhatches          #+#    #+#             */
/*   Updated: 2021/08/23 00:46:25 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_resources(t_main_strct *mainstrct, int nb_philo)
{
	int	i;

	if (mainstrct->philo != NULL)
		free(mainstrct->philo);
	if (mainstrct->philo_theard != NULL)
		free(mainstrct->philo_theard);
	if (mainstrct->death_theard != NULL)
		free(mainstrct->death_theard);
	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_destroy(&mainstrct->forks_mutex[i]);
		usleep(10);
		i++;
	}
	if (mainstrct->forks_mutex != NULL)
		free(mainstrct->forks_mutex);
	if (mainstrct->print_mutex != NULL)
		free(mainstrct->print_mutex);
	pthread_mutex_destroy(mainstrct->print_mutex);
	return ;
}
