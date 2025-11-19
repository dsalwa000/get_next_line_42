#include "get_next_line.h"

int main()
{
  int fd = open("text.txt", O_RDONLY);
  get_next_line(fd);
  return (0);
}
