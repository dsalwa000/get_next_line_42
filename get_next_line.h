#ifndef GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define GET_NEXT_LINE_H

#ifndef BUFFOR_SIZE
  #define BUFFOR_SIZE 42
#endif

char  *get_next_line(int fd);

#endif