#include "pf_parser.h"
#include "t_out_buffer.h"
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
	while((**str == '-' || **str == '*')
		&& !(fmt->flags & FMT_MINUS) && !(fmt->flags & FMT_ZERO))
	{
		if (**str == '-')
			fmt->flags |= FMT_MINUS;
		else
			fmt->flags |= FMT_ZERO;
		(*str)++;
	}
	while (**str == '-' || **str == '+')
		(*str)++;
	return (PF_PARSE_OK);
}

static int parse_conv(char const **str, t_pf_format *fmt)
{
	if (!(fmt->conv_char == **str))
		return (PF_PARSE_ERROR);
	return (PF_PARSE_OK);
}

int pf_parse_exec(char const **str, t_out_buffer *buf, va_list *pfargs)
{
	t_pf_format fmt;
	char const *ostr;
	t_conv	conv;

	ft_bzero(&fmt, sizeof(t_pf_format));
	ostr = *str;
	while (1)
	{
		if (parse_flags(str, &fmt) == PF_PARSE_ERROR
			|| parse_width(str, &fmt, pfargs) == PF_PARSE_ERROR
			|| parse_width(str, &fmt, pfargs) == PF_PARSE_ERROR
			|| parse_prec(str, &fmt, pfargs) == PF_PARSE_ERROR
			|| parse_conv(str, &fmt) == PF_PARSE_ERROR)
			break;
		if (conv_init(&conv, &fmt, pfargs) == CONV_INIT_ERROR
			|| conv.exec(&conv, buf) == CONV_EXEC_ERROR)
			return (PF_PARSE_ERROR);
		return (PF_PARSE_OK);
	}
	t_out_buffer_ize(buf, ostr, *str);
	return (PF_PARSE_OK);
}
