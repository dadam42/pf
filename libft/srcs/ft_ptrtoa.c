/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:24:53 by damouyal          #+#    #+#             */
/*   Updated: 2019/11/13 10:35:35 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_setup(uintptr_t d, unsigned short mbase, uintptr_t *div)
{
	size_t	len;

	*div = 1;
	len = 0;
	while (d / *div >= mbase)
	{
		*div *= mbase;
		len++;
	}
	return (malloc((len + 1) * sizeof(char)));
}

char		*ft_ptrtoa(uintptr_t d)
{
	static char		*base = "0123456789abcdef";
	uintptr_t		div;
	char			*fwd_ret;
	char			*ret;
	uintptr_t		q;

	if ((ret = ft_setup(d, 16, &div)))
	{
		fwd_ret = ret;
		while (div > 0)
		{
			q = d / div;
			*fwd_ret++ = base[q];
			d -= q * div;
			div /= 16;
		}
		*fwd_ret = 0;
		return (ret);
	}
	return (NULL);
}
