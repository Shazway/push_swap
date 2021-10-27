/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removed_useless_shit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:44:27 by krain             #+#    #+#             */
/*   Updated: 2021/10/27 18:49:43 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int highest;

	while (data->blen >= 0)
	{
		if (smallest_nb_a(data))
		{
			printf("SMALLEST NB FOUND :\n");
			//print_stacks(data);
			b_move_smallest_a(data);
			print_stacks(data);
			//rintf("-----------------\n");
		}
		else if (biggest_nb_a(data))
		{
			printf("BIGGEST NB FOUND :\n");
			//print_stacks(data);
			b_move_biggest_a(data);
			print_stacks(data);
			//rintf("-----------------\n");
		}
		else
		{
			printf("A MIDDLE NB FOUND :\n");
			//print_stacks(data);
			b_move_middle_a(data);	
			print_stacks(data);
			//printf("-----------------\n");
		}
		pa(data);
	}
	
	highest = find_max_index(data->a, data->alen);
	
	void	(*move)(t_data *, int);
	printf("a[%d] = %d\n", highest, data->a[highest]);
	print_stacks(data);

	if (highest > data->alen / 2)
	{
		//printf("%d rrbs is better with rb (blen = %d)\n", i, data->blen);
		move = &ra;
		highest = data->alen - highest + 1;
	}
	else
		move = &rra;
	while (highest > 0)
	{
		move(data, 1);
		highest--;
	}
	printf("%d\n", highest);
	print_stacks(data);
}

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

int	test_rb_s(t_data *data, int nb_rb)
{
	int	i;

	i = 0;
	while (data->blen > 0
		&& !((data->a[data->alen] < data->b[data->blen]
				&& data->b[data->blen] > data->b[0])))
	{
		rb(data, 0);
		i++;
	}
	nb_rb = i;
	while (i >= 0)
	{
		rrb(data, 0);
		i--;
	}
	return (nb_rb);
}

int	test_rb_b(t_data *data, int nb_rb)
{
	int	i;

	i = 0;
	while (data->blen > 0
		&& !(data->a[data->alen] > data->b[data->blen]
			&& data->b[data->blen] > data->b[0]))
	{
		rb(data, 0);
		i++;
	}
	nb_rb = i;
	while (i >= 0)
	{
		rrb(data, 0);
		i--;
	}
	return (nb_rb);
}

int	test_rb_m(t_data *data, int nb_rb)
{
	int	i;

	i = 0;
	while (data->blen > 0
		&& !(data->b[data->blen] < data->a[data->alen]
			&& data->a[data->alen] < data->b[0]))
	{
		rb(data, 0);
		i++;
	}
	nb_rb = i;
	while (i >= 0)
	{
		rrb(data, 0);
		i--;
	}
	return (nb_rb);
}

int	smallest_nb(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->blen)
		if (data->b[i] < data->b[data->blen])
			return (0);
	return (1);
}

int	biggest_nb(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->blen)
		if (data->b[i] > data->a[data->alen])
			return (0);
	return (1);
}