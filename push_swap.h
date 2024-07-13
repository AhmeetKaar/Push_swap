/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:17:52 by akar              #+#    #+#             */
/*   Updated: 2024/07/03 15:17:54 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);
void				ft_rra(t_stack **stack_a);
void				ft_ra(t_stack **stack_a);
void				ft_sa(t_stack **stack_a);
void				check_args(char **args);
void				ft_error(void);
int					ft_issort(t_stack **stack);
void				ft_free(char **str);
void				index_stack(t_stack **stack);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
t_stack				*max_node(t_stack **stack);
t_stack				*min_node(t_stack **stack);
t_stack				*ft_lstnew(int content);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstlast(t_stack *lst);
int					ft_lstsize(t_stack *lst);

#endif