/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:24:42 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/02 15:28:46 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static t_node	*get_next_min(t_stack *stack)
{
	t_node	*node;
	t_node	*min;
	int		flag;

	flag = 0;
	node = stack->nodes;
	min = NULL;
	if (!node)
		return (NULL);
	while (node)
	{
		if ((flag == 0 || node->value > min->value) && node->index == -1)
		{
			min = node;
			flag = 1;
		}
		node = node->next;
	}
	return (min);
}

void	node_index(t_stack **stack)
{
	long	i;
	t_node	*node;

	i = ft_lst_size((*stack)->nodes);
	node = get_next_min(*stack);
	while (node)
	{
		node->index = i;
		node = get_next_min(*stack);
		i--;
	}
}
