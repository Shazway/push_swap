/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:12:34 by krain             #+#    #+#             */
/*   Updated: 2021/10/28 01:32:23 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_best_move(t_data *data, int i)
{
	void	(*move)(t_data *, int);

	if (i > data->blen / 2)
	{
		move = &rb;
		i = data->blen - i + 1;
	}
	else
		move = &rrb;
	while (i > 0)
	{
		move(data, 1);
		i--;
	}
}

int	find_max_index(int *stack, int len)
{
	int		i;
	int		ret;
	int		max;

	i = -1;
	max = -1;
	while (++i <= len)
	{
		if (max == -1 || max < stack[i])
		{
			ret = i;
			max = stack[i];
		}
	}
	return (ret);
}

int	highest_b(t_data *data)
{
	int		i;
	int		b_max;

	b_max = find_max_index(data->b, data->blen);
	i = 0;
	while (data->b[i] != data->b[b_max])
		i++;
	if (i != data->blen)
		i++;
	else
		i = 0;
	return (i);
}

int	check_b_insert(t_data *data, int index)
{
	int		prev;

	prev = index + 1;
	if (index == data->blen)
		prev = 0;
	if (data->b[index] < data->a[data->alen]
		&& data->b[prev] > data->a[data->alen])
		return (1);
	return (0);
}

void	best_move_for_b(t_data *data)
{
	int		i;

	if (data->blen <= 0)
		return ;
	i = data->blen + 1;
	while (--i >= 0)
		if (check_b_insert(data, i))
			break ;
	if (i == -1)
		i = highest_b(data);
	else
		i++;
	apply_best_move(data, i);
}
