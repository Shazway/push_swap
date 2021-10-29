/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:48:59 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/28 23:40:47 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bot_scan(t_data *data)
{
	int	bottom_scan;

	bottom_scan = 0;
	while (bottom_scan < data->alen)
	{
		if (data->a[bottom_scan] >= data->c[data->start_chunk]
		&& data->a[bottom_scan] <= data->c[data->end_chunk])
				return (bottom_scan);
		bottom_scan++;
	}
	return (bottom_scan);
}

int	roof_scan(t_data *data)
{
	int	top_scan;

	top_scan = data->alen;
	while (top_scan > 0)
	{
		if (data->a[top_scan] >= data->c[data->start_chunk]
		&& data->a[top_scan] <= data->c[data->end_chunk])
				return (top_scan);
		top_scan--;
	}
	return (top_scan);
}
