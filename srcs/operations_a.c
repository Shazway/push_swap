/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 00:08:30 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/28 16:38:51 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	if (data->blen == -1)
		return ;
	data->alen++;
	data->a[data->alen] = data->b[data->blen];
	data->blen--;
	if (data->print)
		write(1, "pa\n", 3);
}

void	ra(t_data *data, int pr)
{
	int	temp;
	int	i;

	i = data->alen - 1;
	if (data->alen < 1)
		return ;
	temp = data->a[data->alen];
	while (i >= 0)
	{
		data->a[i + 1] = data->a[i];
		i--;
	}
	data->a[0] = temp;
	if (pr != 0 && data->print)
		write(1, "ra\n", 3);
}

void	rra(t_data *data, int pr)
{
	int	temp;
	int	i;

	i = 0;
	temp = data->a[0];
	if (data->alen < 1)
		return ;
	while (i < data->alen)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	data->a[data->alen] = temp;
	if (pr != 0 && data->print)
		write(1, "rra\n", 4);
}

void	sa(t_data *data, int pr)
{
	int	temp;

	if (data->alen < 1)
		return ;
	temp = data->a[data->alen];
	data->a[data->alen] = data->a[data->alen - 1];
	data->a[data->alen - 1] = temp;
	if (pr != 0 && data->print)
		write(1, "sa\n", 3);
}
