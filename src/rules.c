/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:33:08 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/26 12:34:19 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	r(t_stack **stack)
{
	t_node	*tmp;

	if ((*stack)->nodes && (*stack)->nodes->next)
	{
		tmp = (*stack)->nodes;
		(*stack)->nodes = (*stack)->nodes->next;
		ft_lst_node_add_back(&(*stack)->nodes, tmp);
		tmp->next = NULL;
	}
}

void	s(t_stack **stack)
{
	t_node	*tmp;

	if ((*stack)->nodes && (*stack)->nodes->next)
	{
		tmp = (*stack)->nodes;
		(*stack)->nodes = (*stack)->nodes->next;
		tmp->next = (*stack)->nodes->next;
		(*stack)->nodes->next = tmp;
	}
}

void	rr(t_stack **stack)
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
	}
}
