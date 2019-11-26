#include "t_pf_format.h"
#include "t_out_buffer.h"
#include <stdarg.h>
#include "pf_conv_provider.h"
#include "pf_format_util.h"
#include "t_txt_field.h"

static	int exec(t_exec_datas *datas, t_pf_format *fmt,
				t_out_buffer *buf, va_list *pfargs)
{
	t_txt_field *field;

	datas->normalize(fmt);
	if (!datas->get_field(fmt, pfargs))
		return (FMT_EXEC_ERROR);
	datas->decorate(fmt, field);
	if (t_out_buffer_ize(buf, field->my_field, field->size)
		== T_OUT_BUFFERIZE_ERROR)
		return (FMT_EXEC_ERROR);
	datas->end(field);
	return (FMT_EXEC_OK);
}

void	pf_format_normalize(t_pf_format *fmt)
{
	if ((fmt->flags & FMT_WIDTH) && (fmt->width < 0))
	{
		fmt->width = -fmt->width;
		fmt->flags |= FMT_MINUS;
	}
	if ((fmt->flags & FMT_PREC) && (fmt->prec < 0))
		fmt->flags &= ~FMT_PREC;
	if (fmt->flags & FMT_MINUS)
		fmt->flags &= ~FMT_ZERO;
}

int		pf_format_exec(t_pf_format *fmt, t_out_buffer *buf, va_list *pfargs)
{	
	t_exec_datas exec_datas;

	pf_format_normalize(fmt);
	exec_datas.normalize = pf_get_normalize(fmt->convdx);
	exec_datas.get_field = pf_get_get_field(fmt->convdx);
	exec_datas.decorate = pf_get_decorate(fmt->convdx);
	return (exec(&exec_datas, fmt, buf, pfargs));
}
