/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:53:58 by naqua             #+#    #+#             */
/*   Updated: 2022/02/28 11:52:35 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_validation(int argc, char **argv)
{
	size_t	i;

	if (argc < 5 || argc > 6)
	{
		printf(RED NBR ENTER DEF);
		printf(ONE TWO THREE FOUR FIVE GREEN USE DEF);
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		if (!ft_is_digit(argv[i]) || !ft_atoi(argv[i]))
		{
			printf(RED INV DEF);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_arg	args;

	if (ft_validation(argc, argv))
		return (1);
	if (ft_init_args(&args, argc, argv) == 1)
		return (1);
	ft_init_mutex(&args);
	ft_init_philo(&args);
	ft_init_threads(&args);
	ft_end_threads(&args);
	stop_mutex(&args);
	ft_free(&args);
	return (0);
}
