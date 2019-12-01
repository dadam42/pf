/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_behaviours_cat.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 22:55:28 by damouyal          #+#    #+#             */
/*   Updated: 2019/12/01 15:52:34 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_BEHAVIOURS_CAT_H
# define CONV_BEHAVIOURS_CAT_H
# include "s_behaviour.h"
# include "i_behaviour.h"
# include "u_behaviour.h"
# include "d_behaviour.h"
# include "p_behaviour.h"
# include "pe_behaviour.h"
# include "c_behaviour.h"
# include "xu_behaviour.h"
# include "xl_behaviour.h"
# define CONV_STRING "siudp%cxX"
# define CONV_COUNT 9

const t_conv_behaviour s_behaviour = 
{
	.format_rule = &dummy_format_rule,
	.init = &s_init,
	.set_datas_content = &s_set_datas_content,
	.bufferize_field = &s_bufferize_field
};
const t_conv_behaviour c_behaviour = 
{	
	.format_rule = &dummy_format_rule,
	.init = &c_init,
	.set_datas_content = &c_set_datas_content,
	.bufferize_field = &s_bufferize_field
};
#endif
