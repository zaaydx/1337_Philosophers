/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:06:07 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/30 05:41:32 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57) && c != '-' && c != '+')
		return (0);
	else
		return (1);
}

int	check_if_digit(char **list)
{
	int	i;
	int	j;

	i = 1;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			if (ft_isdigit(list[i][j]) == 0 || (ft_isdigit(list[i][j]) == 1
						&& (list[i][j + 1] == '-' || list[i][j + 1] == '+')))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if ((argc > 6) || (argc < 5))
		return (1);
	if (check_if_digit(argv) == 1)
		return (1);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (1);
		if (ft_atoi(argv[i]) <= 0)
			return (1);
		i++;
	}
	return (0);
}
