/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:03:37 by yukoc             #+#    #+#             */
/*   Updated: 2024/11/13 14:39:20 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_proc_int(int i)
{
	int		len;
	long	nb;
	int		tmp;

	len = 0;
	if (i == 0)
		return (write(1, "0", 1));
	nb = i;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		nb *= -1;
	}
	if (nb > 9)
	{
		tmp = ft_proc_int(nb / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789"[nb % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_proc_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_proc_hex(unsigned int hex, char mod)
{
	int	len;
	int	tmp;

	len = 0;
	if (hex >= 16)
	{
		tmp = ft_proc_hex(hex / 16, mod);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (mod == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[hex % 16], 1) == -1)
			return (-1);
	}
	if (mod == 'x')
	{
		if (write(1, &"0123456789abcdef"[hex % 16], 1) == -1)
			return (-1);
	}
	return (len + 1);
}

int	ft_proc_unsigned(unsigned int i)
{
	int	len;
	int	tmp;

	len = 0;
	if (i > 9)
	{
		tmp = ft_proc_unsigned(i / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789"[i % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_proc_pointer(unsigned long addr, int i)
{
	int	len;
	int	tmp;

	if (addr == 0)
		return (ft_proc_nullptr());
	len = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		len += 2;
	}
	if (addr >= 16)
	{
		tmp = ft_proc_pointer(addr / 16, i);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789abcdef"[addr % 16], 1) == -1)
		return (-1);
	return (len + 1);
}
