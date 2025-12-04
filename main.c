#include "get_next_line.h"
#include <stdio.h>

int main()
{
  int fd = open("text.txt", O_RDONLY);
  printf(" gnl: %s", get_next_line(fd));
  printf(" gnl: %s", get_next_line(fd));
  printf(" gnl: %s", get_next_line(fd));
  printf(" gnl: %s", get_next_line(fd));
  printf(" gnl: %s", get_next_line(fd));
  printf(" gnl: %s", get_next_line(fd));
  printf(" gnl: %s", get_next_line(fd));
  // printf(" gnl: %s", get_next_line(fd));
  // printf(" gnl: %s", get_next_line(fd));
  // printf(" gnl: %s", get_next_line(fd));
  // printf(" gnl: %s", get_next_line(fd));
  return (0);
}
