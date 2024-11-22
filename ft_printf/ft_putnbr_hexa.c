/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:34:36 by mbelkass          #+#    #+#             */
/*   Updated: 2024/11/22 06:20:33 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_to_hex(unsigned int nmb, char *bu, const char *hex, int *l)
{
	int				i;

	i = 8;
	bu[i--] = '\0';
	while (nmb > 0)
	{
		bu[i--] = hex[nmb % 16];
		nmb = nmb / 16;
		(*l)++;
	}
}

int	ft_putnbr_hexa(int n, char type)
{
	const char	*hexdigits[2];
	int			len;
	char		buffer[9];
	const char	*hexdigits_ptr;

	len = 0;
	hexdigits[0] = "0123456789abcdef";
	hexdigits[1] = "0123456789ABCDEF";
	if (type == 'x')
		hexdigits_ptr = hexdigits[0];
	else
		hexdigits_ptr = hexdigits[1];
	buffer[8] = '\0';
	if (n == 0)
		return (write(1, "0", 1));
	convert_to_hex((unsigned int)n, buffer, hexdigits_ptr, &len);
	return (write(1, &buffer[8 - len], len));
}
