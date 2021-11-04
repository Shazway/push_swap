/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:17:32 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/11/04 23:25:49 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_ope(int ope[4])
{
	int		i;
	int		i_min;
	int		min;

	i = -1;
	i_min = 0;
	min = -1;
	while (++i < 4)
	{
		if (i == 0 || ope[i] < min)
		{
			min = ope[i];
			i_min = i;
		}
	}
	return (i_min);
}

void	best_operations(t_data *data, int i)
{
	if (i == 0)
	{
		data->ma[0]->n = 0;
		data->mb[0]->n = 0;
	}
	else if (i == 1)
	{
		data->ma[1]->n = 0;
		data->mb[1]->n = 0;
	}
	else if (i == 2)
	{
		data->ma[0]->n = 0;
		data->mb[1]->n = 0;
	}
	else if (i == 3)
	{
		data->ma[1]->n = 0;
		data->mb[0]->n = 0;
	}
}

void	apply_right(t_data *data)
{
	while (data->ma[0]->n > 0 || data->mb[0]->n > 0)
	{
		if (data->ma[0]->n > 0 && data->mb[0]->n > 0)
			rr(data);
		else
		{
			if (data->ma[0]->n > 0)
				ra(data);
			if (data->mb[0]->n > 0)
				rb(data);
		}
		data->ma[0]->n--;
		data->mb[0]->n--;
	}
}

void	apply_left(t_data *data)
{
	while (data->ma[1]->n > 0 || data->mb[1]->n > 0)
	{
		if (data->ma[1]->n > 0 && data->mb[1]->n > 0)
			rrr(data);
		else
		{
			if (data->ma[1]->n > 0)
				rra(data);
			if (data->mb[1]->n > 0)
				rrb(data);
		}
		data->ma[1]->n--;
		data->mb[1]->n--;
	}
}

void	generate_moves(t_data *data)
{
	int		operations[4];

	data->ma[1]->n = data->a->size - data->ma[0]->n;
	data->mb[0]->n = data->b->size - data->mb[1]->n;
	operations[0] = ft_max(data->ma[1]->n, data->mb[1]->n);
	operations[1] = ft_max(data->ma[0]->n, data->mb[0]->n);
	operations[2] = data->ma[1]->n + data->mb[0]->n;
	operations[3] = data->ma[0]->n + data->mb[1]->n;
	best_operations(data, min_ope(operations));
	apply_right(data);
	apply_left(data);
}
