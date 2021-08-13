/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mandatory_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:14:15 by bhatches          #+#    #+#             */
/*   Updated: 2021/08/13 15:34:11 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_mandatory.h"

#define ERRRO 1

typedef struct 	s_prsng_strct
{
	int			philo_n; 	// argv[1]
	useconds_t 	time_die; 	// argv[2] 	
	useconds_t 	time_eat; 	// argv[3]
	useconds_t 	time_sleep; // argv[4]
	int 		meals_n; 	// argv[5] 	
} 				t_prsng_strct;

int	parsing_input(int argc, char **argv, t_prsng_strct *prmtrs)
{
	if (argc != 5 || argc != 6) 
	{
		printf("Error: argc is not correct\n");
		return (ERRRO);
	}
	// ДОБАВИТЬ ПРОВЕРКИ
	prmtrs->philo_n = ft_atoi(argv[1]);
	prmtrs->time_die= ft_atoi(argv[2]);
	prmtrs->time_eat = ft_atoi(argv[3]);
	prmtrs->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		prmtrs->meals_n = ft_atoi(argv[5]);
	else
	 	prmtrs->meals_n = 0;
}

int main(int argc, char **argv)
{
	t_prsng_strct prmtrs;

	if (parsing_input(argc, argv, &prmtrs) == ERROR)
		return (ERROR);
	printf("HELLO\n");
	return (0);
}
