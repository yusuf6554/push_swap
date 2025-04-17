/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:16:16 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/17 15:31:33 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <stdlib.h>

t_stack	*ft_node_last(t_stack **stack)
{
	t_stack	*cur;

	if (!(*stack))
		return (NULL);
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*cur;

	if (!stack || !stack->next)
		return (1);
	cur = stack;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	get_len(t_stack *stack)
{
	int		len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	handle_error(t_stack **stack)
{
	t_stack	*cur;

	if (!stack)
		return ;
	cur = *stack;
	while (*stack)
	{
		*stack = (*stack)->next;
		free(cur);
		cur = *stack;
	}
	ft_printf("Error\n");
	exit(1);
}

int	is_reverse_sorted(t_stack *stack)
{
	t_stack	*cur;

	if (!stack || !stack->next)
		return (1);
	cur = stack;
	while (cur->next)
	{
		if (cur->value < cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
