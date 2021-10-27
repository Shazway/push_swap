/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:18:56 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 18:49:38 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	(*data)->operations = 0;
	if ((*data)->alen < 499)
		(*data)->chunk_size = (((*data)->alen + 1) / 5);
	else
		(*data)->chunk_size = ((*data)->alen + 1) / 11;
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
