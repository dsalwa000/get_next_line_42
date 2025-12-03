#ifndef GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define GET_NEXT_LINE_H

#ifndef BUFFOR_SIZE
  #define BUFFOR_SIZE 5
#endif

char  *get_next_line(int fd);
char  *return_str(char **str, size_t length);
char  *override(char **str, char **c, size_t i);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);

#endif