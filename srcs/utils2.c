/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:32:34 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/26 17:51:15 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_sorted(t_data *data)
{
	int	i;

	i = data->alen;
	while (i > 0 && data->a[i] < data->a[i - 1])
		i--;
	if (i == 0)
		return (0);
	return (1);
}

void	ft_free(t_data *data)
{
	free(data->a);
	free(data->b);
	free(data->c);
	free(data);
}

int	smallest_in_a(t_data *data)
{
	int	i;
	int	temp;

	i = 0;
	temp = data->a[0];
	while (i <= data->alen)
	{
		if (temp > data->a[i])
			temp = data->a[i];
		i++;
	}
	return (temp);
}

int	fill(t_data *data, int k, int i)
{
	if (data->alen >= 0)
	{
		data->a[k] = i;
		data->c[k] = data->a[k];
	}
	return (1);
}

void	fill_tabs(char **argv, t_data *data, int i, int j)
{
	int	k;
	int	sign;

	sign = 1;
	k = 0;
	while (i >= 1)
	{
		if (i == -1)
			break ;
		j = ft_strlen(argv[i]);
		while (j >= 0)
		{
			j = decrem_j(argv, i, j);
			if (argv[i][j] == '-')
				sign *= -1;
			sign = fill(data, k, ft_atoi(argv[i], j, sign));
			k++;
			if (j <= 0)
				break ;
			j--;
			while (j > 0 && (argv[i][j] == ' ' || argv[i][j] == '-'))
				j--;
		}
		i--;
	}
}
