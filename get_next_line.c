#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	gnl;
	char			*line;
	ssize_t			newl_index;

	line = NULL;
	newl_index = 0;

	while (42)
	{
		if (gnl.next_index >= gnl.b_read)
		{
			gnl.b_read = read(fd, gnl.read_buffer, BUFFER_SIZE);
			if (gnl.b_read <= 0)
				return (NULL);
			gnl.next_index = 0;
		}
		newl_index = get_new_index(&gnl);
		if (newl_index >= 0 || gnl.b_read < BUFFER_SIZE)
		{
			line = create_line(line, newl_index, &gnl);
			gnl.next_index = newl_index + 1;
			return (line);
		}
		line = add_buffer_to_line(line, &gnl);
		gnl.next_index = gnl.b_read;
	}
	return (line);
}

char	*add_buffer_to_line(char *line, t_gnl *gnl)
{
	if (line != NULL)
	{
		line = ft_strjoin(line, gnl->read_buffer, gnl->b_read);
		return (line);
	}
	else
	{
		line = malloc((gnl->b_read - gnl->next_index + 1) * sizeof (char));
		ft_strlcpy(gnl->read_buffer + gnl->next_index, line, gnl->b_read - gnl->next_index);
	}
	return(line);
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

char	*create_line(char *line, ssize_t newl_index, t_gnl *gnl)
{
	if (line != NULL)
	{
		line = ft_strjoin(line, gnl->read_buffer, newl_index);// AJOUTER ARG NEXT
		return(line);
	}
	else
	{
		line = malloc((newl_index - gnl->next_index + 1) * sizeof (char));
		if (!line)
			return (NULL);
		ft_strlcpy(gnl->read_buffer + gnl->next_index, line, newl_index - gnl->next_index);
	}
	return (line);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t len)
{
	char		*line;
	ssize_t		s1_len;
	ssize_t		i;

	i = 0;
	s1_len = ft_strlen(s1);
	line = malloc((s1_len + len + 1) * sizeof (char));
	if(!line)
	{
	//	free(s1);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		line[i] = s1[i];
		i++;
	}
	while (i <= s1_len + len)
	{
		line[i] = s2[i - s1_len];
		i++;
	}
	line[i] = '\0';
	//free(s1);
	return (line);
}


