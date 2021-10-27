/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:48:00 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 17:21:37 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_move_smallest(t_data *data)
{
	if (test_s(data) == 1)
		while ((data->blen > 0)
			&& !((data->a[data->alen] < data->b[data->blen]
					&& data->b[data->blen] > data->b[0])))
			rb(data, 1);
	else
		while ((data->blen > 0)
			&& !((data->a[data->alen] < data->b[data->blen]
					&& data->b[data->blen] > data->b[0])))
			rrb(data, 1);
}

void	b_move_biggest(t_data *data)
{
	if (test_b(data) == 1)
		while (data->blen > 0
			&& !((data->a[data->alen] > data->b[data->blen]
					&& data->b[data->blen] > data->b[0])))
			rb(data, 1);
	else
		while (data->blen > 0
			&& !((data->a[data->alen] > data->b[data->blen]
					&& data->b[data->blen] > data->b[0])))
			rrb(data, 1);
}

void	b_move_middle(t_data *data)
{
	if (test_m(data) == 1)
		while (data->blen > 0
			&& !(data->b[data->blen] < data->a[data->alen]
				&& data->a[data->alen] < data->b[0]))
			rb(data, 1);
	else
		while (data->blen > 0
			&& !(data->b[data->blen] < data->a[data->alen]
				&& data->a[data->alen] < data->b[0]))
			rrb(data, 1);
}
void	arrange_b_stack(t_data *data)
{
		if (smallest_nb(data))
		{
			printf("SMALLEST NB FOUND :\n");
			print_stacks(data);
			b_move_smallest(data);
			print_stacks(data);
			printf("-----------------\n");
		}
		else if (biggest_nb(data))
		{
			printf("BIGGEST NB FOUND :\n");
			print_stacks(data);
			b_move_biggest(data);
			print_stacks(data);
			printf("-----------------\n");
		}
		else
		{
			printf("A MIDDLE NB FOUND :\n");
			print_stacks(data);
			b_move_middle(data);
			print_stacks(data);
			printf("-----------------\n");
		}
}
