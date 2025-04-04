/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:52:08 by yukoc             #+#    #+#             */
/*   Updated: 2025/03/22 18:25:52 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_int_min_max(char **argv)
{
	long	i;
	long	n;

	i = -1;
	while (argv[++i])
	{
		n = ft_atoi(argv[i]);
		if (n > 2147483647 || n < -2147483648)
			return (1);
	}
	return (0);
}

static int	is_short(char **argv)
{
	long	i;

	i = 0;
	while (argv[++i])
		if (ft_atoi(argv[i - 1]) >= ft_atoi(argv[i]))
			return (0);
	return (1);
}

static int	is_repeat_digit(int argc, char **argv)
{
	long	i;
	long	j;

	i = -1;
	while (argv[++i])
	{
		j = i;
		while (++j < argc)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
	}
	return (0);
}

static int	is_digit(char **argv)
{
	long	i;
	long	j;
	long	count;

	i = -1;
	count = 0;
	while (argv[++i])
	{
		j = 0;
		count = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			return (1);
		while (argv[i][j] == '0' && argv[i][j + 1] == '0')
			j++;
		while (argv[i][j] && ++count)
			if (argv[i][j] < '0' || argv[i][j++] > '9')
				return (1);
		if (count > 11)
			return (1);
	}
	return (0);
}

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
