/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:31:33 by yukoc             #+#    #+#             */
/*   Updated: 2025/04/17 15:11:16 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}				t_stack;

void	free_stack(t_stack **stack);
int		stack_init(int argc, char **argv, t_stack **stack);
t_stack	*ft_node_last(t_stack **stack);
int		is_sorted(t_stack *stack);
int		get_len(t_stack *stack);
void	handle_error(t_stack **stack);
int		is_reverse_sorted(t_stack *stack);
void	sort_index(t_stack **stack);
int		find_pivot(t_stack **stack, int len);
int		sort(t_stack **a, t_stack **b, int len);
void	sort_three_a(t_stack **stack);
void	sort_three_b(t_stack **stack);
void	sort_little(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
int		ft_is_digit(char *str);
int		ft_is_valid_integer(char *str);
int		check_for_duplicates(t_stack *stack);
int		check_arg(char *a);

#endif