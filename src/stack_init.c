/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:34:43 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/17 14:48:45 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void	free_stack(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	cur = *stack;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*stack = NULL;
}

static int	create_node(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*cur;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		handle_error(stack, "Memory allocation error (node)");
		return (0);
	}
	new->value = value;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		cur = *stack;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	return (1);
}

static void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	ft_proc_split(char **split, t_stack **stack)
{
	int		i;

	i = 0;
	while (split[i])
	{
		if (!ft_is_valid_integer(split[i]))
		{
			ft_free_split(split);
			handle_error(stack, "Error: Invalid argument\n");
			return (1);
		}
		create_node(stack, ft_atoi(split[i]));
		i++;
	}
	ft_free_split(split);
	return (0);
}

int	stack_init(int argc, char **argv, t_stack **stack)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		if (check_arg(argv[i]))
			handle_error(stack, "Error: Empty argument\n");
		split = ft_split(argv[i], ' ');
		if (!split)
			return (handle_error(stack, "Memory allocation error (split)"), 1);
		if (ft_proc_split(split, stack))
			return (1);
		i++;
	}
	if (check_for_duplicates(*stack))
		return (handle_error(stack, "Error: Duplicate numbers detected"), 1);
	return (0);
}
