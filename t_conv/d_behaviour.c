#include "d_behaviour.h"
#include "t_txt_field.h"
#include "t_out_buffer.h"
#include "t_pf_format.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include "dummy_behaviour.h"
#include "s_behaviour.h"

int d_init(t_conv *conv, va_list *pfargs)
{
	static char sign = 0;
	int d = 0;

	d = va_arg(*pfargs, int);
	if (!(conv->field.my_field = ft_itoa(d)))
		return (CONV_INIT_ERROR);
	conv->format_rule(conv->fmt);
	if (d < 0)
	{
		conv->bhv.set_datas_content = &dummy_set_datas_content;
		conv->bhv.bufferize_field = &dummy_bufferize_field;
		sign = '-';
		conv->com = &sign;
	}
	return (CONV_YES_DISPLAY);
}

void signed_num_set_datas_content(t_conv *conv, t_txt_field_datas *fdatas)
{
	static char sign = 0;

	sign = *conv->com;
	conv->com = 0;
	conv->field.my_field++;
	fdatas->left_pad++;
	fdatas->field_size++;
	unsigned_num_set_datas_content(conv, fdatas);
	if (conv->com)
		conv->bhv.bufferize_field = signed_num_bufferize_field;
	else
		conv->bhv.bufferize_field = prec_signed_num_bufferize_field;
}

void unsigned_num_set_datas_content(t_conv *conv, t_txt_field_datas *fdatas)
{
	static char need_prec;

	fdatas->content = conv->field.my_field;
	fdatas->content_size = ft_strlen(fdatas->content);
	if ((conv->fmt->flags & FMT_PREC) && conv->fmt->prec > fdatas->content_size)
	{
		conv->com = &need_prec;
		fdatas->field_size += conv->fmt->prec;
		conv->bhv.bufferize_field = &prec_unsigned_num_bufferize_field;
		fdatas->left_pad += conv->fmt->prec - fdatas->content_size;
	}
	else
		fdatas->field_size = fdatas->content_size;
}

int unsigned_num_bufferize_field(t_conv *conv, t_out_buffer *buf, t_txt_field_datas *fdatas)
{
	int ret;
	char	*to_free;
	
	to_free = fdatas->content;
	ret = s_bufferize_field(conv, buf, fdatas);
	free(to_free);
	return (ret);
}

int prec_unsigned_num_bufferize_field(t_conv *conv, t_out_buffer *buf, t_txt_field_datas *fdatas)
{
	char *ins;
	int ret;
	char *to_free;
	int limit;

	to_free = fdatas->content;
	if (t_txt_field_init(&conv->field, fdatas) != T_TXT_FIELD_INIT_OK)
		return (CONV_EXEC_ERROR);
	ins = (conv->fmt->flags & FMT_MINUS ? conv->field.my_field 
		: conv->field.my_field + (conv->field.size - conv->fmt->prec));
	limit = conv->fmt->prec - fdatas->content_size;
	while (limit-- > 0)
		*ins++ = '0';
	ret = t_out_buffer_ize(buf, conv->field.my_field, conv->field.my_field
		+ conv->field.size);
	t_txt_field_rls(&conv->field);
	free(to_free);	
	if (ret == T_OUT_BUFFERIZE_ERROR)
		return (CONV_EXEC_ERROR);
	return (CONV_EXEC_OK);
}
