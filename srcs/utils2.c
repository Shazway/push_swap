/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:32:34 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 23:18:26 by magostin         ###   ########.fr       */
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

void	fill_tabs(char *args, t_data *data)
{
	int		i;
	int		j;

	j = -1;
	i = 0;
	while (args && args[i])
	{
		while (args[i] && args[i] == ' ')
			i++;
		if (!args[i])
			break ;
		fill(data, ++j, ft_atoi(args + i));
		while (args[i] && args[i] != ' ')
			i++;
	}
}
