/*
** EPITECH PROJECT, 2022
** temp
** File description:
** temp
*/

#include <stdio.h>

int my_strlen(char const *str);

int   my_strcmp(const char *s1, const char *s2)
{
  int  i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}