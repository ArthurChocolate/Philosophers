/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:59:59 by naqua             #+#    #+#             */
/*   Updated: 2022/02/28 12:04:15 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_1(t_philo *philo)
{
	pthread_mutex_lock(philo->l_f);
	pthread_mutex_lock(philo->r_f);
	pthread_mutex_lock(&philo->lock_print);
	if (philo->stop != 1)
	{
		printf(GREEN FORK DEF, ft_time() - philo->start_time,
			philo->philo_id + 1);
		printf(GREEN FORK DEF, ft_time() - philo->start_time,
			philo->philo_id + 1);
	}
	pthread_mutex_lock(&philo->lock_print);
}

void	forks_2(t_philo *philo)
{
	if (philo->philo_id % 2 == 0 && philo->philo_id + 1 != philo->nbr_philo)
	{
		pthread_mutex_lock(philo->r_f);
		pthread_mutex_lock(philo->l_f);
		pthread_mutex_lock(&philo->lock_print);
		if (philo->stop != 1)
		{
			printf(GREEN FORK DEF, ft_time() - philo->start_time,
				philo->philo_id + 1);
			printf(GREEN FORK DEF, ft_time() - philo->start_time,
				philo->philo_id + 1);
		}
		pthread_mutex_unlock(&philo->lock_print);
	}
	else
		forks_1(philo);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf(YELLOW EAT DEF, ft_time() - philo->start_time,
		philo->philo_id + 1);
	pthread_mutex_unlock(&philo->lock_print);
	philo->nbr_of_meals += 1;
	philo->time_of_last_meal = ft_time();
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_f);
	pthread_mutex_unlock(philo->r_f);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf(PURPLE SLEEP DEF, ft_time() - philo->start_time,
		philo->philo_id + 1);
	pthread_mutex_unlock(&philo->lock_print);
	ft_usleep(philo->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_print);
	printf(CYAN THINK DEF, ft_time() - philo->start_time,
		philo->philo_id + 1);
	pthread_mutex_unlock(&philo->lock_print);
}
