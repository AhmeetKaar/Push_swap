/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:17:29 by akar              #+#    #+#             */
/*   Updated: 2024/07/03 15:20:02 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack **stack)
{
	t_stack	*max;

	max = NULL;
	max = max_node(stack);
	if (max == *stack)
		ft_ra(stack);
	else if ((*stack)->next == max)
		ft_rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		ft_sa(stack);
}

static void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	min = min_node(stack_a);
	if ((*stack_a)->next == min)
		ft_sa(stack_a);
	else if ((*stack_a)->next->next == min)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if ((*stack_a)->next->next->next == min)
		ft_rra(stack_a);
	if (!(ft_issort(stack_a)))
	{
		ft_pb(stack_a, stack_b);
		sort_3(stack_a);
		ft_pa(stack_a, stack_b);
	}
}

static void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	min = min_node(stack_a);
	if ((*stack_a)->next == min)
		ft_sa(stack_a);
	else if ((*stack_a)->next->next == min)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if ((*stack_a)->next->next->next == min)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if ((*stack_a)->next->next->next->next == min)
		ft_rra(stack_a);
	if (!(ft_issort(stack_a)))
	{
		ft_pb(stack_a, stack_b);
		sort_4(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
