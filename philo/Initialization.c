/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 02:53:04 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/30 05:41:51 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_struct_philo(t_data *data)
{
	int	index;

	index = 0;
	data->philo = malloc(sizeof(t_data) * data->nbrofphilo);
	if (!data->philo)
		return (1);
	while (index < data->nbrofphilo)
	{
		data->philo[index].id = index;
		data->philo[index].l_f = index;
		data->philo[index].r_f = (index + 1) % data->nbrofphilo;
		data->philo[index].check_die_time = 0;
		data->philo[index].eat = 0;
		data->philo[index].data = data;
		index++;
	}
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int	index;

	index = 0;
	if (pthread_mutex_init(&(data->eating), NULL))
		return (1);
	if (pthread_mutex_init(&(data->print), NULL))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbrofphilo);
	if (!(data->forks))
		return (1);
	while (index < data->nbrofphilo)
	{
		if (pthread_mutex_init(&(data->forks[index]), NULL))
			return (1);
		index++;
	}
	return (0);
}

int	initialization(t_data *data, int argc, char **argv)
{
	data->nbrofphilo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->beginning_time = 0;
	data->die = 0;
	data->check_eat = 0;
	data->time_each_philo_must_eat = 0;
	if (argc == 6)
		data->time_each_philo_must_eat = ft_atoi(argv[5]);
	if (ft_init_mutex(data) || ft_init_struct_philo(data))
		return (write(2, "initialization failed\n", 22), 1);
	return (0);
}
