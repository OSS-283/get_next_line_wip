#include "get_next_line.h"

ssize_t	get_new_index(t_gnl *gnl)
{
	char	*buffer;
	ssize_t	index;
	ssize_t	len;

	buffer = gnl->read_buffer + gnl->next_index;
	len = gnl->b_read - gnl->next_index;
	index = 0;
	while (index < len && buffer[index] != '\0')
	{
		if (buffer[index] == '\n')
		{
			return (index + gnl->next_index);
		}
		index++;
	}
	if (gnl->b_read < BUFFER_SIZE)
		return (index + gnl->next_index -1);
	return (-1);
}

void	ft_strlcpy(char *src, char *dst, ssize_t dsize)
{
	ssize_t	i;

	i = 0;
	dsize++;
	while (src[i] && i < dsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

ssize_t	ft_strlen(const char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

  /*--------------------------------*/
 /*--------------MAIN--------------*/
/*--------------------------------*/

/* int	main(void)
{
	int		fd = open("43_no_nl", O_RDONLY);

	if (fd == -1)
	{
		if (fd == -1)
			write(2, "Cannot open file.\n", 18);
		return (1);
	}
	char	*line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		// getchar();
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
} */
