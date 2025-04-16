/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:03:12 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/16 13:36:21 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*tmp;
	int		i;

	cur = *stack;
	while (cur)
	{
		i = 0;
		tmp = *stack;
		while (tmp)
		{
			if (cur->value > tmp->value)
				i++;
			tmp = tmp->next;
		}
		cur->index = i;
		cur = cur->next;
	}
}

static int	insertion(int *tmp_array, int len)
{
	int	i;
	int	j;
	int	key;
	int	pivot;

	i = 1;
	while (i < len)
	{
		key = tmp_array[i];
		j = i - 1;
		while (j >= 0 && tmp_array[j] > key)
		{
			tmp_array[j + 1] = tmp_array[j];
			j--;
		}
		tmp_array[j + 1] = key;
		i++;
	}
	pivot = tmp_array[len / 2];
	free(tmp_array);
	return (pivot);
}

int	find_pivot(t_stack **stack, int len)
{
	int		*pivot_array;
	int		i;
	t_stack	*tmp;

	i = 0;
	pivot_array = (int *)malloc(sizeof(int) * len);
	if (!pivot_array)
		handle_error(stack, "Memory allocation error (pivot_array)\n");
	tmp = *stack;
	while (tmp)
	{
		pivot_array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (insertion(pivot_array, len));
}
