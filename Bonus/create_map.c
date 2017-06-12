/*
** create_map.c for create_map in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Fri Dec  9 11:44:54 2016 Benjamin GAYMAY
** Last update Thu Dec 22 14:48:20 2016 Benjamin GAYMAY
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
    {
      my_putstr("Invalid map\n");
      return (84);
    }
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
  int	i;
  int	column;

  win = 2;
  i = 0;
  column = 0;
  while (i < lines)
    {
      if (column < count_columns(buffer, i))
	column = count_columns(buffer, i);
      i++;
    }
  clear();
  if ((lines > LINES) || (column > COLS))
    aff_error();
  else
    aff_sokoban(array, lines, column, &win);
  check_key(array, player, &win, buffer);
  if (win != 1 && win != 0)
    aff_term(array, lines, player, buffer);
  else
    {
      aff_map(array, lines, column);
      endwin();
      return (win);
    }
}

void	aff_sokoban(t_array *array, int lines, int columns, int *win)
{
  if (find_base(array, lines) != 0)
    aff_map(array, lines, columns);
  else
    {
      aff_win(lines);
      move((LINES - lines) / 3 + 2, (COLS - 24) / 2);
      printw("PRESS \"SPACE\" TO REPLAY");
      aff_map(array, lines, columns);
      *win = 3;
    }
  if (game_over(array, lines) == 1)
    {
      aff_game_over(lines);
      move((LINES - lines) / 3 + 2, (COLS - 22) / 2);
      printw("PRESS \"SPACE\" TO RETRY");
      aff_map(array, lines, columns);
      *win = 4;
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
  else if (c == 'q')
    {
      if (*win == 3)
	*win = 0;
      else
	*win = 1;
    }
  else if (*win == 2)
    my_move(c, array, player, buffer);
}
