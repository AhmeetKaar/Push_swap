/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:17:33 by akar              #+#    #+#             */
/*   Updated: 2024/07/03 15:17:35 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_stack **stack)
{
	t_stack	*start;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-1);
	start = *stack;
	last = ft_lstlast(start);
	*stack = start->next;
	start->next = NULL;
	last->next = start;
	return (0);
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}
