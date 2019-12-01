/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 22:57:01 by damouyal          #+#    #+#             */
/*   Updated: 2019/12/01 16:54:53 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CONV_H
# define T_CONV_H
# include "t_pf_format.h"
# include "t_txt_field.h"
# include "t_out_buffer.h"
# include <stdarg.h>
# include <stddef.h>
# include "t_conv_behaviour.h"
# include "dummy_behaviour.h"
# include "t_pf_format.h"
# define CONV_EXEC_OK 1
# define CONV_EXEC_ERROR 0
# define CONV_INIT_OK 1
# define CONV_INIT_ERROR 0
# define CONV_NO_DISPLAY 1
# define CONV_YES_DISPLAY 2

struct					s_conv
{
	t_conv_behaviour	bhv;
	void				*com;
	t_pf_format			*fmt;
	t_txt_field			field;
};

int					conv_init(t_conv *conv, t_pf_format *fmt,
								va_list *pfargs);
void				set_field_size(t_conv *conv, t_txt_field_datas *fdatas);
#endif
