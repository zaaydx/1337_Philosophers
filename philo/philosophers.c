/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:06:17 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/26 18:06:18 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    t_arguments     *args;

    args = (t_arguments *)malloc(sizeof(t_arguments));
    if (!check_input(argc, argv, args))
    {
        free(args);
        return (1);
    }
    return (0);
}