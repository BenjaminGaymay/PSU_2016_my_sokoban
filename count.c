/*
** count.c for count in /home/benjamin.g/delivery/PSU_2016_my_sokoban
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Fri Dec  9 11:42:16 2016 Benjamin GAYMAY
** Last update Thu Dec 15 10:39:27 2016 Benjamin GAYMAY
*/

int	count_columns(char *buffer, int i)
{
  int	f;
  int	j;

  j = 0;
  f = 0;
  while (i > 0 && buffer[f] != '\0')
    {
      if (buffer[f] == '\n')
	i--;
      f++;
    }
  j = f;
  while (buffer[j] != '\n' && buffer[j] != '\0')
    j++;
  return (j - f);
}

int	count_lines(char *buffer)
{
  int	f;
  int	nb_line;

  f = 0;
  nb_line = 0;
  while (buffer[f] != '\0')
    {
      if (buffer[f] == '\n')
	nb_line++;
      f++;
    }
  if (buffer[f - 1] != '\n')
    nb_line++;
  return (nb_line);
}
