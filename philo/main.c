/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 03:01:52 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/30 05:43:16 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_arguments(argc, argv) == 1)
		return (write(2, "incorrect arguments\n", 21), 1);
	if (initialization(&data, argc, argv) == 1)
		return (1);
	if (creat_thread(&data, (&data)->philo) == 1)
		return (1);
	return (0);
}
