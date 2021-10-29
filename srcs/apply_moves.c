/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:33:47 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/29 16:57:46 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_operations(t_move *a, t_move *b, int i)
{
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
}

void	apply_left_moves(t_data *data, t_move *a, t_move *b)
{
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
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	apply_right_moves(t_data *data, t_move *a, t_move *b)
{
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
}

void	reset_moves(t_move *a, t_move *b)
{
	a->right_i = 0;
	b->right_i = 0;
	a->left_i = 0;
	b->left_i = 0;
}
