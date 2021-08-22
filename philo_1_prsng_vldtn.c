/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_1_prsng_vldtn.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 21:34:40 by bhatches          #+#    #+#             */
/*   Updated: 2021/08/19 22:20:03 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	vldtn_1(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: argc is not correct\n");
		return (ERROR);
	}
	if (vldthn_chech_str_is_digits(argv[1]) == false
		|| vldthn_chech_str_is_digits(argv[2]) == false
		|| vldthn_chech_str_is_digits(argv[3]) == false
		|| vldthn_chech_str_is_digits(argv[4]) == false)
	{
		printf("Error: your argv_i is not digit or less than 0\n");
		return (ERROR);
	}
	return (0);
}

int	vldtn_2(t_prsng_strct *prsngStrct)
{
	if (prsngStrct->nb_philo <= 0
		|| prsngStrct->time_die < 0
		|| prsngStrct->time_eat < 0
		|| prsngStrct->time_sleep < 0)
	{
		printf("Error: your argv_i is equal or less than zero\n");
		return (ERROR);
	}
	return (0);
}

int	vldtn_3(int argc, char **argv, t_prsng_strct *prsngStrct)
{
	if (argc == 6)
	{
		if (vldthn_chech_str_is_digits(argv[5]) == false)
		{
			printf("Error: your argv_6 is not digit\n");
			return (ERROR);
		}
		prsngStrct->nb_meals = ft_atoi(argv[5]);
		if (prsngStrct->nb_meals < 0)
		{
			printf("Error: your argv_6 is less than zero\n");
			return (ERROR);
		}
	}
	else
		prsngStrct->nb_meals = -1;
	return (0);
}

int	prsng_vldtn(int argc, char **argv, t_prsng_strct *prsngStrct)
{
	if (vldtn_1(argc, argv) == ERROR)
		return (ERROR);
	prsngStrct->nb_philo = ft_atoi(argv[1]);
	prsngStrct->time_die = ft_atoi(argv[2]);
	prsngStrct->time_eat = ft_atoi(argv[3]);
	prsngStrct->time_sleep = ft_atoi(argv[4]);
	if (vldtn_2(prsngStrct) == ERROR)
		return (ERROR);
	if (vldtn_3(argc, argv, prsngStrct) == ERROR)
		return (ERROR);
	return (0);
}
