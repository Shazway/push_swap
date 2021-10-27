/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:48:59 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/23 13:03:56 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bot_scan(t_data *data, int i)
{
	int	bottom_scan;

	bottom_scan = 0;
	while (bottom_scan <= data->alen)
	{
		i = data->start_chunk;
		while (i < data->end_chunk
			&& data->a[bottom_scan] != data->c[i])
			i++;
		if (data->a[bottom_scan] == data->c[i])
			break ;
		bottom_scan++;
	}
	return (bottom_scan);
}

int	roof_scan(t_data *data, int i)
{
	int	top_scan;

	top_scan = data->alen;
	while (top_scan > 0)
	{
		i = data->start_chunk;
		while (i < data->end_chunk && data->a[top_scan] != data->c[i])
			i++;
		if (data->a[top_scan] == data->c[i])
			break ;
		top_scan--;
	}
	return (top_scan);
}
