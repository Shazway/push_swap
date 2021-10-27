/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:46:17 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/26 22:06:10 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_s(t_data *data)
{
	int	i;
	int	nb_rb;
	int	nb_rrb;

	i = 0;
	nb_rb = test_rb_s(data, 0);
	while (data->blen > 0
		&& !((data->a[data->alen] < data->b[data->blen]
				&& data->b[data->blen] > data->b[0])))
	{
		rrb(data, 0);
		i++;
	}
	nb_rrb = i;
	while (i >= 0)
	{
		rb(data, 0);
		i--;
	}
	if (nb_rb < nb_rrb)
		return (1);
	return (0);
}

int	test_b(t_data *data)
{
	int	i;
	int	nb_rb;
	int	nb_rrb;

	i = 0;
	nb_rb = test_rb_b(data, 0);
	while (data->blen > 0
		&& !(data->a[data->alen] > data->b[data->blen]
			&& data->b[data->blen] > data->b[0]))
	{
		rrb(data, 0);
		i++;
	}
	nb_rrb = i;
	while (i >= 0)
	{
		rb(data, 0);
		i--;
	}
	if (nb_rb < nb_rrb)
		return (1);
	return (0);
}

int	test_m(t_data *data)
{
	int	i;
	int	nb_rb;
	int	nb_rrb;

	i = 0;
	nb_rb = test_rb_m(data, 0);
	while (data->blen > 0
		&& !(data->b[data->blen] < data->a[data->alen]
			&& data->a[data->alen] < data->b[0]))
	{
		rrb(data, 0);
		i++;
	}
	nb_rrb = i;
	while (i >= 0)
	{
		rb(data, 0);
		i--;
	}
	if (nb_rb < nb_rrb)
		return (1);
	return (0);
}
