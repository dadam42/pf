#include "t_txt_field.h"
#include <stdlib.h>

int		t_txt_field_init(t_txt_field *field, t_txt_field_datas *datas)
{
	int cdx;
	int limit;

	if ((field->field = malloc(sizeof(char) * datas->field_size)))
	{
		cdx = 0;
		limit = datas->left_pad;
		while (cdx < limit)
			field->field[cdx++] = left_bg;
		limit += datas->content_size;
		while (cdx < limit)
			field->field[cdx++] = datas->content++;
		limit = datas->field_size;
		while (cdx < limit)
			field->field[cdx++] = right_bg;
		field->size = datas->field_size;
	}
	return (T_TXT_FIELD_INIT_ERROR);
}

void	t_txt_field_rls(t_txt_field *field)
{
	free(field->field);
}
