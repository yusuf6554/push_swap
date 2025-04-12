/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:03:12 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/12 16:08:37 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		rra(ps->a);
	}
	else if (t.first > t.second && t.second < t.third && t.third < t.first)
		ra(ps->a);
	else if (t.first < t.second && t.second > t.third && t.third < t.first)
		rra(ps->a);
	else if (t.first > t.second && t.second < t.third && t.third > t.first)
		ss_push_a(ps);
	else if (t.first < t.second && t.second > t.third && t.third > t.first)
	{
		ra(ps->a);
		ss_push_a(ps);
		rra(ps->a);
	}
}
