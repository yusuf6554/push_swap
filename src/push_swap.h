/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:31:33 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/09 14:19:04 by yukoc            ###   ########.fr       */
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

int		check_args(int argc, char **argv);
void	free_stacks(t_push_swap *ps);
int		ft_lst_node_add_back(t_node **lst, t_node *new);
int		ft_lst_size(t_node *lst);
void	r(t_stack **stack);
void	s(t_stack **stack);
void	rr(t_stack **stack);
void	ra(t_stack **stack);
void	sa(t_stack **stack);
void	pa(t_push_swap *ps);
void	rra(t_stack **stack);
void	rb(t_stack **stack);
void	sb(t_stack **stack);
void	pb(t_push_swap *ps);
void	rrb(t_stack **stack);
void	r(t_stack **stack);
void	s(t_stack **stack);
void	rr(t_stack **stack);
void	r_all(t_push_swap *ps, int flag);
void	s_all(t_push_swap *ps, int flag);
void	rr_all(t_push_swap *ps, int flag);
void	ss_push_a(t_push_swap *ps);
void	sb_push_a(t_push_swap *ps, int min, int max);
void	sa_push_b(t_push_swap *ps, int min, int max);

#endif