/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_num.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 15:36:20 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 13:56:22 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <limits.h>

int	print_num(int n)
{
	ft_putnbr(n);
	return (ft_intlen(n) + (n < 0));
}

int	print_unsigned(long n)
{
	if (n < 0)
		n = UINT_MAX - -n;
	ft_putnbr(n);
	return (ft_intlen(n));
}
