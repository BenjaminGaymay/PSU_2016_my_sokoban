/*
** my_puterror.c for my_puterror in /home/benjamin.g/delivery/CPool_Day04
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct  6 15:28:00 2016 Benjamin GAYMAY
** Last update Thu Dec 15 17:05:14 2016 Benjamin GAYMAY
*/

#include <unistd.h>
#include "my.h"

int	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  return (0);
}
