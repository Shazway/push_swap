/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:12:50 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/23 11:28:33 by tmoragli         ###   ########.fr       */
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
	data->operations++;
}

void	sb(t_data *data, int pr)
{
	int	temp;

	if (data->blen < 1)
		return ;
	temp = data->b[data->blen];
	data->b[data->blen] = data->b[data->blen - 1];
	data->b[data->blen - 1] = temp;
	if (pr != 0 && data->print)
		write(1, "sb\n", 3);
	data->operations++;
}

void	rb(t_data *data, int pr)
{
	int	temp;
	int	i;

	i = data->blen - 1;
	if (data->blen < 1)
		return ;
	temp = data->b[data->blen];
	while (i >= 0)
	{
		data->b[i + 1] = data->b[i];
		i--;
	}
	data->b[0] = temp;
	if (pr != 0 && data->print)
		write(1, "rb\n", 3);
	data->operations++;
}

void	rrb(t_data *data, int pr)
{
	int	temp;
	int	i;

	i = 0;
	temp = data->b[0];
	if (data->blen < 1)
		return ;
	while (i < data->blen)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
	data->b[data->blen] = temp;
	if (pr != 0 && data->print)
		write(1, "rrb\n", 4);
	data->operations++;
}