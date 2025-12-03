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

  return (free(*str), *str = h, *c);
}

char  *return_str(char **str, size_t length_of_return)
{
  char *c;
  size_t i;

  c = malloc(length_of_return);
  if (!c)
  {
    return NULL;
  }
  printf("hey");
  i = 0;
  if (length_of_return == 0 && ((*str)[0] == '\n'))
  {
    return (c[i] = (*str)[i], i++, c[i] = '\0', override(str, &c, i));
  }
  while (length_of_return > i)
  {
    c[i] = (*str)[i];
    i++;
    if ((*str)[i] == '\n' && length_of_return > 1)
    {
      c[i] = (*str)[i];
      i++;
      break;
    }
  }
  return (c[i] = '\0', i++, override(str, &c, i));
}

size_t final_length_of_return(char *str)
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
  // while (1)
  // {
  read_chars = read(fd, ft_memset(buffor, 0, BUFFOR_SIZE + 1), BUFFOR_SIZE);
  str = ft_strjoin(str, buffor);
  printf("%zu\n", final_length_of_return(str));
  printf("%zu\n", read_chars);
  if ((read_chars == 0 && ft_strlen(str)) || ft_strchr(str, '\n'))
  {
    return (free(buffor), return_str(&str, final_length_of_return(str)));
  }
  // }
  free(buffor);
  return NULL;
}
