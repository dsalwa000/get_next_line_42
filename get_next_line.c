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

char  *override(char **str, char **c, size_t i)
{
  size_t j;
  char *h;

  h = malloc(ft_strlen(*str) - i + 1);
  // printf("i: %zu\n", i);
  // printf("(*str)[i]: %c\n", (*str)[i]);
  if (!h)
  {
    return(free(h), free(*c), NULL);
  }
  j = 0;
  while ((*str)[i] != '\0')
  {
    h[j++] = (*str)[i++];
  }
  h[j] = '\0';

  // printf("h inside override: %s\n", h);
  return (free(*str), *str = h, *c);
}

char  *return_str(char **str, size_t length)
{
  char *c;
  size_t i;

  // printf("*str: %s\n", *str);
  c = malloc(length + 1);
  if (!c)
  {
    return NULL;
  }
  i = 0;
  // printf("length: %zu\n", length);
  if (length == 1 && ((*str)[0] == '\n'))
  {
    return (c[i] = (*str)[i], i++, c[i] = '\0', override(str, &c, i));
  }
  while (length > i)
  {
    c[i] = (*str)[i];
    // printf("c: %c\n", c[i]);
    // printf("i: %zu\n", i);
    i++;
    if ((*str)[i] == '\n' && length > 1)
    {
      c[i] = (*str)[i];
      i++;
      break;
    }
  }
  // printf("c: %s\n", c);
  return (c[i] = '\0', i++, override(str, &c, i));
}

char  *get_next_line(int fd)
{
  char *buffor;
  static char *str;
  size_t i;
  size_t n;

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
    // printf("str_len(str): %zu\n", ft_strlen(str));
    while (str[i] != '\n' && ft_strlen(str) > i)
    {
      // printf("%zu\n", i);
      // printf("%c\n", str[i]);
      i++;
    }
    // printf("c inside gnl: %c\n", str[i]);
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
      return (free(buffor), return_str(&str, i));
    }
    // printf("read\n");
    if ((n = read(fd, ft_memset(buffor, 0, BUFFOR_SIZE + 1), BUFFOR_SIZE)) == 0)
    {
      buffor = NULL;
    }
  }
  free(buffor);
  return NULL;
}
