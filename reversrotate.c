/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:17:39 by akar              #+#    #+#             */
/*   Updated: 2024/07/03 15:17:41 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*iter;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-1);
	iter = *stack;
	last = ft_lstlast(iter);
	while (iter != NULL)
	{
		if (iter->next->next == NULL)
		{
			iter->next = NULL;
			break ;
		}
		iter = iter->next;
	}
	last->next = *stack;
	*stack = last;
	return (0);
}

void	ft_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}
