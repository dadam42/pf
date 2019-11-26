#ifndef T_TXT_FIELD_H
# define T_TXT_FIELD_H
# define T_TXT_FIELD_INIT_OK 1
# define T_TXT_FIELD_INIT_ERROR 0

typedef struct s_txt_field_datas
{
	int		content_size;
	char	*content;
	char	left_bg;
	char	right_bg;
	int		left_pad;
	int		field_size;
}				t_txt_field_datas;

typedef struct s_txt_field
{
	char				*my_field;
	int					size;
	t_txt_field_datas	*datas;
}				t_txt_field;

int		t_txt_field_init(t_txt_field *field, t_txt_field_datas *datas);
void	t_txt_field_rls(t_txt_field *field);
#endif
