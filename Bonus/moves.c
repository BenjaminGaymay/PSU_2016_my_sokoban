/*
** moves.c for moves in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Fri Dec  9 11:45:55 2016 Benjamin GAYMAY
** Last update Sat Dec 17 22:37:48 2016 Benjamin GAYMAY
*/

#include <ncurses.h>
#include "my_sokoban.h"

void	my_move(int dir, t_array *array, t_pos *player, char *buffer)
{
  char	last_case;

  if (array->hide[player->y][player->x] == 'G')
    last_case = 'O';
  else
    last_case = ' ';
  if (dir == KEY_LEFT)
    is_left(array, player, last_case, buffer);
  else if (dir == KEY_RIGHT)
    is_right(array, player, last_case, buffer);
  else if (dir == KEY_UP)
    is_up(array, player, last_case, buffer);
  else if (dir == KEY_DOWN)
    is_down(array, player, last_case, buffer);
}

void	is_left(t_array *array, t_pos *player, char last_case, char *buffer)
{
  if (wall(player->x - 1, player->y, array, buffer) == 0)
    {
      if (is_box(player->x - 1, player->y, array) == 0)
	{
	  array->hide[player->y][player->x] = last_case;
	  if (is_O(player->x - 1, player->y, array) == 0)
	    array->hide[player->y][player->x - 1] = 'P';
	  else
	    array->hide[player->y][player->x - 1] = 'G';
	  player->x = player->x - 1;
	}
      else if (is_free(player->x - 2, player->y, array, buffer) == 1)
	{
	  array->hide[player->y][player->x] = last_case;
	  player->x = player->x - 1;
	  if (array->hide[player->y][player->x] == 'X')
	    array->hide[player->y][player->x] = 'P';
	  else
	    array->hide[player->y][player->x] = 'G';
	  if (array->hide[player->y][player->x - 1] == 'O')
	    array->hide[player->y][player->x - 1] = '+';
	  else
	    array->hide[player->y][player->x - 1] = 'X';
	}
    }
}

void	is_right(t_array *array, t_pos *player, char last_case, char *buffer)
{
  if (wall(player->x + 1, player->y, array, buffer) == 0)
    {
      if (is_box(player->x + 1, player->y, array) == 0)
	{
	  array->hide[player->y][player->x] = last_case;
	  if (is_O(player->x + 1, player->y, array) == 0)
	    array->hide[player->y][player->x + 1] = 'P';
	  else
	    array->hide[player->y][player->x + 1] = 'G';
	  player->x = player->x + 1;
	}
      else if (is_free(player->x + 2, player->y, array, buffer) == 1)
	{
	  array->hide[player->y][player->x] = last_case;
	  player->x = player->x + 1;
	  if (array->hide[player->y][player->x] == 'X')
	    array->hide[player->y][player->x] = 'P';
	  else
	    array->hide[player->y][player->x] = 'G';
	  if (array->hide[player->y][player->x + 1] == 'O')
	    array->hide[player->y][player->x + 1] = '+';
	  else
	    array->hide[player->y][player->x + 1] = 'X';
	}
    }
}

void	is_down(t_array *array, t_pos *player, char last_case, char *buffer)
{
  if (wall(player->x, player->y + 1 , array, buffer) == 0)
    {
      if (is_box(player->x, player->y + 1, array) == 0)
	{
	  array->hide[player->y][player->x] = last_case;
	  if (is_O(player->x, player->y + 1, array) == 0)
	    array->hide[player->y + 1][player->x] = 'P';
	  else
	    array->hide[player->y + 1][player->x] = 'G';
	  player->y = player->y + 1;
	}
      else if (is_free(player->x, player->y + 2, array, buffer) == 1)
	{
	  array->hide[player->y][player->x] = last_case;
	  player->y = player->y + 1;
	  if (array->hide[player->y][player->x] == 'X')
	    array->hide[player->y][player->x] = 'P';
	  else
	    array->hide[player->y][player->x] = 'G';
	  if (array->hide[player->y + 1][player->x] == 'O')
	    array->hide[player->y + 1][player->x] = '+';
	  else
	    array->hide[player->y + 1][player->x] = 'X';
	}
    }
}

void	is_up(t_array *array, t_pos *player, char last_case, char *buffer)
{
  if (wall(player->x, player->y - 1, array, buffer) == 0)
    {
      if (is_box(player->x, player->y - 1, array) == 0)
	{
	  array->hide[player->y][player->x] = last_case;
	  if (is_O(player->x, player->y - 1, array) == 0)
	    array->hide[player->y - 1][player->x] = 'P';
	  else
	    array->hide[player->y - 1][player->x] = 'G';
	  player->y = player->y - 1;
	}
      else if (is_free(player->x, player->y - 2, array, buffer) == 1)
	{
	  array->hide[player->y][player->x] = last_case;
	  player->y = player->y - 1;
	  if (array->hide[player->y][player->x] == 'X')
	    array->hide[player->y][player->x] = 'P';
	  else
	    array->hide[player->y][player->x] = 'G';
	  if (array->hide[player->y - 1][player->x] == 'O')
	    array->hide[player->y - 1][player->x] = '+';
	  else
	    array->hide[player->y - 1][player->x] = 'X';
	}
    }
}
