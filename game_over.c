/*
** game_over.c for game_over in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Sun Dec 11 15:34:09 2016 Benjamin GAYMAY
** Last update Sun Dec 18 14:47:28 2016 Benjamin GAYMAY
*/

#include <ncurses.h>
#include "my_sokoban.h"
#include "game_over.h"

int	game_over(t_array *array, int lines)
{
  t_pos	block;
  int	i;

  block.x = 0;
  block.y = 0;
  i = 0;
  return (game_over2(array, lines, block, i));
}

int	game_over2(t_array *array, int lines, t_pos block, int i)
{
  int	cant_move;
  int	nb_block;

  nb_block = 0;
  cant_move = 0;
  while (block.y < lines)
    {
      while (array->hide[block.y][block.x] != '\0')
	{
	  if (array->hide[block.y][block.x] == 'X')
	    {
	      if (block_can_move(array, block.x, block.y, i) == 0)
		cant_move++;
	      nb_block++;
	    }
	  else if (array->hide[block.y][block.x] == '+')
	    nb_block++;
	  block.x += 1;
	}
      block.x = 0;
      block.y += 1;
    }
  if (nb_block == cant_move)
    return (1);
  return (0);
}

int	block_can_move(t_array *array, int x, int y, int i)
{
  if (case_is_empty(x, y + 1, array, &i) == 0 &&
      case_is_empty(x - 1, y, array, &i) == 0)
    return (0);
  else if (case_is_empty(x, y + 1, array, &i) == 0 &&
	   case_is_empty(x + 1, y, array, &i) == 0)
    return (0);
  else if (case_is_empty(x, y - 1, array, &i) == 0 &&
	   case_is_empty(x - 1, y, array, &i) == 0)
    return (0);
  else if (case_is_empty(x, y - 1, array, &i) == 0 &&
	   case_is_empty(x + 1, y, array, &i) == 0)
    return (0);
  else
    return (1);
}

int	case_is_empty(int x, int y, t_array *array, int *i)
{
  if (y < 0 || array->hide[y] == NULL)
    return (0);
  else if (array->hide[y][x] == 'X' || array->hide[y][x] == '+')
    {
      if (*i < 3)
	{
	  *i = *i + 1;
	  if (block_can_move(array, x, y, *i) == 1)
	    return (1);
	}
      return (0);
    }
  else if (array->hide[y][x] == 'P' || array->hide[y][x] == 'O' ||
	   array->hide[y][x] == ' ' || array->hide[y][x] == 'G')
    return (1);
  return (0);
}
