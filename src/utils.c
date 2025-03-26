/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:16:16 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/26 12:21:01 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_stacks(t_push_swap *ps)
{
	t_node	*tmp;

	while (ps->a && ps->a->nodes)
	{
		tmp = ps->a->nodes;
		ps->a->nodes = ps->a->nodes->next;
		free(tmp);
	}
	if (ps->a)
		free(ps->a);
	while (ps->b && ps->b->nodes)
	{
		tmp = ps->b->nodes;
		ps->b->nodes = ps->b->nodes->next;
		free(tmp);
	}
	if (ps->b)
		free(ps->b);
	if (ps)
		free(ps);
}

static t_node	*ft_lst_last(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lst_node_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!new || !lst)
		return (0);
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lst_last(*lst);
		if (!last)
			return (0);
		last->next = new;
	}
	return (1);
}

int	ft_lst_size(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
