/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:08:59 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/17 13:10:26 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	last = ft_node_last(a);
	temp->next = NULL;
	last->next = temp;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*b) || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	last = ft_node_last(b);
	temp->next = NULL;
	last->next = temp;
	ft_printf("rb\n");
}
