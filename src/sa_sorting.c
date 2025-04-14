/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:03:12 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/14 14:10:12 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sa_more_than_three_sort2(t_push_swap *ps, t_three_values t)
{
	if (t.first < t.second && t.second > t.third && t.third < t.first)
	{
		ra(&ps->a);
		ss_push_a(ps);
		rra(&ps->a);
		sa(&ps->a);
	}
	else if (t.first > t.second && t.second < t.third && t.third > t.first)
		ss_push_a(ps);
	else if (t.first < t.second && t.second > t.third && t.third > t.first)
	{
		ra(&ps->a);
		ss_push_a(ps);
		rra(&ps->a);
	}
}

void	sa_more_than_three_sort(t_push_swap *ps, t_three_values t)
{
	if (t.first > t.second && t.second > t.third && t.third < t.first)
	{
		ss_push_a(ps);
		ra(&ps->a);
		sa(&ps->a);
		rra(&ps->a);
		sa(&ps->a);
	}
	else if (t.first > t.second && t.second < t.third && t.third < t.first)
	{
		ss_push_a(ps);
		ra(&ps->a);
		sa(&ps->a);
		rra(&ps->a);
	}
	else
		sa_more_than_three_sort2(ps, t);
}

void	sa_sort_three(t_push_swap *ps)
{
	t_three_values	t;

	t.first = ps->a->nodes->index;
	t.second = ps->a->nodes->next->index;
	if (ps->a->size >= 3)
		t.third = ps->a->nodes->next->next->index;
	if (t.first > t.second && t.second > t.third && t.third < t.first)
	{
		ss_push_a(ps);
		rra(&ps->a);
	}
	else if (t.first > t.second && t.second < t.third && t.third < t.first)
		ra(&ps->a);
	else if (t.first < t.second && t.second > t.third && t.third < t.first)
		rra(&ps->a);
	else if (t.first > t.second && t.second < t.third && t.third > t.first)
		ss_push_a(ps);
	else if (t.first < t.second && t.second > t.third && t.third > t.first)
	{
		ra(&ps->a);
		ss_push_a(ps);
		rra(&ps->a);
	}
}

int	is_node_sorted(t_stack *stack, int min, int max)
{
	t_node	*node;

	node = stack->nodes;
	while (max - min + 1)
	{
		if (node->index != min)
			return (0);
		node = node->next;
		min++;
	}
	return (1);
}
