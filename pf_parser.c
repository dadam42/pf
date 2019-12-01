/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:08:10 by damouyal          #+#    #+#             */
/*   Updated: 2019/12/01 16:20:02 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_parser.h"
#include "t_out_buffer.h"
#include "t_txt_field.h"
#include "t_pf_format.h"
#include "conv.h"
#include "libft.h"

static int parse_width(char const **str, t_pf_format *fmt, va_list *pfargs)
{
	if (!**str)
		return (PF_PARSE_ERROR);
	if (ft_isdigit(**str) || **str == '*')
	{
		fmt->flags |= FMT_WIDTH;
		if (**str == '*')
		{
			fmt->width = va_arg(*pfargs, int);
			(*str)++;
		}
		else
			fmt->width = ft_otg_atoi(str);
	}
	return (PF_PARSE_OK);
}

static int parse_prec(char const **str, t_pf_format *fmt, va_list *pfargs)
{
	if (!**str)
		return (PF_PARSE_ERROR);
	if (**str == '.')
	{
		(*str)++;
		if (!**str)
			return (PF_PARSE_ERROR);
		fmt->flags |= FMT_PREC;
		if (**str == '*')
		{
			fmt->prec = va_arg(*pfargs, int);
			(*str)++;
		}
		else
			fmt->prec = ft_otg_atoi(str);
	}
	return (PF_PARSE_OK);
}

static int parse_flags(char const **str, t_pf_format *fmt)
{
	if (!**str)
		return (PF_PARSE_ERROR);
	while((**str == '-' || **str == '0')
			&& !((fmt->flags & FMT_MINUS) && (fmt->flags & FMT_ZERO)))
	{
		if (**str == '-')
			fmt->flags |= FMT_MINUS;
		else
			fmt->flags |= FMT_ZERO;
		(*str)++;
	}
	while (**str == '-' || **str == '0')
		(*str)++;
	return (PF_PARSE_OK);
}

static int pf_exec_conv(t_conv *conv, t_pf_format *fmt,
		t_out_buffer *buf, va_list *pfargs)
{
	t_txt_field_datas fdatas;
	int		ret_init;

	ft_bzero(&fdatas, sizeof(fdatas));
	while (1)
	{
		if ((ret_init = conv_init(conv, fmt, pfargs)) == CONV_INIT_ERROR)
			break;
		if (ret_init == CONV_YES_DISPLAY)
		{
			if (conv->fmt->flags & FMT_ZERO)
				fdatas.left_bg = '0';
			else
				fdatas.left_bg = ' ';
			fdatas.right_bg = ' ';
			conv->bhv.set_datas_content(conv, &fdatas);
			set_field_size(conv, &fdatas);
			if (conv->bhv.bufferize_field(conv, buf, &fdatas) != CONV_EXEC_OK)
				break;
		}
		return (PF_PARSE_OK);
	}
	return (PF_PARSE_ERROR);
}

int pf_parse_exec(char const **str, t_out_buffer *buf, va_list *pfargs)
{
	t_pf_format fmt;
	char const *ostr;
	t_conv	conv;

	ft_bzero(&fmt, sizeof(t_pf_format));
	ostr = (*str)++;
	while (1)
	{
		if (parse_flags(str, &fmt) == PF_PARSE_ERROR
				|| parse_width(str, &fmt, pfargs) == PF_PARSE_ERROR
				|| parse_width(str, &fmt, pfargs) == PF_PARSE_ERROR
				|| parse_prec(str, &fmt, pfargs) == PF_PARSE_ERROR)
			break;
		if (!(fmt.conv_char = **str))
			break;
		return (pf_exec_conv(&conv, &fmt, buf, pfargs));
	}
	t_out_buffer_ize(buf, ostr, *str);
	return (PF_PARSE_OK);
}
