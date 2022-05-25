/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:54:33 by naqua             #+#    #+#             */
/*   Updated: 2022/02/28 14:59:15 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

/*
*	errors def
*/

# define NBR	"\n\t\tWrong number of arguments\n"
# define ENTER	"\t\tPlease enter 4 or 5 arguments\n\n"
# define ONE	"1) Numbers of philosophers\n"
# define TWO	"2) Time to die\n"
# define THREE	"3) Time to eat\n"
# define FOUR	"4) Time to sleep\n"
# define FIVE	"5) Number of meals (optional)\n\n"
# define INV	"Invalid argument\n"
# define USE	"usage: ./philo <nbr of philo> <time to die> <time to eat> \
<time to sleep> <number of meals>\n"

/*
*	colors def
*/

# define DEF	"\033[0m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define PURPLE	"\033[0;35m"
# define YELLOW	"\033[0;33m"
# define CYAN	"\033[0;36m"

/*
*	actions def
*/

# define SLEEP	"%ld %d is sleeping\n"
# define FORK	"%ld %d has taken a fork\n"
# define EAT	"%ld %d is eating\n"
# define DIED	"%ld %d died\n"
# define THINK	"%ld %d is thinking\n"

typedef struct s_philo
{
	int					philo_id;
	int					nbr_of_meals;
	int					nbr_of_meals_1;
	time_t				time_of_last_meal;
	int					nbr_philo;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	time_t				limit_of_life;
	int					stop;
	time_t				start_time;
	pthread_mutex_t		lock_print;
	pthread_mutex_t		*l_f;
	pthread_mutex_t		*r_f;
	struct s_arg		*arg;
}	t_philo;

/*
*	argument processing
*/

typedef struct s_arg
{
	int					nbr_philo;
	int					philo_id;
	time_t				start_time;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					dead;
	int					nbr_of_meals;
	pthread_mutex_t		*forks;
	pthread_t			*tids;
	pthread_mutex_t		lock_print;
	t_philo				*all_philos;
}	t_arg;

/*
*	init
*/

void	ft_init_philo(t_arg *args);
void	ft_init_threads(t_arg *args);
void	ft_init_mutex(t_arg *args);
void	ft_end_threads(t_arg *args);
int		ft_init_args(t_arg *args, int argc, char **argv);

/*
*	process
*/

int		ft_cnt_of_meals(t_philo *philo);
void	died_philo(t_philo *philo, int i);
void	*ft_monitor(void *args);
void	*ft_process(void *args);

/*
*	actions
*/

void	forks_1(t_philo *philo);
void	forks_2(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

/*
*	free
*/

void	ft_free(t_arg *args);
void	stop_mutex(t_arg *args);

/*
*	utils
*/

long	ft_time(void);
void	ft_usleep(int ms);
int		ft_atoi(const char *str);
int		ft_is_digit(char *str);

#endif
