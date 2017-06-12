/*
** use_array.c for use_array in /home/benjamin.g/delivery/CPE_2016_BSQ
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Tue Dec  6 13:41:33 2016 Benjamin GAYMAY
** Last update Sat Dec 17 23:07:58 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "count.h"
#include "my.h"

void	add_in_array(char **array, char *buffer, int line, int columns)
{
  int	i;
  int	f;
  int	g;

  i = 0;
  f = 0;
  g = 0;
  while (i < line)
    {
      while (buffer[g] != '\n' && buffer[g] != '\0')
	{
	  array[i][f] = buffer[g];
	  g++;
	  f++;
	}
      array[i][f] = '\0';
      f = 0;
      g++;
      i++;
    }
}

void	aff_array(char **array, int line)
{
  int	i;

  i = 0;
  while (i < line)
    {
      my_putstr(array[i]);
      my_putchar('\n');
      i++;
    }
}
