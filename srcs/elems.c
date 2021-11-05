/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:51:53 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/28 01:41:30 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elems(t_data *data)
{
	if (data->a[0] > data->a[1] && data->a[0] > data->a[2]
		&& data->a[1] < data->a[2])
		sa(data, 1);
	if (data->a[0] < data->a[1] && data->a[0] < data->a[2]
		&& data->a[1] < data->a[2])
	{	
		sa(data, 1);
		rra(data, 1);
	}
	if (data->a[0] > data->a[1] && data->a[0] < data->a[2]
		&& data->a[1] < data->a[2])
		ra(data, 1);
	if (data->a[0] < data->a[1] && data->a[0] > data->a[2]
		&& data->a[1] > data->a[2])
	{
		sa(data, 1);
		ra(data, 1);
	}
	if (data->a[0] < data->a[1] && data->a[0] < data->a[2]
		&& data->a[1] > data->a[2])
		rra(data, 1);
}

void	four_or_five_elems(t_data *data)
{
	int		highest;

	while (data->blen >= 0)
	{
		best_move_for_a(data);
		pa(data);
	}
	highest = find_max_index(data->a, data->alen);
	apply_best_move_a(data, highest);
}
