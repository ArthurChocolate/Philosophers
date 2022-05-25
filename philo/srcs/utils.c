/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:59:21 by naqua             #+#    #+#             */
/*   Updated: 2022/02/28 12:50:27 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (time);
}

void	ft_usleep(int ms)
{
	long	time;

	time = ft_time();
	usleep(ms * 920);
	while (ft_time() < time + ms)
		usleep(ms * 3);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str == '\t' || *str == '\r' || *str == '\n'
		|| *str == ' ' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		negative *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * negative);
}

int	ft_is_digit(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
