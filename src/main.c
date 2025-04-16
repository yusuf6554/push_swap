/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:18:38 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/16 12:53:41 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	push_swap_main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (stack_init(argc, argv, &a) == 0)
		return (1);
	if (!is_sorted(a))
	{
		sort_index(&a);
		sort(&a, &b, get_len(a));
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}

int	main(int argc, char **argv)
{
	return (push_swap_main(argc, argv));
}
