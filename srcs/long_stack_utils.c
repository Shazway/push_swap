/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:42:47 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 17:19:28 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_nb_to_top(t_data *data, int top_scan, int bottom_scan)
{
	if (top_scan != 0 && data->alen - bottom_scan < top_scan + 1)
	{
		while (top_scan < data->alen)
		{	
			ra(data, 1);
			top_scan++;
		}
	}
	if (data->alen - bottom_scan > top_scan + 1)
	{
		while (bottom_scan >= 0)
		{
			rra(data, 1);
			bottom_scan--;
		}
	}
	if (data->alen - bottom_scan == top_scan + 1)
	{
		while (bottom_scan >= 0)
		{
			rra(data, 1);
			bottom_scan--;
		}
	}
}

int	test_rb_s(t_data *data, int nb_rb)
{
	int	i;

	i = 0;
	while (data->blen > 0
		&& !((data->a[data->alen] < data->b[data->blen]
				&& data->b[data->blen] > data->b[0])))
	{
		rb(data, 0);
		i++;
	}
	nb_rb = i;
	while (i >= 0)
	{
		rrb(data, 0);
		i--;
	}
	return (nb_rb);
}

int	test_rb_b(t_data *data, int nb_rb)
{
	int	i;

	i = 0;
	while (data->blen > 0
		&& !(data->a[data->alen] > data->b[data->blen]
			&& data->b[data->blen] > data->b[0]))
	{
		rb(data, 0);
		i++;
	}
	nb_rb = i;
	while (i >= 0)
	{
		rrb(data, 0);
		i--;
	}
	return (nb_rb);
}

int	test_rb_m(t_data *data, int nb_rb)
{
	int	i;

	i = 0;
	while (data->blen > 0
		&& !(data->b[data->blen] < data->a[data->alen]
			&& data->a[data->alen] < data->b[0]))
	{
		rb(data, 0);
		i++;
	}
	nb_rb = i;
	while (i >= 0)
	{
		rrb(data, 0);
		i--;
	}
	return (nb_rb);
}

int	next_chunk(t_data *data)
{
	data->start_chunk = data->start_chunk + data->chunk_size;
	data->end_chunk = data->chunk_size + data->end_chunk;
	return (data->chunk_size);
}
