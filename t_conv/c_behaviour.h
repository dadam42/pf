/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_behaviour.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:33:24 by damouyal          #+#    #+#             */
/*   Updated: 2019/12/01 15:51:53 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_BEHAVIOUR_H
# define C_BEHAVIOUR_H
# include "conv.h"
# include "t_conv_behaviour.h"
# include "dummy_behaviour.h"
# include "t_conv_behaviour.h"

int c_init(t_conv *conv, va_list *pfargs);
void c_set_datas_content(t_conv *conv, t_txt_field_datas *fdatas);
#endif
