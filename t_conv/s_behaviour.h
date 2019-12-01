/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_behaviour.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 13:29:47 by damouyal          #+#    #+#             */
/*   Updated: 2019/12/01 14:47:12 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_BEHAVIOUR_H
# define S_BEHAVIOUR_H
# include "conv.h"
# include "t_conv_behaviour.h"
# include "dummy_behaviour.h"
# include <stdarg.h>

int		s_init(t_conv *conv, va_list *pfargs);
void	s_set_datas_content(t_conv *conv, t_txt_field_datas *datas);
int		s_bufferize_field(t_conv *conv, t_out_buffer *buf,
						t_txt_field_datas *fdatas);
#endif
