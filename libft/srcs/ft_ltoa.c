/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:28:12 by damouyal          #+#    #+#             */
/*   Updated: 2019/11/12 18:30:43 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_builda_ltoa(long n, int sign, long div, size_t dgt_cnt)
{
	long		q;
	char		*ret;
	char		*fwd_ret;

	if ((ret = malloc((dgt_cnt + 1 + (sign == -1 ? 1 : 0)) * sizeof(char))))
	{
		fwd_ret = ret;
		if (sign == -1)
			*fwd_ret++ = '-';
		while (div > 0)
		{
			q = n / div;
			*fwd_ret++ = '0' - q;
			n -= q * div;
			div /= 10;
		}
		*fwd_ret = 0;
	}
	return (ret);
}

char		*ft_ltoa(long n)
{
	long		div;
	int			sign;
	int			dgt_cnt;

	sign = 1;
	if (n >= 0)
		n = -n;
	else
		sign = -1;
	div = 1;
	dgt_cnt = 0;
	while (n / div <= -10)
	{
		div *= 10;
		dgt_cnt++;
	}
	return (ft_builda_ltoa(n, sign, div, dgt_cnt));
}
