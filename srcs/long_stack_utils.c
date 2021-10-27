/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:42:47 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 18:48:08 by krain            ###   ########.fr       */
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

int	next_chunk(t_data *data)
{
	data->start_chunk = data->start_chunk + data->chunk_size;
	data->end_chunk = data->chunk_size + data->end_chunk;
	return (data->chunk_size);
}
