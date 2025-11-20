/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:00:11 by dsalwa            #+#    #+#             */
/*   Updated: 2025/11/20 22:22:01 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char  *return_str(char **str, int length)
{
  char *c;
  char *h;
  int i;
  int j;

  c = malloc(length + 1);
  if (!c)
  {
    return NULL;
  }
  i = 0;
  while ((*str)[i] != '\n')
  {
    c[i] = (*str)[i];
    i++;
  }
  h = malloc(ft_strlen(*str) - 1);
  if (!h)
  {
    return (free(c), NULL);
  }
  j = 0;
  while ((*str)[i] != '\0')
  {
    h[j++] = (*str)[i++];
  }
  return (*str = h, c);
}

char  *get_next_line(int fd)
{
  char *buffor;
  static char *save;
  int i;
  size_t n;
  int endline;

  i = 0;
  endline = 0;
  buffor = malloc(BUFFOR_SIZE + 1);
  n = read(fd, buffor, BUFFOR_SIZE);
  save = ft_strjoin(save, buffor);
  while (save[i] != '\n' && save[i] != '\0')
  {
    i++;
  }
  if (save[i] == '\n')
  {
    printf("return: %s\n", return_str(&save, i));
    printf("next: %s\n", save);
    return (return_str(&save, i));
  }
  // n = read(fd, buffor, BUFFOR_SIZE);
  // if (endline)
  // {
  //   return save;
  // }
  // endline = 0;
  return "d";
}
