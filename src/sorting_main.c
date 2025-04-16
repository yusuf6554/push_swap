/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:03:16 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/16 13:41:13 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_radix(t_stack **a, t_stack **b, int size)
{
	int		i;
	int		j;
	int		num;
	int		max_bits;

	max_bits = 0;
	i = -1;
	while ((size - 1) >> max_bits)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = (*a)->index;
			if ((num >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(b, a);
	}	
}

void	sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	else if (size == 3)
	{
		sort_three_a(a, b);
		return ;
	}
	if (size <= 6)
	{
		sort_little(a, b);
		return ;
	}
	radix(a, b, size);
}
