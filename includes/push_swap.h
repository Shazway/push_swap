/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:38:17 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 18:42:51 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int	*a;
	int	*b;
	int	*c;
	int	alen;
	int	blen;
	int	clen;
	int	end_chunk;
	int	start_chunk;
	int	chunk_size;
	int	print;
	int	operations;
}	t_data;
void	sa(t_data *data, int pr);
void	sb(t_data *data, int pr);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data, int pr);
void	rb(t_data *data, int pr);
void	rra(t_data *data, int pr);
void	rrb(t_data *data, int pr);
void	rr(t_data *data);
void	rrr(t_data *data);
void	print_stacks(t_data *data);
void	fake_rrb(t_data *data);
void	fake_rb(t_data *data);
void	sort_small_stack(t_data *data);
void	sort_long_stack(t_data *data);
void	push_swap(t_data *data);
void	b_move_smallest(t_data *data);
void	b_move_biggest(t_data *data);
void	b_move_middle(t_data *data);
void	arrange_b_stack(t_data *data);
int		test_s(t_data *data);
int		test_b(t_data *data);
int		test_m(t_data *data);
void	three_elems(t_data *data);
void	four_or_five_elems(t_data *data);
void	move_nb_to_top(t_data *data, int top_scan, int bottom_scan);
int		test_rb_s(t_data *data, int nb_rb);
int		test_rb_b(t_data *data, int nb_rb);
int		test_rb_m(t_data *data, int nb_rb);
int		next_chunk(t_data *data);
int		bot_scan(t_data *data, int i);
int		roof_scan(t_data *data, int i);
int		ft_allocate(t_data **data, int len);
void	sort_c_tab(t_data *data);
int		smallest_nb(t_data *data);
int		biggest_nb(t_data *data);
int		is_a_sorted(t_data *data);
int		smallest_in_a(t_data *data);
long	ft_atoi(char *str, int i, int sign);
int		nb_only(char **str);
int		errors_check(char **argv, int argc, int i, t_data *data);
void	ft_free(t_data *data);
int		end_of_argv(char **argv);
void	fill_tabs(char **argv, t_data *data, int i, int j);
int		ft_strlen(char *str);
int		nb_only(char **str);
int		what_len(char **argv, int len);
int		ft_strlen(char *str);
int		decrem_j(char **argv, int i, int j);
int		increm_j(char **argv, int i, int j);
int		check_signs(char **argv);
int		are_there_numbers(char **argv);

void	best_move_for_b(t_data *data);
int find_max_index(int *stack, int len);
void	best_move_for_a(t_data *data);
void	apply_best_move_a(t_data *data, int i);



#endif