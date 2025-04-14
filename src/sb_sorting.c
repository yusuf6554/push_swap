/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:03:16 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/14 14:10:54 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sba_push_sort_three2(t_push_swap *ps, t_three_values t)
{
	if (t.first > t.second && t.second < t.third && t.third > t.first)
	{
		rb(&ps->b);
		sb(&ps->b);
		pa(ps);
		rrb(&ps->b);
		pa(ps);
		pa(ps);
	}
	else if (t.first < t.second && t.second < t.third && t.third > t.first)
	{
		rb(&ps->b);
		sb(&ps->b);
		pa(ps);
		pa(ps);
		rrb(&ps->b);
		pa(ps);
	}
}

void	sba_push_sort_three(t_push_swap *ps, t_three_values t)
{
	if (t.first > t.second && t.second < t.third && t.third < t.first)
	{
		pa(ps);
		sb(&ps->b);
		pa(ps);
		pa(ps);
	}
	else if (t.first < t.second && t.second > t.third && t.third < t.first)
	{
		sb(&ps->b);
		pa(ps);
		pa(ps);
		pa(ps);
	}
	else if (t.first < t.second && t.second > t.third && t.third > t.first)
	{
		sb(&ps->b);
		pa(ps);
		sb(&ps->b);
		pa(ps);
		pa(ps);
	}
	else
		sba_push_sort_three2(ps, t);
}

static void	sb_rev_sort_three2(t_push_swap *ps, t_three_values t)
{
	if (t.first < t.second && t.second < t.third && t.third > t.first)
	{
		rb(&ps->b);
		sb(&ps->b);
		pa(ps);
		pa(ps);
		pa(ps);
	}
	else if (t.first > t.second && t.second < t.third && t.third > t.first)
	{
		rrb(&ps->b);
		pa(ps);
		pa(ps);
		pa(ps);
	}
	else if (t.first < t.second && t.second > t.third && t.third > t.first)
	{
		rb(&ps->b);
		pa(ps);
		pa(ps);
		pa(ps);
	}
}

void	sb_rev_sort_three(t_push_swap *ps, t_three_values t)
{
	if (t.first > t.second && t.second < t.third && t.third < t.first)
	{
		pa(ps);
		sb(&ps->b);
		pa(ps);
		pa(ps);
	}
	else if (t.first < t.second && t.second > t.third && t.third < t.first)
	{
		sb(&ps->b);
		pa(ps);
		pa(ps);
		pa(ps);
	}
	else
		sb_rev_sort_three2(ps, t);
}

int	is_node_reverse_sorted(t_stack *stack, int min, int max)
{
	t_node	*node;

	node = stack->nodes;
	while (max - min + 1)
	{
		if (node->index != max)
			return (0);
		node = node->next;
		max--;
	}
	return (1);
}
