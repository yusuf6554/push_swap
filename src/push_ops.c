/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:58:55 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/09 14:19:40 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sb_push(t_push_swap *ps, int min, int max)
{
	int				i;
	t_three_values	b;

	b.first = ps->b->nodes->index;
	b.second = ps->b->nodes->next->index;
	if (ps->b->size > 2)
		b.third = ps->b->nodes->next->next->index;
	i = max - min + 1;
	if (is_node_sorted_reverse(ps->b, min, max) == 1)
		while (i--)
			pa(ps);
	else if (i == 2)
	{
		sb(ps->b);
		pa(ps);
		pa(ps);
	}
	else if (i == 3 && ps->b->size == 3)
		sb_reverse_sort_three(ps, b);
	else if (i == 3)
		sb_push_sort_three_a(ps, b);
}

static void	sa_push(t_push_swap *ps, int min, int max)
{
	int				i;
	t_three_values	a;

	a.first = ps->a->nodes->index;
	a.second = ps->a->nodes->next->index;
	if (ps->a->size > 2)
		a.third = ps->a->nodes->next->next->index;
	i = max - min + 1;
	if (is_node_sorted(ps->a, min, max) == 1)
		return ;
	else if (i == 2
		&& ps->a->nodes->index > ps->a->nodes->next->index)
		ss_push_a(ps);
	else if (i == 3 && ps->a->size == 3)
		sa_sort_three(ps, a);
	else if (i == 3)
		sa_three_sort_gthree(ps, a);
}

void	sb_push_a(t_push_swap *ps, int min, int max)
{
	int	pivot;
	int	i;
	int	len;
	int	r_count;

	r_count = 0;
	len = max - min + 1;
	pivot = ((max + min) / 2) + (max + min) % 2;
	if (len > 3)
	{
		i = len;
		while ((len / 2) < i)
			if (ps->b->nodes->index >= pivot && i--)
				pa(ps);
		else if (++r_count)
			rb(ps->b);
		while (r_count--
			&& (len / 2) + (len % 2) != ps->b->size)
			rrb(ps->b);
		sa_push_b(ps, pivot, max);
		sb_push_a(ps, min, pivot - 1);
	}
	else
		sb_push(ps, min, max);
}

void	sa_push_b(t_push_swap *ps, int min, int max)
{
	int	pivot;
	int	i;
	int	len;
	int	r_count;

	r_count = 0;
	len = max - min + 1;
	pivot = ((max + min) / 2) + (max + min) % 2;
	if (len > 3)
	{
		i = len;
		while ((len / 2) < i)
			if (ps->a->nodes->index >= pivot && i--)
				pb(ps);
		else if (++r_count)
			ra(ps->a);
		while (r_count--
			&& (len / 2) + (len % 2) != ps->a->size)
			rra(ps->a);
		sa_push_b(ps, pivot, max);
		sb_push_a(ps, min, pivot - 1);
	}
	else
		sa_push(ps, min, max);
}
