/*
** my_sokoban.c for my_sokoban in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Dec  8 13:34:04 2016 Benjamin GAYMAY
** Last update Thu Dec 22 10:29:59 2016 Benjamin GAYMAY
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my_sokoban.h"
#include "create_map.h"
#include "my.h"

int	my_sokoban(t_array *array, int lines, char *buffer)
{
  t_pos	player;

  if (find_player(array, lines, &player) == 1)
    return (create_term(array, lines, &player, buffer));
  my_putstr("Invalid map\n");
  return (84);
}

int	find_player(t_array *array, int lines, t_pos *player)
{
  int	x;
  int	y;
  int	i;

  y = 0;
  x = 0;
  i = 0;
  while (y < lines)
    {
      while (array->hide[y][x] != '\0')
	{
	  if (array->hide[y][x] == 'P')
	    {
	      player->x = x;
	      player->y = y;
	      i++;
	    }
	  x++;
	}
      x = 0;
      y++;
    }
  return (i);
}

int	find_box(t_array *array, int lines)
{
  int	x;
  int	y;
  int	box;

  y = 0;
  x = 0;
  box = 0;
  while (y < lines)
    {
      while (array->hide[y][x] != '\0')
	{
	  if (array->hide[y][x] == 'X')
	    box++;
	  x++;
	}
      x = 0;
      y++;
    }
  return (box);
}

int	find_base(t_array *array, int lines)
{
  int	x;
  int	y;
  int	base;

  y = 0;
  x = 0;
  base = 0;
  while (y < lines)
    {
      while (array->hide[y][x] != '\0')
	{
	  if (array->hide[y][x] == 'O')
	    base++;
	  else if (array->hide[y][x] == 'G')
	    base++;
	  x++;
	}
      x = 0;
      y++;
    }
  return (base);
}
