/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:17:58 by akar              #+#    #+#             */
/*   Updated: 2024/07/03 15:18:01 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parse_args(int ac, char **av);
static char	*convert_to_one_str(int ac, char **av);

static char	**parse_args(int ac, char **av)
{
	char	*str;
	char	**result;

	str = convert_to_one_str(ac, av);
	result = ft_split(str, ' ');
	if (result[0] == NULL)
	{
		free(result[0]);
		free(result);
		exit(0);
	}
	return (free(str), result);
}

static char	*convert_to_one_str(int ac, char **av)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	str = NULL;
	if (ac == 2)
		str = ft_strdup(av[1]);
	else if (ac > 2)
	{
		str = ft_strdup("");
		while (++i < ac)
		{
			temp = ft_strjoin(str, " ");
			free(str);
			str = ft_strjoin(temp, av[i]);
			free(temp);
		}
	}
	return (str);
}

static void	fill_stack(t_stack **stack, int ac, char **av)
{
	int		i;
	char	**argv;
	t_stack	*new;

	i = 0;
	if (ac == 2)
		argv = ft_split(av[1], ' ');
	else
	{
		i = 1;
		argv = av;
	}
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (ac == 2)
		ft_free(argv);
}

static void	free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	node = *stack;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	free(stack);
}

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**args;

	if (ac < 2)
		exit(0);
	args = parse_args(ac, av);
	check_args(args);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack(stack_a, ac, av);
	if (ft_issort(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
