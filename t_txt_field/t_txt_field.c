#include "t_txt_field.h"
#include <stdlib.h>

int		t_txt_field_init(t_txt_field *field, t_txt_field_datas *datas)
{
	int cdx;
	int limit;

	if ((field->my_field = malloc(sizeof(char) * datas->field_size)))
	{
		cdx = 0;
		limit = datas->left_pad;
		while (cdx < limit)
			field->my_field[cdx++] = datas->left_bg;
		limit += datas->content_size;
		while (cdx < limit)
			field->my_field[cdx++] = *datas->content++;
		limit = datas->field_size;
		while (cdx < limit)
			field->my_field[cdx++] = datas->right_bg;
		field->size = datas->field_size;
		field->datas = datas;
		return (T_TXT_FIELD_INIT_OK);
	}
	return (T_TXT_FIELD_INIT_ERROR);
}

void	t_txt_field_rls(t_txt_field *field)
{
	free(field->my_field);
}
