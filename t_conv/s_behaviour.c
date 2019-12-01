/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_behaviour.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 13:58:54 by damouyal          #+#    #+#             */
/*   Updated: 2019/12/01 15:05:50 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_behaviour.h"
#include "t_txt_field.h"
#include "t_out_buffer.h"
#include "t_pf_format.h"
#include "libft.h"

int	s_init(t_conv *conv, va_list *pfargs)
{
	conv->field.my_field = va_arg(*pfargs, char*);
	return (CONV_YES_DISPLAY);
}

int	s_bufferize_field(t_conv *conv, t_out_buffer *buf,
					t_txt_field_datas *fdatas)
{
	if (t_txt_field_init(&conv->field, fdatas) != T_TXT_FIELD_INIT_OK)
		return (CONV_EXEC_ERROR);
	t_out_buffer_ize(buf, conv->field.my_field,
			conv->field.my_field + conv->field.size);
	t_txt_field_rls(&conv->field);
	return (CONV_EXEC_OK);
}

void s_set_datas_content(t_conv *conv, t_txt_field_datas *fdatas)
{
	static char *defstr = "(null)";

	fdatas->content = (conv->field.my_field ? conv->field.my_field : defstr);
	fdatas->content_size = ft_strlen(fdatas->content);
	if ((conv->fmt->flags & FMT_PREC) && fdatas->content_size > conv->fmt->prec)
		fdatas->content_size = conv->fmt->prec;
}
