/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 22:57:11 by damouyal          #+#    #+#             */
/*   Updated: 2019/12/01 21:27:01 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv.h"
#include "conv_behaviours_cat.h" 
#include "t_pf_format.h"
#include "t_out_buffer.h"
#include "format_rules.h"
#include <stdarg.h>

static void		set_conv_behaviour(t_conv *conv, t_pf_format *fmt)
{
	static const char 				conv_string[CONV_COUNT + 1] = CONV_STRING;
	const t_conv_behaviour	conv_behaviours[CONV_COUNT] = {s_behaviour,
		i_behaviour, u_behaviour, d_behaviour, p_behaviour, pe_behaviour,
		c_behaviour, xu_behaviour, xl_behaviour};
	const t_conv_behaviour	default_behaviour = {
		.format_rule = &dummy_format_rule, .init = &dummy_init,
		.set_datas_content = &dummy_set_datas_content,
		.bufferize_field = &dummy_bufferize_field};
	int						convdx;

	convdx = 0;
	while (conv_string[convdx])
		if (conv_string[convdx] == fmt->conv_char)
		{
			conv->bhv = conv_behaviours[convdx];
			return;
		}
		else
			convdx++;
	conv->bhv = default_behaviour;
}

int conv_init(t_conv *conv, t_pf_format *fmt, va_list *pfargs)
{
	format_general_rule(fmt);
	conv->fmt = fmt;
	conv->com = NULL;
	set_conv_behaviour(conv, fmt);
	return (conv->bhv.init(conv, pfargs));
}

void set_field_size(t_conv *conv, t_txt_field_datas *fdatas)
{
	if ((conv->fmt->flags & FMT_WIDTH) 
		&& conv->fmt->width > fdatas->field_size)
	{
		if (!(conv->fmt->flags & FMT_MINUS))
			fdatas->left_pad += conv->fmt->width - fdatas->field_size;
		fdatas->field_size += conv->fmt->width;
	}
}
