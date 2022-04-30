/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 03:02:34 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/30 05:45:22 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->eating));
	print_message(data, "is eating 🍝", philo->id);
	philo->check_die_time = get_time();
	pthread_mutex_unlock(&(data->eating));
	(philo->eat)++;
	usleep(data->time_to_eat * 1000);
}

int	taking_fork(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->l_f]));
	print_message(data, "has taken a fork 🍴", philo->id);
	pthread_mutex_lock(&(data->forks[philo->r_f]));
	print_message(data, "has taken a fork 🍴", philo->id);
	start_eat(philo->data, philo);
	pthread_mutex_unlock(&(data->forks[philo->l_f]));
	pthread_mutex_unlock(&(data->forks[philo->r_f]));
	if (data->check_eat)
		return (1);
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*copy_of_philo;
	t_data	*data;

	copy_of_philo = (t_philo *)philo;
	data = copy_of_philo->data;
	if (data->nbrofphilo == 1)
	{
		print_message(data, "has taken a fork 🍴", copy_of_philo->id);
		usleep(data->time_to_die * 1000);
		return (NULL);
	}
	if (copy_of_philo->id % 2)
		usleep(10000);
	while (!(data->die))
	{
		if (taking_fork(data, copy_of_philo))
			break ;
		print_message(data, "is sleeping 💤", copy_of_philo->id);
		usleep(data->time_to_sleep * 1000);
		print_message(data, "is thinking 🤔", copy_of_philo->id);
	}
	return (NULL);
}
