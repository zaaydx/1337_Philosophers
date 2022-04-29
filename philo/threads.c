/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:06:29 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/28 21:43:46 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h" 

int	creat_thread(t_data *data, t_philo *philo)
{
	int	index;

	index = 0;
	data->beginning_time = get_time();
	while (index < data->nbrofphilo)
	{
		philo[index].check_die_time = get_time();
		if (pthread_create(&data->philo[index].thread_id,
				NULL, routine, (void *)&(philo[index])))
			return (write(2, "threads failed\n", 15), 1);
		index++;
	}
	check_death(data, data->philo);
	end(data, data->philo);
	return (0);
}