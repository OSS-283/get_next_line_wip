#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_struct
{
	char		read_buffer[BUFFER_SIZE];
	ssize_t		b_read;
	ssize_t		next_index;
}	t_gnl;

char		*get_next_line(int fd);
ssize_t		get_new_index(t_gnl *gnl);
char		*create_line(char *line, ssize_t newl_index, t_gnl *gnl);
char		*add_buffer_to_line(char *line, t_gnl *gnl);
ssize_t		ft_strlen(const char *s);
void		ft_strlcpy(char *src, char *dst, ssize_t dsize);
char		*ft_strjoin(char *s1, char *s2, ssize_t len);

#endif
