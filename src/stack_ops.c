/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:34:43 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/07 13:43:20 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_node	*set_value(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = val;
	node->index = -1;
	node->next = NULL;
	return (node);
}

static int	fill_node_with_two_args(t_stack **stack_a, char **argv)
{
	t_node	*node;
	t_node	*node_temp;
	char	**temp;
	int		i;

	temp = ft_split(argv[1], ' ');
	if (!temp)
		return (0);
	if (temp[1] == 0)
		return (ft_free_all(temp), 0);
	node = set_value(ft_atoi(temp[0]));
	if (!node)
		return (ft_free_all(temp), 0);
	(*stack_a)->nodes = node;
	i = 0;
	while (temp[++i])
	{
		node_temp = set_value(ft_atoi(temp[i]));
		if (!node_temp)
			return (ft_free_all(temp), 0);
		if (ft_lst_node_add_back(&node, node_temp) == 0)
			return (ft_free_all(temp), 0);
	}
	ft_free_all(temp);
	return (1);
}

static int	fill_node(t_stack **stack_a, int argc, char **argv)
{
	t_node	*node;
	t_node	*temp;
	int		i;

	node = set_value(ft_atoi(argv[1]));
	if (!node)
		return (0);
	(*stack_a)->nodes = node;
	i = 1;
	while (++i < argc)
	{
		temp = set_value(ft_atoi(argv[i]));
		if (!temp)
			return (0);
		if (ft_lst_node_add_back(&node, temp) == 0)
			return (0);
	}
	return (1);
}

int	stack_ops(int argc, char **argv, t_stack **stack)
{
	if (argc == 2)
		if (!fill_node_with_two_args(stack, argv))
			return (0);
	else
		if (!fill_node(stack, argc, argv))
			return (0);
	(*stack)->size = ft_lst_size((*stack)->nodes);
	return (1);
}
