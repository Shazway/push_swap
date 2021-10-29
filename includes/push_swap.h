/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:45:53 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/29 17:12:56 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int				*a;
	int				*b;
	int				*c;
	struct s_move	*a_move;
	struct s_move	*b_move;
	int				alen;
	int				blen;
	int				clen;
	int				end_chunk;
	int				start_chunk;
	int				chunk_size;
	int				print;
}	t_data;

typedef struct s_move
{
	int		left_i;
	int		right_i;
	int		i;
}	t_move;

/*
**		a.c
*/
void	best_move_for_a(t_data *data);
void	apply_best_move_a(t_data *data, int i);

/*
**		b.c
*/
void	best_move_b(t_data *data);
int		find_max_index(int *stack, int len);
void	apply_moves(t_data *data);
void	best_move_a(t_data *data, int top_scan, int bottom_scan);

/*
**		elems.c
*/
void	three_elems(t_data *data);
void	four_or_five_elems(t_data *data);

/*
**		errors.c errors2.c
*/
int		errors_check(char *args, int argc, int i, t_data *data);

int		nb_only(char *args);
int		increm_j(char **argv, int i, int j);
int		check_signs(char *args);
int		are_there_numbers(char *args);

/*
**		long_stack_utils.c
*/
void	move_nb_to_top(t_data *data, int top_scan, int bottom_scan);
int		next_chunk(t_data *data);

/*
**		operations_a.c operations_b.c operations_both.c
*/
void	pa(t_data *data);
void	ra(t_data *data, int pr);
void	rra(t_data *data, int pr);
void	sa(t_data *data, int pr);

void	pb(t_data *data);
void	rb(t_data *data, int pr);
void	rrb(t_data *data, int pr);
void	sb(t_data *data, int pr);

void	rr(t_data *data);
void	rrr(t_data *data);
void	ss(t_data *data);

/*
**		scans.c
*/
int		bot_scan(t_data *data);
int		roof_scan(t_data *data);

/*
**		utils.c utils2.c utils3.c utils4.c
*/
void	print_stacks(t_data *data);
int		ft_allocate(t_data *data, int len);
int		ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);

int		is_a_sorted(t_data *data);
void	ft_free(t_data *data, char *args, int i);
int		smallest_in_a(t_data *data);
void	fill_tabs(char *argv, t_data *data);

int		decrem_j(char **argv, int i, int j);
int		end_of_argv(char **argv);
int		ft_strlen(char *str);
int		what_len(char **argv, int len);
long	ft_atoi(char *str);

char	*concatenate(char **argv);
void	ft_strjoin_to(char **dest, char *s2);
int		highest_b(t_data *data);
int		min_ope(int ope[4]);
void	sort_c_tab(t_data *data);

/*
**	apply_moves.c
*/
void	reset_moves(t_move *a, t_move *b);
void	apply_right_moves(t_data *data, t_move *a, t_move *b);
void	apply_left_moves(t_data *data, t_move *a, t_move *b);
void	best_operations(t_move *a, t_move *b, int i);
int		ft_max(int a, int b);

#endif