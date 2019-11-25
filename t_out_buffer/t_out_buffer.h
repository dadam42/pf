#ifndef T_OUT_BUFFER_H
# define T_OUT_BUFFER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif
# define T_OUT_BUFFERIZE_ERROR -1
# define T_OUT_BUFFERIZE_OK 1

typedef int		t_count;
typedef int		t_idx;
typedef struct	s_out_buffer
{
	char	buf[BUFFER_SIZE];
	t_idx	idx;
	t_count	count;
	int		fd;
}				t_out_buffer;

void			t_out_buffer_init(t_out_buffer *buf, int fd);
t_count			t_out_buffer_ize(t_out_buffer *buf, char const *start,
									char const *end);
t_count			t_out_buffer_flush(t_out_buffer *buf);
#endif
