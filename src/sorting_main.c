/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:03:16 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/17 13:32:18 by yukoc            ###   ########.fr       */
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
	i = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	while (i < max_bits)
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
			pa(a, b);
		i++;
	}	
}

int	sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return (0);
	}
	else if (size == 3)
		return (sort_three_a(a), 0);
	if (size <= 6)
		return (sort_little(a, b), 0);
	return (sort_radix(a, b, size), 0);
}
