/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:14:15 by bhatches          #+#    #+#             */
/*   Updated: 2021/08/19 23:44:52 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_prsng_strct	prsngStrct;
	t_main_strct	mainStrct;

	if (prsng_vldtn(argc, argv, &prsngStrct) == ERROR)
		return (ERROR);
	if (init_main_strct(&prsngStrct, &mainStrct) == ERROR)
		return (ERROR);
	if (create_threads(&mainStrct, prsngStrct.nb_philo) == ERROR)
		return (ERROR);
	free_resources(&mainStrct, prsngStrct.nb_philo);
	return (0);
}
