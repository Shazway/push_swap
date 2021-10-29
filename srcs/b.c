/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:46:03 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/30 01:14:55 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(int *stack, int len)
{
	int		i;
	int		ret;
	int		max;

	i = -1;
	max = -2147483648;
	while (++i <= len)
	{
		if (max < stack[i])
		{
			ret = i;
			max = stack[i];
		}
	}
	return (ret);
}

int	check_b_insert(t_data *data, int index)
{
	int		prev;

	prev = index + 1;
	if (index == data->blen)
		prev = 0;
	if (data->b[index] <= data->a[data->a_move->i]
		&& data->b[prev] >= data->a[data->a_move->i])
		return (1);
	return (0);
}

void	best_move_b(t_data *data)
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
	data->b_move->left_i = i;
	data->b_move->right_i = data->blen - i + 1;
}

void	best_move_a(t_data *data, int top_scan, int bottom_scan)
{
	if (data->alen - top_scan < bottom_scan + 1)
	{
		data->a_move->left_i = top_scan + 1;
		data->a_move->right_i = data->alen - top_scan;
		data->a_move->i = top_scan;
	}
	else
	{
		data->a_move->left_i = bottom_scan + 1;
		data->a_move->right_i = data->alen - bottom_scan;
		data->a_move->i = bottom_scan;
	}
}

void	apply_moves(t_data *data)
{
	int		operations[4];
	t_move	*a;
	t_move	*b;

	a = data->a_move;
	b = data->b_move;
	operations[0] = ft_max(a->left_i, b->left_i);
	operations[1] = ft_max(a->right_i, b->right_i);
	operations[2] = a->left_i + b->right_i;
	operations[3] = a->right_i + b->left_i;
	best_operations(a, b, min_ope(operations));
	apply_left_moves(data, a, b);
	apply_right_moves(data, a, b);
	reset_moves(a, b);
}
