#include "t_out_buffer.h"
#include <unistd.h>

static int		my_write(int fd, char const* start, int	len)
{
	int wret;
	int owret;

	wret = 0;
	owret = 0;
	while ((wret += write(fd, start + wret, len - wret)) 
		&& (wret < len))
		if (wret <= owret)
			return (T_OUT_BUFFERIZE_ERROR);
		else
			owret = wret;
	return (T_OUT_BUFFERIZE_OK);
}

void			t_out_buffer_init(t_out_buffer *buf, int fd)
{
	buf->fd = fd;
	buf->count = 0;
	buf->idx = 0;	
}

t_count			t_out_buffer_ize(t_out_buffer *buf, char const *start, char const *end)
{
	t_idx	oidx;

	while(1)
	{
		oidx = buf->idx;
		while (buf->idx < BUFFER_SIZE && start < end)
			buf->buf[buf->idx++] = *start++;
		buf->count += buf->idx - oidx;
		if (start == end)
			return (buf->count);
		if (my_write(buf->fd, buf->buf, BUFFER_SIZE) == T_OUT_BUFFERIZE_ERROR)
			break;
		buf->idx = 0;
		while (start + BUFFER_SIZE <= end)
			if (my_write(buf->fd, start, BUFFER_SIZE) == T_OUT_BUFFERIZE_ERROR)
				break;
			else
			{
				start += BUFFER_SIZE;
				buf->count += BUFFER_SIZE;
			}
	}
	return (T_OUT_BUFFERIZE_ERROR);
}

t_count			t_out_buffer_flush(t_out_buffer *buf)
{
	if (my_write(buf->fd, buf->buf, buf->idx) == T_OUT_BUFFERIZE_ERROR)
		return (T_OUT_BUFFERIZE_ERROR);
	buf->idx = 0;
	return (buf->count);
}
