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

void override(char **str, char **c, int i)
{
  int j;
  char *h;

  h = malloc(ft_strlen(*str) - 1);
  if (!h)
  {
    free(c);
    return;
  }
  j = 0;
  while ((*str)[i] != '\0')
  {
    h[j++] = (*str)[i++];
  }

  *str = h;
  // printf("str inside override: %s\n", *str);
}

char  *return_str(char **str, size_t length)
{
  char *c;
  size_t i;

  c = malloc(length + 1);
  if (!c)
  {
    return NULL;
  }
  i = 0;
  // printf("length: %zu\n", length);
  // printf("i for return loop: %zu\n", i);
  // printf("(*str)[i]: %c\n", (*str)[i]);
  if (length == 1 && ((*str)[i] == '\n'))
  {
    // printf("first if inside return\n");
    return (c[i] = (*str)[i], i++, c[i + 1] = '\0', override(str, &c, i), c);
  }
  while (length > i)
  {
    // printf("inside return while");
    c[i] = (*str)[i];
    i++;
    if ((*str)[i] == '\n')
    {
      c[i] = (*str)[i];
      i++;
      break;
    } 
  }
  // printf("c: %s\n", c);
  return (c[i + 1] = '\0', override(str, &c, i), c);
}

char  *get_next_line(int fd)
{
  char *buffor;
  static char *str;
  // static int times = 1;
  size_t i;
  size_t n;

  // printf("Called for a: %d time\n", times);
  // times++;

  buffor = malloc(BUFFOR_SIZE + 1);
  if (!buffor)
  {
    return (NULL);
  }
  n = read(fd, buffor, BUFFOR_SIZE);
  i = 0;
  while (n > 0 || (n == 0 && ft_strlen(str) > 0))
  {
    // printf("buffor content: %s\n", buffor);
    str = ft_strjoin(str, buffor);
    while (str[i] != '\n' && ft_strlen(str) > i)
    {
      i++;
    }
    // printf("i inside gnl: %zu\n", i); 
    // printf("last: %c\n", str[i]);
    if (i == 0 && str[i] == '\n')
    {
      i++;
    }
    // printf("i inside gnl after if: %zu\n", i);
    // printf("str after strjoin: %s\n", str);
    if (ft_strlen(str) != i || (n == 0 && ft_strlen(str) > 0))
    {
      // printf("here we go\n");
      return (return_str(&str, i));
    }
    // printf("read\n");
    if ((n = read(fd, buffor, BUFFOR_SIZE)) == 0)
    {
      buffor = NULL;
    }
  }
  return NULL;
} 
