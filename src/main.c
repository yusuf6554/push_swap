/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:18:38 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/17 12:49:11 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
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
	return (i);
}

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;
	int			size;
	char		**split;

	if (argc < 2)
		return (0);
	size = get_stack_size(argv);
	split = NULL;
	if (argc == 2)
	{
		split = split_string(argv[1], ' ');
		size = get_stack_size(split);
	}
	push_swap.stack_a = malloc(sizeof(int) * size);
	push_swap.stack_b = malloc(sizeof(int) * size);
	free_split(split);
	free(push_swap.stack_a);
	free(push_swap.stack_b);
	(void)push_swap;
	return (0);
}
