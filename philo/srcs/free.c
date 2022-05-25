/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:55:36 by naqua             #+#    #+#             */
/*   Updated: 2022/02/28 10:55:40 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_arg *args)
{
	free(args->tids);
	free(args->all_philos);
	free(args->forks);
}

void	stop_mutex(t_arg *args)
{
	int	nbr_ph;

	nbr_ph = args->nbr_philo;
	while (nbr_ph--)
	{
		pthread_mutex_unlock(&args->forks[nbr_ph]);
		pthread_mutex_destroy(&args->forks[nbr_ph]);
	}
	pthread_mutex_unlock(&(*args).lock_print);
	pthread_mutex_destroy(&(*args).lock_print);
}
