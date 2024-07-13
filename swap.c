/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:17:24 by akar              #+#    #+#             */
/*   Updated: 2024/07/03 15:17:26 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_stack **stack)
{
	t_stack	*start;
	t_stack	*second;
	int		temp_data;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-1);
	start = *stack;
	second = start->next;
	temp_data = start->data;
	start->data = second->data;
	second->data = temp_data;
	return (0);
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}
