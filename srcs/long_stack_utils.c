/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:53:48 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/30 00:21:06 by tmoragli         ###   ########.fr       */
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
	else if (data->alen - bottom_scan >= top_scan + 1)
	{
		while (bottom_scan >= 0)
		{
			rra(data, 1);
			bottom_scan--;
		}
	}
}

int	next_chunk(t_data *data)
{
	data->start_chunk = data->start_chunk + data->chunk_size;
	data->end_chunk = data->chunk_size + data->end_chunk;
	if (data->end_chunk > data->clen)
		data->end_chunk = data->clen;
	return (data->chunk_size);
}
