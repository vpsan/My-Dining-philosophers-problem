/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2_vldtn_isdigits.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:23:49 by bhatches          #+#    #+#             */
/*   Updated: 2021/08/19 22:20:16 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int value)
{
	if (value >= '0' && value <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

bool	vldthn_chech_str_is_digits(char *str)
{
	int	j;
	int	exit_flag;

	j = 0;
	exit_flag = 0;
	while (str[j] != '\0')
	{
		if (ft_isdigit(str[j]) == false)
			exit_flag = 1;
		j++;
	}
	if (exit_flag == 1)
		return (false);
	return (true);
}
