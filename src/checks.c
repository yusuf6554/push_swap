/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:52:08 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/17 13:35:59 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

int	ft_is_digit(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_valid_integer(char *str)
{
	int		i;
	int		sign;
	long	num;

	if (!ft_is_digit(str))
		return (0);
	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (num * sign < INT_MIN || num * sign > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	check_for_duplicates(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*tmp;

	cur = stack;
	while (cur)
	{
		tmp = cur->next;
		while (tmp)
		{
			if (cur->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (0);
}

int	check_arg(char *a)
{
	int	i;

	i = 0;
	if (a == NULL)
		return (0);
	while (a[i])
	{
		if (a[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
