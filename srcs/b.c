/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:12:34 by krain             #+#    #+#             */
/*   Updated: 2021/10/29 01:16:23 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	//printf("Trying to push %d on b with %d or %d moves\n", data->a[data->a_move->i], data->b_move->left_i, data->b_move->right_i);
	//print_stacks(data);
}


void	best_move_a(t_data *data, int top_scan, int bottom_scan)
{
	if (data->alen - top_scan < bottom_scan + 1)
	{
		data->a_move->left_i = top_scan + 1;
		data->a_move->right_i = data->alen - top_scan;
		data->a_move->i = top_scan;
		//printf("top_scan found %d, need %d< or %d> moves\n", data->a[top_scan], data->a_move->left_i, data->a_move->right_i);
	}
	else
	{
		data->a_move->left_i = bottom_scan + 1;
		data->a_move->right_i = data->alen - bottom_scan;
		data->a_move->i = bottom_scan;
		//printf("bottom_scan found %d, need %d< or %d> moves\n", data->a[bottom_scan], data->a_move->left_i, data->a_move->right_i);
	}
}

int		ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int		min_ope(int ope[4])
{
	int		i;
	int		i_min;
	int		min;

	i = -1;
	i_min = 0;
	min = -1;
	while (++i < 4)
	{
		if (min == -1 || ope[i] < min)
		{
			min = ope[i];
			i_min = i;
		}
	}
	return (i_min);
}

void	apply_moves(t_data *data)
{
	int		operations[4];
	int		i;
	t_move	*a;
	t_move	*b;

	a = data->a_move;
	b = data->b_move;
	operations[0] = ft_max(a->left_i, b->left_i);
	operations[1] = ft_max(a->right_i, b->right_i);
	operations[2] = a->left_i + b->right_i;
	operations[3] = a->right_i + b->left_i;
	i = min_ope(operations);
	if (i == 0)
	{
		a->right_i = 0;
		b->right_i = 0;
	}
	else if (i == 1)
	{
		a->left_i = 0;
		b->left_i = 0;
	}
	else if (i == 2)
	{
		a->right_i = 0;
		b->left_i = 0;
	}
	else if (i == 3)
	{
		a->left_i = 0;
		b->right_i = 0;
	}
	while (a->left_i > 0 || b->left_i > 0)
	{
		if (a->left_i > 0 && b->left_i > 0)
			rrr(data);
		else
		{
			if (a->left_i > 0)
				rra(data, 1);
			if (b->left_i > 0)
				rrb(data, 1);
		}
		a->left_i--;
		b->left_i--;
	}
	while (a->right_i > 0 || b->right_i > 0)
	{
		if (a->right_i > 0 && b->right_i > 0)
			rr(data);
		else
		{
			if (a->right_i > 0)
				ra(data, 1);
			if (b->right_i > 0)
				rb(data, 1);
		}
		a->right_i--;
		b->right_i--;
	}
	a->right_i = 0;
	b->right_i = 0;
	a->left_i = 0;
	b->left_i = 0;
}