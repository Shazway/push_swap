/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:45:33 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/29 17:13:11 by tmoragli         ###   ########.fr       */
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

	data->print = 1;
	count = data->chunk_size;
	sort_c_tab(data);
	while (data->alen >= 0)
	{
		bottom_scan = bot_scan(data);
		top_scan = roof_scan(data);
		best_move_a(data, top_scan, bottom_scan);
		best_move_b(data);
		apply_moves(data);
		pb(data);
		count--;
		if (count == 0 && data->alen > 1)
			count = next_chunk(data);
	}
	while (data->blen >= 0)
		pa(data);
	s_in_a = smallest_in_a(data);
	while (data->a[data->alen] != s_in_a)
		ra(data, 1);
}

void	push_swap(t_data *data)
{
	if (!is_a_sorted(data))
		return ;
	if (data->alen <= 4)
		sort_small_stack(data);
	else if (data->alen > 4)
		sort_long_stack(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*args;

	data = malloc(sizeof(t_data));
	args = concatenate(argv);
	if (errors_check(args, argc, 0, NULL))
	{
		if (argc > 1)
			write(1, "Error\n", 6);
		free(args);
		free(data);
		return (1);
	}
	if (ft_allocate(data, (what_len(argv, 0) - 1)))
	{
		ft_free(data, args, 0);
		return (1);
	}
	fill_tabs(args, data);
	free(args);
	if (data->alen != 0 && errors_check(args, argc, 1, data))
	{
		write(1, "Error\n", 6);
		ft_free(data, args, 0);
		return (1);
	}
	push_swap(data);
	ft_free(data, args, 0);
	return (0);
}
