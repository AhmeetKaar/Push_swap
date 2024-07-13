/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:18:06 by akar              #+#    #+#             */
/*   Updated: 2024/07/03 15:18:08 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_args_is_number(char **args);
static void		check_args_is_duplicate(char **args);
static void		check_is_int(char **args);
static long int	ft_atol(const char *str);

void	check_args(char **args)
{
	int	i;

	i = 0;
	check_args_is_number(args);
	check_is_int(args);
	check_args_is_duplicate(args);
	while (args[i])
		free(args[i++]);
	free(args);
}

static void	check_args_is_number(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if ((args[i][j] == '+' || args[i][j] == '-') && args[i][j + 1]
			&& args[i][j + 1] != '0')
			j++;
		while (args[i][j])
		{
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				ft_error();
			j++;
		}
		i++;
	}
}

static void	check_is_int(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_atol(args[i]) > INTMAX || ft_atol(args[i]) < INTMIN)
			ft_error();
		i++;
	}
}

static void	check_args_is_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[j]) == ft_atoi(args[i]))
				ft_error();
			j++;
		}
		i++;
	}
}

static long int	ft_atol(const char *str)
{
	int			i;
	int			mult;
	long int	nb;

	mult = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}
