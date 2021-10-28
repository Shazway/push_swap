/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:39:27 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/28 16:28:26 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
