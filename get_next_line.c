#include "get_next_line.h"
#include <stdio.h>

char  *get_next_line(int fd)
{
  char *help;
  static char *buffor;
  // w zasadzie nie wiemy jak długa będzie ta linia i to jest problem
  char *result;
  // int i;
  // int j;

  help = malloc(BUFFOR_SIZE + 1);
  buffor = malloc(BUFFOR_SIZE + 1);
  result = malloc(BUFFOR_SIZE + 1);
  read(fd, help, BUFFOR_SIZE);
  help[BUFFOR_SIZE] = '\0';
  buffor[BUFFOR_SIZE] = '\0';
  printf("%s\n", help);
  // i = 0;
  // while (help[i] != '\0' || help[i] != '\n')
  // {
  //   i++;
  // }
  // j = 0;
  // while (help[i] != '\0')
  // {
  //   buffor[j] = help[i++];
  // }
  
  return result;
}
