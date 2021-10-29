/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:39:27 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/29 16:40:48 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*concatenate(char **argv)
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

void	ft_strjoin_to(char **dest, char *s2)
{
	char		*temp;

	temp = *dest;
	*dest = ft_strjoin(*dest, s2);
	free(temp);
}

int	min_ope(int ope[4])
{
	int		i;
	int		i_min;
	int		min;

	i = -1;
	i_min = 0;
	min = -1;
	while (++i < 4)
	{
		if (min == -1 || ope[i] < min)
		{
			min = ope[i];
			i_min = i;
		}
	}
	return (i_min);
}

int	highest_b(t_data *data)
{
	int		i;
	int		b_max;

	b_max = find_max_index(data->b, data->blen);
	i = 0;
	while (data->b[i] != data->b[b_max])
		i++;
	if (i != data->blen)
		i++;
	else
		i = 0;
	return (i);
}
