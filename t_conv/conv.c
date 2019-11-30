#include "conv.h" 
#include "t_pf_format.h"
#include "t_out_buffer.h"
#include "format_rules.h"
#include <stdarg.h>

static void		set_conv_behaviour(t_conv *conv, t_pf_format *fmt)
{
	static char 	pf_conv_string[PF_CONV_COUNT + 1] = PF_CONV_STRING;
	const t_conv	pf_conv_behaviours[PF_CONV_COUNT] = PF_CONV_BEHAVIOURS;
	const t_conv	default_conv = PF_DEFAULT_BEHAVIOUR;
	int				convdx;

	convdx = 0;
	while (pf_conv_string[convdx])
		if (pf_conv_string[convdx] == fmt->conv_char)
		{
			*conv = pf_conv_behaviours[convdx];
			return;
		}
		else
			convdx++;
	*conv = default_conv;
}

int conv_init(t_conv *conv, t_pf_format *fmt, va_list *pfargs)
{
	format_general_rule(fmt);
	set_conv_behaviour(conv, fmt);
	conv->fmt = fmt;
	conv->com = NULL;
	return (conv->init(conv, pfargs));
}
