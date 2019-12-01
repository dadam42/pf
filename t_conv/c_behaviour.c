#include "c_behaviour.h"
#include "t_txt_field.h"
#include "t_out_buffer.h"
#include "t_pf_format.h"

int c_init(t_conv *conv, va_list *pfargs)
{
	static char pfarg = 0;

	pfarg = (char)va_arg(*pfargs, int);
	conv->com = &pfarg;
	return (CONV_YES_DISPLAY);
}

void c_set_datas_content(t_conv *conv, t_txt_field_datas *fdatas)
{
	fdatas->content = conv->com;
	fdatas->content_size = 1;
	if ((conv->fmt->flags & FMT_PREC) && fdatas->content_size > conv->fmt->prec)
		fdatas->content_size = conv->fmt->prec;
}
