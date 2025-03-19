/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:31:33 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/19 14:54:59 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_push_swap
{
	char	**split;
	char	**argv;
	int		argc;
	int		*stack_a;
	int		*stack_b;
	int		size;
}				t_push_swap;

#endif