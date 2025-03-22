/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:31:33 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/22 18:21:45 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*nodes;
	int		size;
}				t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
}				t_push_swap;

typedef struct s_three_values
{
	int	first;
	int	second;
	int	third;
}				t_three_values;

int	check_args(int argc, char **argv);

#endif