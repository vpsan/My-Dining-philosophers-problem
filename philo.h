/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:14:17 by bhatches          #+#    #+#             */
/*   Updated: 2021/08/19 23:44:51 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# define ERROR 1
# define MINIMUM_INT	-2147483648

typedef struct s_prsng_strct
{
	int			nb_philo;
	uint64_t	time_die;
	uint64_t	time_eat;
	uint64_t	time_sleep;
	int			nb_meals;
}	t_prsng_strct;

typedef struct s_philo
{
	int				id_philo;
	pthread_t		thread_philo;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	pthread_mutex_t	*print_mutex;
	bool			finished;
	bool			started;
	int				nb_meals;
	uint64_t		time_start;
	uint64_t		time_last_meal;
	uint64_t		time_die;
	uint64_t		time_eat;
	uint64_t		time_sleep;
}	t_philo;

typedef struct s_main_strct
{
	int				nb_philo;
	t_philo			*philo;
	pthread_t		*philo_theard;
	pthread_t		*death_theard;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	*print_mutex;
}	t_main_strct;

int			prsng_vldtn(int argc, char **argv, t_prsng_strct *prsngstrct);
int			ft_atoi(const char *str);
bool		vldthn_chech_str_is_digits(char *str);

uint64_t	time_now(void);
void		go_to_sleep(uint64_t microseconds_to_sleep);
void		go_to_eat(t_philo *philo);

int			init_main_strct(t_prsng_strct *prsngStrct, t_main_strct *mainStrct);

int			create_threads(t_main_strct *mainStrct, int nb_philo);

void		free_resources(t_main_strct *mainStrct, int nb_philo);

#endif