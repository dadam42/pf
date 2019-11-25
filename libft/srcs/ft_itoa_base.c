/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:38:14 by damouyal          #+#    #+#             */
/*   Updated: 2019/11/13 10:34:40 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_setup(int d, unsigned short mbase, int *div_sign)
{
	size_t	len;

	div_sign[1] = 1;
	if (d >= 0)
		d = -d;
	else
		div_sign[1] = -1;
	div_sign[0] = 1;
	len = 0;
	while (d / div_sign[0] <= -mbase)
	{
		div_sign[0] *= mbase;
		len++;
	}
	return (malloc((len + 1 + (div_sign[1] == -1 ? 1 : 0)) * sizeof(char)));
}

char		*ft_itoa_base(int d, char *base)
{
	unsigned short	mbase;
	int				div_sign[2];
	char			*fwd_ret;
	char			*ret;
	int				q;

	if (!base)
		return (NULL);
	mbase = ft_strlen(base);
	if (mbase > 1 && (ret = ft_setup(d, mbase, div_sign)))
	{
		fwd_ret = ret;
		if (div_sign[1] == -1)
			*fwd_ret++ = '-';
		while (div_sign[0] > 0)
		{
			q = d / div_sign[0];
			*fwd_ret++ = base[q];
			d -= q * div_sign[0];
			div_sign[0] /= mbase;
		}
		*fwd_ret = 0;
		return (ret);
	}
	return (NULL);
}
