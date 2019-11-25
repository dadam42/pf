#include "t_string.h"
#include <stdlib.h>

void		rls_string(t_string *const tstr)
{
	free(tstr->content);
}

void		destroy_string(t_string *const tstr)
{
	if (tstr)
	{
		free(tstr->content);
		free(tstr);
	}
}
