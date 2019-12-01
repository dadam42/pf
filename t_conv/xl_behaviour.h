#ifndef XL_BEHAVIOUR_H
# define XL_BEHAVIOUR_H
# include "conv.h"
# include "t_conv_behaviour.h"
# include "dummy_behaviour.h"
# include "t_conv_behaviour.h"
const t_conv_behaviour xl_behaviour = 
{	
	.format_rule = &dummy_format_rule,
	.init = &dummy_init,
	.set_datas_content = &dummy_set_datas_content,
	.bufferize_field = &dummy_bufferize_field
};
#endif
