/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:15:41 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/26 17:49:25 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_only(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < '0'
				|| str[i][j] > '9') && str[i][j] != ' ' && str[i][j] != '-')
				return (1);
			j++;
		}
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

int	check_signs(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				if (argv[i][j + 1] <= '0' || argv[i][j + 1] >= '9')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	are_there_numbers(char **argv)
{
	int	i;
	int	j;
	int	is_nb;

	i = 0;
	is_nb = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				is_nb = 0;
			j++;
		}
		i++;
	}
	return (is_nb);
}
