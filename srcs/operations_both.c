/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:17:43 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 19:04:36 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_data *data)
{
	ra(data, 0);
	rb(data, 0);
	if (data->print)
		write(1, "rr\n", 3);
}

void	rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	if (data->print)
		write(1, "rrr\n", 4);
	data->operations++;
}

void	ss(t_data *data)
{
	sa(data, 0);
	sb(data, 0);
	if (data->print)
		write(1, "ss\n", 3);
}
