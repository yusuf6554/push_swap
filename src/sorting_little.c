/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_little.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:41:49 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/18 12:46:55 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	sort_three_a(t_stack **stack)
{
	int	b;
	int	c;

	if (is_sorted(*stack))
		return ;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if ((*stack)->value > b && b < c && (*stack)->value < c)
		sa(stack);
	else if ((*stack)->value > b && b > c && (*stack)->value > c)
	{
		sa(stack);
		rra(stack);
	}
	else if ((*stack)->value > b && b < c && (*stack)->value > c)
		ra(stack);
	else if ((*stack)->value < b && b > c && (*stack)->value < c)
	{
		sa(stack);
		ra(stack);
	}
	else if ((*stack)->value < b && b > c && (*stack)->value > c)
		rra(stack);
}

void	sort_three_b(t_stack **stack)
{
	int	b;
	int	c;

	if (is_reverse_sorted(*stack))
		return ;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if ((*stack)->value > b && b > c && (*stack)->value > c)
	{
		sb(stack);
		rrb(stack);
	}
	else if ((*stack)->value < b && b > c && (*stack)->value < c)
		rb(stack);
	else if ((*stack)->value > b && b < c && (*stack)->value < c)
		rrb(stack);
	else if ((*stack)->value < b && b > c && (*stack)->value > c)
		sb(stack);
	else if ((*stack)->value > b && b < c && (*stack)->value > c)
	{
		rrb(stack);
		sb(stack);
	}
}

void	sort_little(t_stack **a, t_stack **b)
{
	int	pivot;
	int	len;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	pivot = find_pivot(a, get_len(*a));
	len = get_len(*a) / 2;
	while (len > 0)
	{
		if ((*a)->value >= pivot)
			ra(a);
		else
		{
			pb(a, b);
			len--;
		}
	}
	if (get_len(*b) == 2 && (*b)->value < (*b)->next->value)
		sb(b);
	if (get_len(*a) == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	sort_three_a(a);
	sort_three_b(b);
	while (*b)
		pa(a, b);
}
