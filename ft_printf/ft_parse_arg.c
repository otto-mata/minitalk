/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:09:15 by tblochet          #+#    #+#             */
/*   Updated: 2024/12/04 16:14:32 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uintlen(uint32_t n)
{
	int	sz;

	if (n == 0)
		return (1);
	sz = 0;
	while (n > 0)
	{
		sz++;
		n /= 10;
	}
	return (sz);
}

static char	*ft_itoa_unsigned(uint32_t n)
{
	int const	nlen = ft_uintlen(n);
	int			i;
	int			digit;
	char		*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = ft_calloc(nlen + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < nlen)
	{
		digit = n % 10;
		str[i++] = '0' + digit;
		n /= 10;
	}
	ft_strrev(str);
	return (str);
}

static char	*ft_parse_string(char *s)
{
	if (!s)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}

static char	*ft_parse_char(char c)
{
	char	buf[2];

	buf[0] = c;
	buf[1] = 0;
	return (ft_strdup(buf));
}

char	*ft_parse_arg(char flag, va_list args)
{
	char const	*hex;
	char		*parsed;

	hex = "0123456789abcdef";
	if (flag == 'c')
		parsed = ft_parse_char(va_arg(args, int) % 256);
	else if (flag == 's')
		parsed = ft_parse_string(va_arg(args, char *));
	else if (flag == 'u')
		parsed = ft_itoa_unsigned(va_arg(args, uint32_t));
	else if (flag == 'i' || flag == 'd')
		parsed = ft_itoa(va_arg(args, int));
	else if (flag == 'x')
		parsed = ft_itoa_base_int(va_arg(args, uint32_t), hex);
	else if (flag == 'p')
		parsed = ft_specialjoin("0x", ft_itoa_base(va_arg(args, uint64_t),
					hex));
	else if (flag == 'X')
		parsed = ft_itoa_base_int(va_arg(args, uint32_t), "0123456789ABCDEF");
	else if (flag == '%')
		parsed = ft_strdup("%");
	else
		parsed = ft_strdup("");
	return (parsed);
}
