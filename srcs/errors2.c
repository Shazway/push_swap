/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:15:41 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 23:17:29 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_only(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if ((args[i] < '0'
			|| args[i] > '9') && args[i] != ' ' && args[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	increm_j(char **argv, int i, int j)
{
	while (argv[i][j] && argv[i][j] == '-')
		j++;
	return (j);
}

int	check_signs(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '-')
			if (args[i + 1] < '0' || args[i + 1] > '9')
				return (1);
		i++;
	}
	return (0);
}

int	are_there_numbers(char *args)
{
	int	i;
	int	is_nb;

	i = 0;
	is_nb = 1;
	while (args[i])
	{
		if (args[i] >= '0' && args[i] <= '9')
			is_nb = 0;
		i++;
	}
	return (is_nb);
}
