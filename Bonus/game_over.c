/*
** game_over.c for game_over in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Sun Dec 11 15:34:09 2016 Benjamin GAYMAY
** Last update Thu Dec 22 10:25:37 2016 Benjamin GAYMAY
*/

#include <ncurses.h>
#include "game_over.h"

int	game_over(t_array *array, int lines)
{
  int	x;
  int	y;
  int	i;

  x = 0;
  y = 0;
  i = 0;
  while (y < lines)
    {
      while (array->hide[y][x] != '\0')
	{
	  if (array->hide[y][x] == 'X')
	    {
	      if (block_can_move(array, x, y, i) == 0)
		return (1);
	    }
	  x++;
	}
      x = 0;
      y++;
    }
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

void	aff_game_over(int lines)
{
  move((LINES - lines) / 3 - 3, (COLS - 69) / 2);
  printw(" _______ _______ _______ _______  ");
  printw("    _______ ___ ___ _______ ______ ");
  move((LINES - lines) / 3 - 2, (COLS - 69) / 2);
  printw("|     __|   _   |   |   |    ___|  ");
  printw("  |       |   |   |    ___|   __ \\");
  move((LINES - lines) / 3 - 1, (COLS - 69) / 2);
  printw("|    |  |       |       |    ___|  ");
  printw("  |   -   |   |   |    ___|      <");
  move((LINES - lines) / 3, (COLS - 69) / 2);
  printw("|_______|___|___|__|_|__|_______|  ");
  printw("  |_______|\\_____/|_______|___|__|");
}

void	aff_win(int lines)
{
  move((LINES - lines) / 3 - 3, (COLS - 21) / 2);
  printw(" __ __ __ __ ____ __");
  move((LINES - lines) / 3 - 2, (COLS - 21) / 2);
  printw("|  |  |  |  |    |  |");
  move((LINES - lines) / 3 - 1, (COLS - 21) / 2);
  printw("|  |  |  |  |       |");
  move((LINES - lines) / 3, (COLS - 21) / 2);
  printw(" \\__/\\__/|__|__|____|");
}
