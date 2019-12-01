/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_behaviour.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:23:07 by damouyal          #+#    #+#             */
/*   Updated: 2019/12/01 18:39:27 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_BEHAVIOUR_H
# define D_BEHAVIOUR_H
# include "conv.h"
# include "t_conv_behaviour.h"
# include "dummy_behaviour.h"
# include "t_conv_behaviour.h"
int d_init(t_conv *conv, va_list *pfargs);
void unsigned_num_set_datas_content(t_conv *conv, t_txt_field_datas *fdatas);
int unsigned_num_bufferize_field(t_conv *conv, t_out_buffer *buf, t_txt_field_datas *fdatas);
int prec_unsigned_num_bufferize_field(t_conv *conv, t_out_buffer *buf, t_txt_field_datas *fdatas);
#endif
