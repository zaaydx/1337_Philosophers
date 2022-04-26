/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:06:25 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/26 18:06:26 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_arguments
{
    int             nb_of_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             nb_must_eat;
    int             start_time;

}   t_arguments;

typedef struct s_philosophers
{
    int             id;

}   t_philosophers;

/* utiles1.c FILE */
int	ft_ispositive(int *s, int n);
int	ft_atoi(const char *str);
int	is_digits(char **argv, int c);

/* utiles2.c FILE */
int ft_gettime(void);

/* threads.c FILE */
void print_statut(t_philosophers *philo, char *moves);

/* arguments.c FILE */
int check_input(int argc, char **argv, t_arguments *args);

#endif