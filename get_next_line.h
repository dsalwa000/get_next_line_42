#ifndef GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define GET_NEXT_LINE_H

#ifndef BUFFOR_SIZE
  #define BUFFOR_SIZE 42
#endif

char  *get_next_line(int fd);
char  *return_str(char **str, size_t found_index);
char  *override(char **str, char **c, size_t found_index);
size_t  find_nl_or_zero_index(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);

#endif