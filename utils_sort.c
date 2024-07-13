/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:17:12 by akar              #+#    #+#             */
/*   Updated: 2024/07/03 15:17:14 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*max_node(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max;

	if (!stack)
		return (NULL);
	max = *stack;
	tmp = max->next;
	while (tmp != NULL)
	{
		if (tmp->data > max->data)
		{
			max = tmp;
			tmp = max->next;
		}
		else
			tmp = tmp->next;
	}
	return (max);
}

t_stack	*min_node(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = *stack;
	tmp = min->next;
	while (tmp != NULL)
	{
		if (tmp->data < min->data)
		{
			min = tmp;
			tmp = min->next;
		}
		else
			tmp = tmp->next;
	}
	return (min);
}

int	ft_issort(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node != NULL && node->next != NULL)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}
