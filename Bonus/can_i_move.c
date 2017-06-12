/*
** can_i_move.c for can_i_move in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Fri Dec  9 12:34:25 2016 Benjamin GAYMAY
** Last update Sat Dec 17 22:49:35 2016 Benjamin GAYMAY
*/

#include "my.h"
#include "count.h"
#include "my_sokoban.h"

int	wall(int x, int y, t_array *array, char *buffer)
{
  if (y < 0 || x < 0)
    return (1);
  else if (y > (count_lines(buffer) - 1)
	   || x > (my_strlen(array->hide[y]) - 1))
    return (1);
  else if (array->hide[y][x] == '#')
    return (1);
  return (0);
}

int	is_O(int x, int y, t_array *array)
{
  if (array->hide[y][x] == 'O')
    return (1);
  return (0);
}

int	is_box(int x, int y, t_array *array)
{
  if (array->hide[y][x] == 'X' || array->hide[y][x] == '+')
    return (1);
  return (0);
}

int	is_free(int x, int y, t_array *array, char *buffer)
{
  if (y < 0 || x < 0)
    return (0);
  else if (y > (count_lines(buffer) - 1)
	   || x > (my_strlen(array->hide[y]) - 1))
    return (0);
  else if (array->hide[y][x] != ' ' && array->hide[y][x] != 'O')
    return (0);
  return (1);
}
