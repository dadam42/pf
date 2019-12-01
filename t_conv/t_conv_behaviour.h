/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_conv_behaviour.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 04:54:02 by damouyal          #+#    #+#             */
/*   Updated: 2019/12/01 14:56:22 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_UTIL_H
# define CONV_UTIL_H
# include <stdarg.h>

typedef struct s_conv	t_conv;
typedef struct s_out_buffer t_out_buffer;
typedef struct s_txt_field_datas	t_txt_field_datas;
typedef struct s_pf_format t_pf_format;
typedef void			(*t_format_rule)(t_conv *conv,t_pf_format *fmt);
typedef	int				(*t_init_conv)(t_conv *conv, va_list *pfargs);
typedef void				(*t_set_datas_content)(t_conv *conv, t_txt_field_datas *datas);
typedef int				(*t_bufferize_field)(t_conv *conv, t_out_buffer *buf,
											t_txt_field_datas *datas);
typedef struct		s_conv_behaviour
{
	t_format_rule			format_rule;
	t_init_conv				init;
	t_set_datas_content		set_datas_content;
	t_bufferize_field		bufferize_field;
}					t_conv_behaviour;

#endif
