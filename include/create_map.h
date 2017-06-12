/*
** create_map.h for create_map in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Fri Dec  9 11:47:38 2016 Benjamin GAYMAY
** Last update Sat Dec 17 22:24:18 2016 Benjamin GAYMAY
*/

#ifndef CREATE_MAP_H_
# define CREATE_MAP_H_

#include "my_sokoban.h"

int	create_term(t_array *array, int lines, t_pos *player, char *buffer);
int	aff_term(t_array *array, int lines, t_pos *player, char *buffer);
int	find_middle(int columns, int lines, char *buffer);
void	aff_sokoban(t_array *array, int lines, int columns, int *win);
void	check_key(t_array *array, t_pos *player, int *win, char *buffer);

void	aff_error();
void	aff_map(t_array *array, int lines, int columns);

#endif /* !CREATE_MAP_H_ */
