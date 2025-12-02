/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:00:11 by dsalwa            #+#    #+#             */
/*   Updated: 2025/12/02 22:06:02 by dsalwa           ###   ########.fr       */
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

char  *return_str(char **str, size_t last_index)
{
  char *c;
  size_t i;

  c = malloc(last_index + 1);
  if (!c)
  {
    return NULL;
  }
  i = 0;
  if (last_index == 0 && ((*str)[0] == '\n'))
  {
    return (c[i] = (*str)[i], i++, c[i] = '\0', override(str, &c, i));
  }
  while (last_index > i)
  {
    c[i] = (*str)[i];
    i++;
    if ((*str)[i] == '\n' && last_index > 1)
    {
      c[i] = (*str)[i];
      i++;
      break;
    }
  }
  // printf("c: %s\n", c);
  return (c[i] = '\0', i++, override(str, &c, i));
}

size_t length_of_a_return(char *str)
{
  size_t  i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
  {
    i++;
  }
  if (str[i] == '\n')
  {
    i++;
  }
  return  (i);
}

char  *get_next_line(int fd)
{
  char *buffor;
  static char *str;
  size_t read_chars;

  buffor = malloc(BUFFOR_SIZE + 1);
  if (!buffor)
  {
    return (NULL);
  }
  while (1)
  {
    read_chars = read(fd, ft_memset(buffor, 0, BUFFOR_SIZE + 1), BUFFOR_SIZE);
    str = ft_strjoin(str, buffor);
    if ((read_chars < 0 && !ft_strchr(str, '\n')) || ft_strchr(str, '\n'))
    {
      return (free(buffor), return_str(&str, length_of_a_return(str)));
    }
  }
  free(buffor);
  return NULL;
}
