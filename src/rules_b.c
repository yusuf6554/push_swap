/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:25:20 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/26 12:44:43 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rb(t_stack **stack)
{
	t_node	*tmp;

	if ((*stack)->nodes && (*stack)->nodes->next)
	{
		tmp = (*stack)->nodes;
		(*stack)->nodes = (*stack)->nodes->next;
		ft_lst_node_add_back(&(*stack)->nodes, tmp);
		tmp->next = NULL;
		ft_putendl_fd("rb", 1);
	}
}

void	sb(t_stack **stack)
{
	t_node	*tmp;

	if ((*stack)->nodes && (*stack)->nodes->next)
	{
		tmp = (*stack)->nodes;
		(*stack)->nodes = (*stack)->nodes->next;
		tmp->next = (*stack)->nodes->next;
		(*stack)->nodes->next = tmp;
		ft_putendl_fd("sb", 1);
	}
}

void	pb(t_push_swap *ps)
{
	t_node	*tmp;

	if (ps->a->size)
	{
		ps->b->size++;
		ps->a->size--;
		tmp = ps->a->nodes;
		ps->a->nodes = ps->a->nodes->next;
		tmp->next = ps->b->nodes;
		ps->b->nodes = tmp;
		ft_putendl_fd("pb", 1);
	}
}

void	rrb(t_stack **stack)
{
	t_node	*tmp;
	t_node	*last;

	if ((*stack)->nodes && (*stack)->nodes->next)
	{
		tmp = (*stack)->nodes;
		last = ft_lst_last(tmp);
		tmp = (*stack)->nodes;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = (*stack)->nodes;
		(*stack)->nodes = last;
		ft_putendl_fd("rrb", 1);
	}
}
