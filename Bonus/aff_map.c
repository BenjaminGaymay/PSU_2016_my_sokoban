/*
** aff_map.c for aff_map in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Mon Dec 12 12:35:20 2016 Benjamin GAYMAY
** Last update Thu Dec 22 14:47:46 2016 Benjamin GAYMAY
*/

#include <ncurses.h>
#include "my_sokoban.h"
#include "my.h"
#include "create_map.h"

void	aff_map(t_array *array, int lines, int columns)
{
  int	f;
  int	x;

  f = 0;
  x = 0;
  mvprintw(2, 2, "PRESS \"Q\" KEY TO LEAVE");
  mvprintw(4, 2, "PRESS \"SPACE\" TO RESET THE LEVEL");
  while (f < lines)
    {
      while (array->hide[f][x] != '\0')
	{
	  array->aff[f][x] = array->hide[f][x];
	  if (array->hide[f][x] == 'G')
	    array->aff[f][x] = 'P';
	  else if (array->hide[f][x] == '+')
	    array->aff[f][x] = 'X';
	  x++;      
	}
      x = 0;
      move((LINES - lines) / 2 + f, (COLS - columns) / 2);
      printw(array->aff[f]);
      f++;
    }
}

void	aff_error()
{
  move((LINES) / 2 - 1, (COLS - 8) / 2);
  printw("Increase");
  move((LINES) / 2 + 1, (COLS - 8) / 2);
  printw("the term");
}
