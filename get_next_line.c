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

char  *override(char **str, char **c, size_t found_index)
{
  size_t j;
  char *h;

  h = malloc(ft_strlen(*str) - found_index);
  if (!h)
  {
    return(free(h), free(*str), free(*c), NULL);
  }
  j = 0;
  found_index++;
  while (ft_strlen(*str) > found_index)
  {
    h[j++] = (*str)[found_index++];
  }
  if ((*str)[found_index] == '\n')
  {
    h[j++] = '\n';
  }
  return (h[j] = '\0', free(*str), *str = h, *c);
}

char  *return_str(char **str, size_t found_index)
{
  char *c;
  size_t i;

  c = malloc(found_index + 1);
  if (!c)
  {
    return NULL;
  }
  i = 0;
  if (found_index == 0 && ((*str)[0] == '\n'))
  {
    return (c[i] = (*str)[i], i++, c[i] = '\0', override(str, &c, found_index));
  }
  while (found_index > i)
  {
    c[i] = (*str)[i];
    i++;
    if ((*str)[i] == '\n' && found_index > 1)
    {
      c[i] = (*str)[i];
      i++;
      break;
    }
  }
  return (c[i] = '\0', override(str, &c, found_index));
}

size_t find_nl_or_zero_index(char *str)
{
  size_t  i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
  {
    i++;
  }
  return  (i);
}

char  *get_next_line(int fd)
{
  char *read_buffor;
  static char *static_str;
  size_t amount_of_read_chars;

  if (fd < 0 || BUFFOR_SIZE <= 0)
    return (NULL);
  read_buffor = malloc(BUFFOR_SIZE + 1);
  if (!read_buffor)
  {
    return (NULL);
  }
  while (1)
  {
    amount_of_read_chars = read(fd, ft_memset(read_buffor, 0, BUFFOR_SIZE + 1), BUFFOR_SIZE);
    static_str = ft_strjoin(static_str, read_buffor);
    if (ft_strchr(static_str, '\n') || (ft_strlen(static_str) > 0 && amount_of_read_chars == 0))
    {
      return (free(read_buffor), return_str(&static_str, find_nl_or_zero_index(static_str)));
    }
    if (amount_of_read_chars == 0) 
    {
      break;
    }
  }
  return (free(read_buffor), NULL);
}
