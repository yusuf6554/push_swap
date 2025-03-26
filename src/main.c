/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:18:38 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/27 02:21:08 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static int	get_pivot(t_node *node)
{
	int	min;
	int	max;

	min = node->index;
	max = node->index;
	while (node)
	{
		if (node->index < min)
			min = node->index;
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return (((min + max) / 2) + (min + max) % 2);
}

static void	sort_main(t_push_swap *ps, int max, int min)
{
	int	pivot_a;
	int	i;
	int	len;

	pivot_a = ((max + min) / 2) + (max + min) % 2;
	len = max - min + 1;
	i = len;
	while (len / 2 + len % 2 != i)
	{
		if (ps->a->nodes->index < pivot_a && i--)
			pb(ps);
		else if (ps->b->size > 2
			&& ps->b->nodes->index <= get_pivot(ps->b->nodes))
			r_all(ps, 1);
		else
			ra(ps->a);
	}
	sa_pb(ps, max, pivot_a);
	sb_pa(ps, min, pivot_a - 1);
}

static t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->nodes = NULL;
	return (stack);
}

static int	push_swap_main(int argc, char **argv)
{
	t_push_swap	ps;
	int			i;

	i = check_args(argc, argv);
	if (i == 0)
		return (0);
	else if (i == 2)
		return (1);
	ps.a = stack_init();
	ps.b = stack_init();
	if (!ps.a || !ps.b)
		return (free_stacks(&ps), 1);
	if (stack_operations(argc, argv, &ps.a) == 0)
		return (free_stacks(&ps), 1);
	node_index(&ps.a);
	if (ps.a->size == 3)
		sort_three(&ps);
	else if (ps.a->size == 2)
		sa(&ps.a);
	else
		sort_main(&ps, ps.a->size, 1);
	return (free_stacks(&ps), 0);
}

int	main(int argc, char **argv)
{
	return (push_swap_main(argc, argv));
}
