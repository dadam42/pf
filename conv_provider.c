#include "pf_conv_provider.h"

t_convdx pf_get_convdx(char const c)
{
	static char pf_conv_string[] = PF_CONV_STRING;
	t_convdx convdx;

	convdx = 0;
	while (pf_conv_string[convdx] > 0)
		if (pf_conv_string[convdx] == c)
			break;
		else
			convdx++;
	return (convdx);
}
