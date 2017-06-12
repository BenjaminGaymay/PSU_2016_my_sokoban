/*
** game_over.h for game_over in /home/benjamin.g/delivery/PSU_2016_my_sokoban/include
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Sun Dec 11 16:28:02 2016 Benjamin GAYMAY
** Last update Sun Dec 18 14:47:10 2016 Benjamin GAYMAY
*/

#ifndef GAME_OVER_H_
# define GAME_OVER_H_

#include "my_sokoban.h"

int	game_over(t_array *array, int lines);
int	game_over2(t_array *array, int lines, t_pos block, int i);
int	block_can_move(t_array *array, int x, int y, int i);
int	case_is_empty(int x, int y, t_array *array, int *i);
void	aff_win(int lines);
void	aff_game_over(int lines);

#endif /* !GAME_OVER_H_ */
