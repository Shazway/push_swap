/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elems.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:51:53 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 17:17:59 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elems(t_data *data)
{
	if (data->a[0] > data->a[1] && data->a[0] > data->a[2]
		&& data->a[1] < data->a[2])
		sa(data, 1);
	if (data->a[0] < data->a[1] && data->a[0] < data->a[2]
		&& data->a[1] < data->a[2])
	{	
		sa(data, 1);
		rra(data, 1);
	}
	if (data->a[0] > data->a[1] && data->a[0] < data->a[2]
		&& data->a[1] < data->a[2])
		ra(data, 1);
	if (data->a[0] < data->a[1] && data->a[0] > data->a[2]
		&& data->a[1] > data->a[2])
	{
		sa(data, 1);
		ra(data, 1);
	}
	if (data->a[0] < data->a[1] && data->a[0] < data->a[2]
		&& data->a[1] > data->a[2])
		rra(data, 1);
}


int smallest_nb_a(t_data *data)
{
	int i;

	i = -1;
	while (++i <= data->alen)
		if (data->a[i] < data->b[data->blen])
			return (0);
	return (1);
}

int	test_ra_s(t_data *data, int nb_ra)
{
	int	i;

	i = 0;
	while (data->alen > 0
		&& !((data->b[data->blen] < data->a[data->alen]
				&& data->b[data->blen] < data->a[0])))
	{
		ra(data, 0);
		i++;
	}
	nb_ra = i;
	while (i >= 0)
	{
		rra(data, 0);
		i--;
	}
	return (nb_ra);
}
int test_s_a(t_data *data)
{
	int	i;
	int	nb_ra;
	int	nb_rra;

	i = 0;
	nb_ra = test_ra_s(data, 0);
	while (data->alen > 0
		&& !((data->b[data->blen] < data->a[data->alen]
				&& data->b[data->blen] < data->a[0])))
	{
		rra(data, 0);
		i++;
	}
	nb_rra = i;
	while (i >= 0)
	{
		ra(data, 0);
		i--;
	}
	if (nb_ra < nb_rra)
		return (1);
	return (0);
}

void	b_move_smallest_a(t_data *data)
{
	if (test_s_a(data) == 1)
		while ((data->alen > 0)
			&& !((data->b[data->blen] < data->a[data->alen]
					&& data->b[data->blen] < data->a[0])))
			ra(data, 1);
	else
		while ((data->alen > 0)
			&& !((data->b[data->blen] < data->a[data->alen]
					&& data->b[data->blen] < data->a[0])))
			rra(data, 1);
}
//-------------------------------------------------------------------------
int	test_ra_b(t_data *data, int nb_ra)
{
	int	i;

	i = 0;
	while (data->alen > 0
		&& !(data->b[data->blen] > data->a[data->alen]
			&& data->a[data->alen] > data->a[0]))
	{
		ra(data, 0);
		i++;
	}
	nb_ra = i;
	while (i >= 0)
	{
		rra(data, 0);
		i--;
	}
	return (nb_ra);
}
int	test_b_a(t_data *data)
{
	int	i;
	int	nb_ra;
	int	nb_rra;

	i = 0;
	nb_ra = test_ra_b(data, 0);
	while (data->alen > 0
		&& !(data->b[data->blen] > data->a[data->alen]
			&& data->a[data->alen] > data->a[0]))
	{
		rra(data, 0);
		i++;
	}
	nb_rra = i;
	while (i >= 0)
	{
		ra(data, 0);
		i--;
	}
	if (nb_ra < nb_rra)
		return (1);
	return (0);
}
void	b_move_biggest_a(t_data *data)
{
	if (test_b_a(data) == 1)
		while (data->alen > 0
			&& !((data->b[data->blen] > data->a[data->alen]
					&& data->a[data->alen] < data->a[0])))
			ra(data, 1);
	else
		while (data->alen > 0
			&& !((data->b[data->blen] > data->a[data->alen]
					&& data->a[data->alen] < data->a[0])))
			rra(data, 1);
}
int	biggest_nb_a(t_data *data)
{
	int i;

	i = -1;
	while (++i <= data->alen)
		if (data->a[i] > data->b[data->blen])
			return (0);
	return (1);
}
//-------------------------------------------------------------------------
int	test_ra_m(t_data *data, int nb_ra)
{
	int	i;

	i = 0;
	while (data->alen > 0
		&& !(data->a[data->alen] < data->b[data->blen]
			&& data->b[data->blen] < data->a[0]))
	{
		ra(data, 0);
		i++;
	}
	nb_ra = i;
	while (i >= 0)
	{
		rra(data, 0);
		i--;
	}
	return (nb_ra);
}
int test_m_a(t_data *data)
{
	int	i;
	int	nb_ra;
	int	nb_rra;

	i = 0;
	nb_ra = test_ra_m(data, 0);
	while (data->alen > 0
		&& !(data->a[data->alen] < data->b[data->blen]
			&& data->b[data->blen] < data->a[0]))
	{
		rra(data, 0);
		i++;
	}
	nb_rra = i;
	while (i >= 0)
	{
		ra(data, 0);
		i--;
	}
	if (nb_ra < nb_rra)
		return (1);
	return (0);
}
void	b_move_middle_a(t_data *data)
{
	if (test_m_a(data) == 1)
		while (data->alen > 0
			&& !(data->a[data->alen] > data->b[data->blen] 
				&& data->b[data->blen] > data->a[0]))
			ra(data, 1);
	else
		while (data->alen > 0
			&& !(data->a[data->alen] > data->b[data->blen]
				&& data->b[data->blen] > data->a[0]))
			rra(data, 1);
}
void	four_or_five_elems(t_data *data)
{
	int s_in_a;

	while (data->blen >= 0)
	{
		if (smallest_nb_a(data))
		{
			printf("SMALLEST NB FOUND :\n");
			print_stacks(data);
			b_move_smallest_a(data);
			pa(data);
			print_stacks(data);
			printf("-----------------\n");
		}
		else if (biggest_nb_a(data))
		{
			printf("BIGGEST NB FOUND :\n");
			print_stacks(data);
			b_move_biggest_a(data);
			pa(data);
			print_stacks(data);
			printf("-----------------\n");
		}
		else
		{
			printf("A MIDDLE NB FOUND :\n");
			print_stacks(data);
			b_move_middle_a(data);	
			pa(data);
			print_stacks(data);
			printf("-----------------\n");
		}
	}
	s_in_a = smallest_in_a(data);
	while (data->a[data->alen] != s_in_a)
		ra(data, 1);
	print_stacks(data);
}
