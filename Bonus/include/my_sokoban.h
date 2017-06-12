/*
** my_sokoban.h for my_sokoban in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Dec  8 13:19:56 2016 Benjamin GAYMAY
** Last update Thu Dec 22 10:26:45 2016 Benjamin GAYMAY
*/

#ifndef MY_SOKOBAN_
# define MY_SOKOBAN_

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_array
{
  char		**hide;
  char		**aff;
}		t_array;

int	add_in_buffer(int size, char **av);
int	my_array(char *buffer);
void	print_help();

int	my_sokoban(t_array *array, int lines, char *buffer);
int	find_player(t_array *array, int lines, t_pos *player);
int	find_box(t_array *array, int lines);
int	find_base(t_array *array, int lines);

void	my_move(int dir, t_array *array, t_pos *player, char *buffer);
void	is_left(t_array *array, t_pos *player, char last_case, char *buffer);
void	is_right(t_array *array, t_pos *player, char last_case, char *buffer);
void	is_up(t_array *array, t_pos *player, char last_case, char *buffer);
void	is_down(t_array *array, t_pos *player, char last_case, char *buffer);

int	wall(int x, int y, t_array *array, char *buffer);
int	is_box(int x, int y, t_array *array);
int	is_free(int x, int y, t_array *array, char *buffer);
int	is_O(int x, int y, t_array *array);

#endif /* !MY_SOKOBAN_ */
