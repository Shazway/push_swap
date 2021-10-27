/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:18:25 by tmoragli          #+#    #+#             */
/*   Updated: 2021/10/27 18:50:32 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	decrem_j(char **argv, int i, int j)
{
	while (j > 0 && (argv[i][j] >= '0' && argv[i][j] <= '9'))
		j--;
	return (j);
}

int	end_of_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			j++;
		i++;
	}
	return (j - 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

int	what_len(char **argv, int len)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] && (argv[i][j] >= '0' && argv[i][j] <= '9'))
				len++;
			while (argv[i][j] && (argv[i][j] >= '0' && argv[i][j] <= '9'))
				j++;
			while (argv[i][j] && (argv[i][j] == ' ' || argv[i][j] == '-'))
				j++;
		}
		i++;
	}
	return (len);
}

long	ft_atoi(char *str, int i, int sign)
{
	long	nb;

	nb = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '-'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}
