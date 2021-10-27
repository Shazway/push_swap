/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:57:08 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/26 17:48:12 by tmoragli         ###   ########.fr       */
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

int	check_nb(char *str, int j, int count, int sign)
{
	long	nb;

	nb = ft_atoi(str, j, sign);
	if (nb == -2147483648)
		return (0);
	if (nb < 0)
		nb *= -1;
	if (nb > 2147483647 || count > 10)
		return (1);
	return (0);
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

int	nb_limits(char **argv, int sign, int i, int j)
{
	int	count;

	while (argv[i])
	{
		j = 0;
		count = 0;
		sign = 1;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
			{
				sign *= -1;
				j = increm_j(argv, i, j);
			}
			count = count_digits(argv, j, i);
			if (count > 0)
				break ;
			j++;
		}
		if (count >= 10)
			if (check_nb(argv[i], j, count - 1, sign))
				return (1);
		i++;
	}
	return (0);
}

int	errors_check(char **argv, int argc, int i, t_data *data)
{
	if (i == 0)
	{
		if (argc <= 1)
			return (1);
		if (check_signs(argv))
			return (1);
		if (are_there_numbers(argv))
			return (1);
		if (nb_only(argv))
			return (1);
		if (nb_limits(argv, 1, 1, 0))
			return (1);
	}
	else if (is_duplicate(data) == 1)
		return (1);
	return (0);
}
