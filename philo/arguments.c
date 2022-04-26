/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:06:07 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/26 18:06:11 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void store_values(int *arg, int argc, t_arguments *args)
{
    args->nb_of_philo = arg[0];
    args->time_to_die = arg[1];
    args->time_to_eat = arg[2];
    args->time_to_sleep = arg[3];
    if (argc == 6)
        args->nb_must_eat = arg[4];
    else
        args->nb_must_eat = 0;
}

int check_values(int *arg, int argc)
{
    if (!ft_ispositive(arg, argc - 1))
    {
        printf("\033[0;33mIncorrect value of arguments\n");
        return(0);
    }
    return(1);
}

int check_input(int argc, char **argv, t_arguments *args)
{
    int *arg;
    int i;
    int j;

    i = 0;
    j = 0;
    if (argc < 5 || argc > 6)
        printf("\033[0;33mIncorrect number of arguments\n");
    else if (!is_digits(argv, argc))
        printf("\033[0;33mIncorrect type of arguments\n");
    else
    {
        arg = (int *)malloc(sizeof(int) * argc - 1);
        while (++i < argc)
            arg[j++] = ft_atoi(argv[i]);
        if (!check_values(arg, argc))
        {
            free(arg);
            return (0);
        }
        store_values(arg, argc, args);
        free(arg);
        return (1);
    }
    return (0);
}