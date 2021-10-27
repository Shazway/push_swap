/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 00:08:17 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 17:47:09 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_data *data)
{
	int	count;

	count = 0;
	if (data->alen == 1)
		sa(data, 1);
	if (data->alen == 2)
		three_elems(data);
	if (data->alen == 4 || data->alen == 3)
	{
		while (data->alen > 2)
			pb(data);
		three_elems(data);
		four_or_five_elems(data);
	}
}

void	sort_long_stack(t_data *data)
{
	int	top_scan;
	int	bottom_scan;
	int	count;
	int	s_in_a;

	count = data->chunk_size - 1;
	sort_c_tab(data);
	while (data->alen >= 0)
	{
		bottom_scan = bot_scan(data, 0);
		top_scan = roof_scan(data, 0);
		move_nb_to_top(data, top_scan, bottom_scan);
		//arrange_b_stack(data);
		best_move_for_b(data);
		pb(data);
		count--;
		if (count == -1 && data->alen > 1)
			count = next_chunk(data);
	}
	while (data->blen >= 0)
		pa(data);
	s_in_a = smallest_in_a(data);
	while (data->a[data->alen] != s_in_a)
		ra(data, 1);
	//print_stacks(data);
}

void	push_swap(t_data *data)
{
	if (is_a_sorted(data) == 1)
	{
		if (data->alen <= 4)
			sort_small_stack(data);
		else if (data->alen > 4)
			sort_long_stack(data);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (errors_check(argv, argc, 0, NULL) == 1)
	{
		if (argc > 1)
			write(1, "Error\n", 6);
		return (1);
	}
	if (ft_allocate(&data, (what_len(argv, 0) - 1)) == 0)
	{
		ft_free(data);
		return (1);
	}
	fill_tabs(argv, data, argc - 1, end_of_argv(argv));
	if (data->alen != 0 && errors_check(argv, argc, 1, data) == 1)
	{
		write(1, "Error\n", 6);
		ft_free(data);
		return (1);
	}
	push_swap(data);
	ft_free(data);
	return (0);
}
