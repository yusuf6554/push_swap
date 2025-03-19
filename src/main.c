/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:18:38 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/19 14:54:03 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

static int	get_stack_size(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	i--;
	return (i);
}

static void fill_stack(t_push_swap *push_swap)
{
	int	i;

	i = -1;
	while (++i < push_swap->size)
	{
		if (push_swap->argc == 2)
			push_swap->stack_a[i] = ft_atoi(push_swap->split[i]);
		else
			push_swap->stack_a[i] = ft_atoi(push_swap->argv[i + 1]);
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;

	if (argc < 2)
		return (0);
	push_swap.size = get_stack_size(argv);
	push_swap.split = NULL;
	push_swap.argv = argv;
	push_swap.argc = argc;
	if (argc == 2)
	{
		push_swap.split = ft_split(push_swap.argv[1], ' ');
		push_swap.size = get_stack_size(push_swap.split) + 1;
	}
	push_swap.stack_a = malloc(sizeof(int) * (push_swap.size + 1));
	push_swap.stack_b = malloc(sizeof(int) * (push_swap.size + 1));
	if (!push_swap.stack_a || !push_swap.stack_b)
		return (1);
	fill_stack(&push_swap);
	free_split(push_swap.split);
	ft_printf("%i\n%i\n", push_swap.stack_a[0], push_swap.size);
	free(push_swap.stack_a);
	free(push_swap.stack_b);
	return (0);
}
