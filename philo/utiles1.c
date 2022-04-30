/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:06:36 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/30 05:45:55 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(t_data *data, char *string, int philo_id)
{
	pthread_mutex_lock(&(data->print));
	if (!(data->die))
	{
		ft_putnbr_fd(get_time() - data->beginning_time, 1);
		ft_putchar_fd('\t', 1);
		ft_putnbr_fd((philo_id + 1), 1);
		ft_putchar_fd('\t', 1);
		ft_putstr_fd(string, 1);
		ft_putchar_fd('\n', 1);
	}
	pthread_mutex_unlock(&(data->print));
}

void	check_eat(t_data *data, t_philo *philo)
{
	int	index;

	index = 0;
	while (data->time_each_philo_must_eat != 0 && index < data->nbrofphilo
		&& philo[index].eat > data->time_each_philo_must_eat)
		index++;
	if (index == data->nbrofphilo)
		data->check_eat = 1;
}

void	check_death(t_data *data, t_philo *philo)
{
	int		index;

	while (!(data->check_eat))
	{
		index = 0;
		while ((index < data->nbrofphilo) && (!(data->die)))
		{
			pthread_mutex_lock(&(data->eating));
			if ((get_time() - philo[index].check_die_time) > data->time_to_die)
			{
				print_message(data, "\e[0;31mdied\e[0;37m", index);
				data->die = 1;
			}
			pthread_mutex_unlock(&(data->eating));
			index++;
		}
		if (data->die)
			break ;
		if (data->time_each_philo_must_eat > 0)
			check_eat(data, data->philo);
		usleep(1000);
	}
}

void	end(t_data *data, t_philo *philo)
{
	int	index;

	index = 0;
	while (index < data->nbrofphilo)
		pthread_join(philo[index++].thread_id, NULL);
	index = 0;
	while (index < data->nbrofphilo)
		pthread_mutex_destroy(&(data->forks[index++]));
	pthread_mutex_destroy(&(data->eating));
	pthread_mutex_destroy(&(data->print));
	free(data->philo);
	free(data->forks);
}
