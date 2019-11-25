/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:28:12 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/15 15:29:56 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_alloc;
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_alloc = len_s1 + len_s2 + 1;
	if ((ret = malloc(len_alloc * sizeof(char))))
	{
		ft_memcpy(ret, s1, len_s1);
		ft_memcpy(ret + len_s1, s2, len_s2 + 1);
	}
	return (ret);
}
