/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:47:24 by yukoc             #+#    #+#             */
/*   Updated: 2024/12/09 14:37:06 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		len;
	int		i;
	int		tmp;

	i = -1;
	len = 0;
	if (!str)
		return (-1);
	va_start(arguments, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_check_param(str[i + 1]))
		{
			tmp = ft_proc_param(&arguments, str[++i]);
			if (tmp == -1)
				return (-1);
			len += tmp - 1;
		}
		else if (ft_putchar(str[i]) == -1)
			return (-1);
		len++;
	}
	va_end(arguments);
	return (len);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_check_param(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 's' || c == '%'
		|| c == 'x' || c == 'X' || c == 'u' || c == 'p' || c == '\0'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_proc_param(va_list *arguments, char mod)
{
	if (mod == 'c')
		return (ft_putchar(va_arg((*arguments), int)));
	else if (mod == 'd' || mod == 'i')
		return (ft_proc_int(va_arg((*arguments), int)));
	else if (mod == 's')
		return (ft_proc_string(va_arg((*arguments), char *)));
	else if (mod == '%')
		return (ft_putchar('%'));
	else if (mod == 'x' || mod == 'X')
		return (ft_proc_hex(va_arg((*arguments), unsigned int), mod));
	else if (mod == 'u')
		return (ft_proc_unsigned(va_arg((*arguments), unsigned int)));
	else if (mod == 'p')
		return (ft_proc_pointer(va_arg((*arguments), unsigned long), 1));
	else if (mod == '\0' || mod == ' ')
		return (-1);
	else
		return (0);
}
