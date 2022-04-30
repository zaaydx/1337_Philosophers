/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:06:25 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/30 05:47:28 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	int				l_f;
	int				r_f;
	long long		check_die_time;
	int				eat;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	print;
	int				nbrofphilo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_each_philo_must_eat;
	int				die;
	int				check_eat;
	long long		beginning_time;
	t_philo			*philo;
}				t_data;

/* philosophers.c FILE */
void		*routine(void *philo);

/* utiles1.c FILE */
long long	get_time(void);
void		print_message(t_data *data, char *string, int philo_id);
void		check_death(t_data *data, t_philo *philo);
void		end(t_data *data, t_philo *philo);

/* utiles2.c FILE */
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);

/* threads.c FILE */
int			creat_thread(t_data *data, t_philo *philo);

/* Initialization FILE */
int			initialization(t_data *data, int ac, char **av);

/* arguments.c FILE */
int			check_arguments(int argc, char **argv);

#endif
