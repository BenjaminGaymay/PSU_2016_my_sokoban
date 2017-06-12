/*
** main.c for main in /home/benjamin.g/delivery/PSU_2016_my_popup
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Wed Dec  7 14:02:07 2016 Benjamin GAYMAY
** Last update Fri Jan  6 15:49:14 2017 Benjamin GAYMAY
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "count.h"
#include "use_array.h"
#include "my_sokoban.h"

int		main(int ac, char **av, char **ae)
{
  FILE		*file;
  char		*line;
  size_t	len;
  ssize_t	count_size;
  int		size;

  len = 0;
  size = 0;
  if (ac == 2)
    {
      if (av[1][0] == '-' && av[1][1] == 'h')
	print_help();
      else if ((file = fopen(av[1], "r")) < 0)
	return (-1);
      else
	{
	  while ((count_size = getline(&line, &len, file)) != -1)
	    size += count_size;
	  fclose(file);
	  free(line);
	  return (add_in_buffer(size, av));
	}
    }
  fclose(file);
  return (0);
}

int		add_in_buffer(int size, char **av)
{
  FILE		*file;
  char		*line;
  size_t	len;
  ssize_t	count_size;
  char	 	*buffer;

  len = 0;
  if ((buffer = malloc(sizeof(char) * (size + 1))) == NULL)
    return (84);
  if ((file = fopen(av[1], "r")) < 0)
    return (-1);
  buffer[0] = '\0';
  while ((count_size = getline(&line, &len, file)) != -1)
    buffer = my_strcat(buffer, line);
  fclose(file);
  return (my_array(buffer));
}

void	print_help()
{
  my_putstr("USAGE\n\t./my_sokoban map\n\nDESCRIPTION\n\tmap\tfile repre");
  my_putstr("senting the warehouse map,containing '#' for walls,\n\t\t'P' ");
  my_putstr("for the player, 'X'for boxes and 'O' for storage locations.\n");
}

int		my_array(char *buffer)
{
  t_array	array;
  char		**m_array1;
  char		**m_array2;
  int		columns;
  int		i;

  i = 0;
  if ((m_array1 = malloc(sizeof(char*) * (count_lines(buffer) + 1))) == NULL ||
    (m_array2 = malloc(sizeof(char*) * (count_lines(buffer) + 1))) == NULL)
    return (84);
  while (i < count_lines(buffer))
    {
      columns = count_columns(buffer, i);
      if ((m_array1[i] = malloc(sizeof(char) * (columns + 1))) == NULL ||
	(m_array2[i] = malloc(sizeof(char) * (columns + 1))) == NULL)
	return (84);
      i++;
    }
  m_array1[i] = NULL;
  m_array2[i] = NULL;
  add_in_array(m_array1, buffer, count_lines(buffer));
  add_in_array(m_array2, buffer, count_lines(buffer));
  array.hide = m_array1;
  array.aff = m_array2;
  return (my_sokoban(&array, count_lines(buffer), buffer));
}
