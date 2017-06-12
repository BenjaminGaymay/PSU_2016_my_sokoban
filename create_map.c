/*
** create_map.c for create_map in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Fri Dec  9 11:44:54 2016 Benjamin GAYMAY
** Last update Sun Dec 18 14:47:56 2016 Benjamin GAYMAY
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "my_sokoban.h"
#include "create_map.h"
#include "count.h"
#include "use_array.h"
#include "game_over.h"

int	create_term(t_array *array, int lines, t_pos *player, char *buffer)
{
  if (find_base(array, lines) == 0 ||
      find_base(array, lines) != find_box(array, lines) ||
      game_over(array, lines) == 1)
    return (84);
  else
    {
      initscr();
      curs_set(0);
      noecho();
      keypad(stdscr, TRUE);
      return (aff_term(array, lines, player, buffer));
    }
}

int	aff_term(t_array *array, int lines, t_pos *player, char *buffer)
{
  int	win;
  int	column_max;

  win = 2;
  column_max = 0;
  column_max = find_middle(column_max, lines, buffer);
  clear();
  if ((lines > LINES) || (column_max > COLS))
    aff_error();
  else
    aff_sokoban(array, lines, column_max, &win);
  check_key(array, player, &win, buffer);
  aff_sokoban(array, lines, column_max, &win);
  if (win == 2)
    aff_term(array, lines, player, buffer);
  else
    {
      aff_map(array, lines, column_max);
      endwin();
      return (win);
    }
}

int	find_middle(int column, int lines, char *buffer)
{
  int	i;

  i = 0;
  while (i < lines)
    {
      if (column < count_columns(buffer, i))
	column = count_columns(buffer, i);
      i++;
    }
  return (column);
}

void	aff_sokoban(t_array *array, int lines, int columns, int *win)
{
  if (find_base(array, lines) != 0)
    aff_map(array, lines, columns);
  else
    {
      aff_map(array, lines, columns);
      *win = 0;
    }
  if (game_over(array, lines) == 1)
    {
      aff_map(array, lines, columns);
      *win = 1;
    }
}

void	check_key(t_array *array, t_pos *player, int *win, char *buffer)
{
  int	c;
  int	lines;

  c = getch();
  if (c == ' ')
    {
      lines = count_lines(buffer);
      add_in_array(array->hide, buffer, lines);
      add_in_array(array->aff, buffer, lines);
      find_player(array, lines, player);
      *win = 2;
    }
  else if (*win == 2)
    my_move(c, array, player, buffer);
}
