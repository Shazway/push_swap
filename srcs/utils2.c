/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:06:19 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/29 17:11:14 by tmoragli         ###   ########.fr       */
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

void	ft_free(t_data *data, char *args, int i)
{
	if (i)
		free(args);
	free(data->a);
	free(data->b);
	free(data->c);
	free(data->a_move);
	free(data->b_move);
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

void	fill_tabs(char *args, t_data *data)
{
	int		i;
	int		j;

	j = data->alen + 1;
	i = 0;
	while (args && args[i])
	{
		while (args[i] && args[i] == ' ')
			i++;
		if (!args[i])
			break ;
		fill(data, --j, ft_atoi(args + i));
		while (args[i] && args[i] != ' ')
			i++;
	}
}
