/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:12:34 by krain             #+#    #+#             */
/*   Updated: 2021/10/28 01:41:23 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_best_move_a(t_data *data, int i)
{
	void	(*move)(t_data *, int);

	if (i > data->alen / 2)
	{
		move = &ra;
		i = data->alen - i + 1;
	}
	else
		move = &rra;
	while (i > 0)
	{
		move(data, 1);
		i--;
	}
}

int	check_a_insert(t_data *data, int index)
{
	int		prev;

	prev = index + 1;
	if (index == data->alen)
		prev = 0;
	if (data->a[index] > data->b[data->blen]
		&& data->a[prev] < data->b[data->blen])
		return (1);
	return (0);
}

void	best_move_for_a(t_data *data)
{
	int		i;

	if (data->alen <= 0)
		return ;
	i = -1;
	while (++i <= data->alen)
		if (check_a_insert(data, i))
			break ;
	if (i == data->alen + 1)
		i = find_max_index(data->a, data->alen);
	else
		i++;
	apply_best_move_a(data, i);
}
