/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 00:08:17 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 23:18:04 by magostin         ###   ########.fr       */
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
int	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	while (src[i])
		i++;
	return (ft_strlen(src));
}
char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*dest;

	len_s1 = ft_strlen(s1) + 1;
	len_s2 = ft_strlen(s2) + 1;
	dest = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!(dest))
		return (0);
	ft_strlcpy(dest, s1, len_s1 + 1);
	ft_strlcpy(dest + len_s1, s2, len_s2 + 1);
	dest[len_s1 + len_s2] = 0;
	return (dest);
}

void	ft_strjoin_to(char **dest, char *s2)
{
	char		*temp;

	temp = *dest;
	*dest = ft_strjoin(*dest, s2);
	free(temp);
}

char *concatanate(char **argv)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	while (argv && argv[++i])
	{
		ft_strjoin_to(&dest, argv[i]);
		ft_strjoin_to(&dest, " ");
	}
	return (dest);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*args;

	args = concatanate(argv);
	if (errors_check(args, argc, 0, NULL) == 1)
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
	fill_tabs(args, data);
	if (data->alen != 0 && errors_check(args, argc, 1, data) == 1)
	{

		write(1, "Error\n", 6);
		ft_free(data);
		return (1);
	}
	push_swap(data);
	ft_free(data);
	return (0);
}
