/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:10:35 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/17 13:12:39 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	remove_last_node(t_stack **stack)
{
	t_stack *last;
	t_stack *prev;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	else
		*stack = NULL;
}

void	rra(t_stack **a)
{
	t_stack *last;

	if (!(*a) || !(*a)->next)
		return ;
	last = ft_node_last(a);
	remove_last_node(a);
	last->next = *a;
	*a = last;
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack *last;

	if (!(*b) || !(*b)->next)
		return ;
	last = ft_node_last(b);
	remove_last_node(b);
	last->next = *b;
	*b = last;
	ft_printf("rrb\n");
}
