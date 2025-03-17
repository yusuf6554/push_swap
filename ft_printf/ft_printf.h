/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukoc <yukoc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:47:56 by yukoc             #+#    #+#             */
/*   Updated: 2024/12/09 14:37:16 by yukoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_check_param(char c);
int		ft_proc_param(va_list *arguments, char mod);

int		ft_proc_int(int i);
int		ft_proc_string(char *str);
int		ft_proc_hex(unsigned int hex, char mod);
int		ft_proc_unsigned(unsigned int i);
int		ft_proc_pointer(unsigned long addr, int i);
int		ft_proc_nullptr(void);

#endif
