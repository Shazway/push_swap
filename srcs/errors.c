/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:57:08 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/28 01:41:36 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->alen == 0)
		return (0);
	while (i <= data->alen)
	{
		j = i;
		while (j <= data->alen)
		{
			if (data->a[i] == data->a[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_nb(char *str)
{
	long	nb;

	nb = ft_atoi(str);
	return (nb > 2147483647 || nb < -2147483648);
}

int	count_digits(char **argv, int j, int i)
{
	int	count;

	count = 0;
	while (argv[i][j] && (argv[i][j] >= '0' && argv[i][j] <= '9'))
	{
		j++;
		count++;
	}
	count++;
	return (count);
}

int	nb_limits(char *args)
{
	int	count;
	int	sign;
	int	i;

	count = 0;
	sign = 1;
	i = 0;
	while (args && args[i])
	{
		while (args[i] && args[i] == ' ')
			i++;
		if (check_nb(args + i))
			return (1);
		while (args[i] && args[i] != ' ')
			i++;
	}
	return (0);
}

int	errors_check(char *args, int argc, int i, t_data *data)
{
	if (i == 0)
	{
		if (argc <= 1)
			return (1);
		if (check_signs(args))
			return (1);
		if (are_there_numbers(args))
			return (1);
		if (nb_only(args))
			return (1);
		if (nb_limits(args))
			return (1);
	}
	else if (is_duplicate(data) == 1)
		return (1);
	return (0);
}
