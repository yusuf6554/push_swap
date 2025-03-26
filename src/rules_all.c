/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:34:38 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/26 12:44:13 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	r_all(t_push_swap *ps, int flag)
{
	if (ps->a->nodes || ps->b->nodes)
	{
		r(&ps->a);
		r(&ps->b);
		if (flag)
			ft_putendl_fd("rr", 1);
	}
}

void	s_all(t_push_swap *ps, int flag)
{
	if (ps->a->nodes || ps->b->nodes)
	{
		s(&ps->a);
		s(&ps->b);
		if (flag)
			ft_putendl_fd("ss", 1);
	}
}

void	rr_all(t_push_swap *ps, int flag)
{
	if (ps->a->nodes || ps->b->nodes)
	{
		rr(&ps->a);
		rr(&ps->b);
		if (flag)
			ft_putendl_fd("rrr", 1);
	}
}

void	ss_push_a(t_push_swap *ps)
{
	if (ps->b->size >= 2 && ps->b->nodes->index < ps->b->nodes->next->index)
		s_all(ps, 1);
	else
		sa(&ps->a);
}
