/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:52:08 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/21 13:04:55 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_args(int argc, char **argv)
{
	char	**tmp;
	long	n;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
			return (ft_putendl_fd("Error", 2), 2);
		n = ft_word_counter(argv[1], ' ');
		if (is_digit(tmp) || is_repeat_digit(n, tmp)
			|| is_int_min_max(tmp) || n == 0)
			return (ft_free_all(tmp), ft_putendl_fd("Error", 2), 2);
		else if (n == 1 || is_short(tmp))
			return (ft_free_all(tmp), 0);
		ft_free_all(tmp);
		return (1);
	}
	if (is_digit(argv + 1) || is_repeat_digit(argc - 1, argv + 1)
		|| is_int_min_max(argv + 1))
		return (ft_putendl_fd("Error", 2), 2);
	else if (is_short(argv + 1))
		return (0);
	return (1);
}
