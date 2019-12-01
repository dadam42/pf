/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_behaviour.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:09:41 by damouyal          #+#    #+#             */
/*   Updated: 2019/12/01 14:58:52 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BHV_DUMMIES_H
# define BHV_DUMMIES_H
# include <stdarg.h>
# include "t_out_buffer.h"
# include "t_conv_behaviour.h"
# include "t_pf_format.h"

typedef struct s_conv	t_conv;

int dummy_init(t_conv *conv, va_list *pfargs);
void dummy_format_rule (t_conv *conv, t_pf_format *fmt);
int dummy_bufferize_field(t_conv *conv, t_out_buffer *buf,
							t_txt_field_datas *fdatas);
void dummy_set_datas_content(t_conv *conv, t_txt_field_datas *fdatas);
#endif
