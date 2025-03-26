/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:22:10 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/26 12:31:37 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ra(t_stack **stack)
{
	t_node	*tmp;

	if ((*stack)->nodes && (*stack)->nodes->next)
	{
		tmp = (*stack)->nodes;
		(*stack)->nodes = (*stack)->nodes->next;
		ft_lst_node_add_back(&(*stack)->nodes, tmp);
		tmp->next = NULL;
		ft_putendl_fd("ra", 1);
	}
}

void	sa(t_stack **stack)
{
	t_node	*tmp;

	if ((*stack)->nodes && (*stack)->nodes->next)
	{
		tmp = (*stack)->nodes;
		(*stack)->nodes = (*stack)->nodes->next;
		tmp->next = (*stack)->nodes->next;
		(*stack)->nodes->next = tmp;
		ft_putendl_fd("sa", 1);
	}
}

void	pa(t_push_swap *ps)
{
	t_node	*tmp;

	if (ps->b->size)
	{
		ps->a->size++;
		ps->b->size--;
		tmp = ps->b->nodes;
		ps->b->nodes = ps->b->nodes->next;
		tmp->next = ps->a->nodes;
		ps->a->nodes = tmp;
		ft_putendl_fd("pa", 1);
	}
}

void	rra(t_stack **stack)
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
		ft_putendl_fd("rra", 1);
	}
}
