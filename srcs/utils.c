/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:54:05 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/29 16:37:49 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_stacks(t_data *data)
{
	int	i;

	i = 0;
	printf("\nStacks:\nA => ");
	while (i <= data->alen)
	{
		printf("%d ", data->a[i]);
		i++;
	}
	i = 0;
	printf("\nB => ");
	while (i <= data->blen)
	{
		printf("%d ", data->b[i]);
		i++;
	}
	printf("\nC => ");
	i = 0;
	while (i <= data->clen)
	{
		printf("%d ", data->c[i]);
		i++;
	}
	printf("\n");
}

int	ft_allocate_moves(t_data *data)
{
	data->a_move = malloc(sizeof(t_move));
	data->b_move = malloc(sizeof(t_move));
	if (!data->a_move || !data->b_move)
		return (1);
	return (0);
}

int	ft_allocate(t_data *data, int len)
{
	if (!data || ft_allocate_moves(data))
		return (1);
	data->alen = len;
	data->blen = -1;
	data->clen = len;
	data->start_chunk = 0;
	data->print = 1;
	if (data->alen < 499)
		data->chunk_size = ((data->alen + 1) / 6);
	else
		data->chunk_size = (data->alen + 1) / 12;
	data->end_chunk = data->chunk_size - 1;
	data->a = malloc(sizeof(int) * (len + 1));
	data->b = malloc(sizeof(int) * (len + 1));
	data->c = malloc(sizeof(int) * (len + 1));
	if (!data->a || !data->b || !data->c)
		return (1);
	return (0);
}
