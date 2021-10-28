/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:18:56 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/28 22:58:57 by magostin         ###   ########.fr       */
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

int	ft_allocate(t_data **data, int len)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (0);
	(*data)->alen = len;
	(*data)->blen = -1;
	(*data)->clen = len;
	(*data)->start_chunk = 0;
	(*data)->print = 1;
	if ((*data)->alen < 499)
		(*data)->chunk_size = (((*data)->alen + 1) / 6);
	else
		(*data)->chunk_size = ((*data)->alen + 1) / 12;
	(*data)->end_chunk = (*data)->chunk_size - 1;
	(*data)->a = malloc(sizeof(int) * (len + 1));
	if (!(*data)->a)
		return (0);
	(*data)->b = malloc(sizeof(int) * (len + 1));
	if (!(*data)->b)
		return (0);
	(*data)->c = malloc(sizeof(int) * (len + 1));
	if (!(*data)->c)
		return (0);
	return (1);
}

void	sort_c_tab(t_data *data)
{
	int	i;
	int	temp;
	int	breakcondition;

	while (1)
	{
		i = 0;
		breakcondition = 0;
		while (i < data->clen)
		{
			if (data->c[i] > data->c[i + 1])
			{
				temp = data->c[i];
				data->c[i] = data->c[i + 1];
				data->c[i + 1] = temp;
				breakcondition = 1;
			}
			i++;
		}
		if (breakcondition == 0)
			break ;
	}
}
