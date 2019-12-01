#include "format_rules.h"
#include "t_pf_format.h"

void	format_general_rule(t_pf_format *fmt)
{
	if ((fmt->flags & FMT_PREC) && (fmt->prec < 0))
		fmt->flags &= ~FMT_PREC;
	if ((fmt->flags & FMT_WIDTH) && (fmt->width < 0))
	{
		fmt->flags |= FMT_MINUS;
		fmt->width = -fmt->width;
	}
	if (fmt->flags & FMT_MINUS)
		fmt->flags &= ~FMT_ZERO;
}

void	format_numeric_rule(t_pf_format *fmt)
{
	if (fmt->flags & FMT_PREC)
		fmt->flags &= ~FMT_ZERO;
}
