/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_behaviour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:09:48 by damouyal          #+#    #+#             */
/*   Updated: 2019/12/01 14:59:12 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dummy_behaviour.h"
#include "conv.h"
#include "t_out_buffer.h"

int dummy_init(t_conv *conv, va_list *pfargs)
{
	(void)conv;
	(void)pfargs;
	return (CONV_INIT_OK);
}

void dummy_format_rule (t_conv *conv, t_pf_format *fmt)
{
	(void)fmt;
	(void)conv;
}

int dummy_bufferize_field(t_conv *conv, t_out_buffer *buf,
							t_txt_field_datas *fdatas)
{
	(void)fdatas;
	(void)conv;
	(void)buf;
	return (CONV_EXEC_OK);
}

void	 dummy_set_datas_content(t_conv *conv, t_txt_field_datas *datas)
{
	(void)conv;
	(void)datas;
}
