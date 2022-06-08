/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:03:48 by malord            #+#    #+#             */
/*   Updated: 2022/06/08 13:05:31 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Calculates the number of chars in current line and allocates memory
accordingly. */
void	ft_genline(char **line, t_list *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

/* Extracts all characters from stash and stores in out line. Stops after /n. */
void	ft_getline(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	ft_genline(line, stash);
	if (!(*line))
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

/* Cleans the stash after getting the line. Removes characters already returned 
by get_next_line and keeps the unreturned ones in static variable. */
void	ft_clean_stash(t_list **stash, char (*bufleft)[BUFFER_SIZE + 1])
{
	t_list	*last;
	int		i;
	int		j;

	if (!stash)
		return ;
	last = ft_lstlast(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	j = 0;
	while (last->content[i])
	{
		(*bufleft)[j++] = last->content[i];
		i++;
	}
	(*bufleft)[j] = '\0';
}

// Adds the content of buffer to the end of stash.
void	ft_add_to_stash(t_list **stash, char *buf, int reader)
{
	int		i;
	t_list	*last;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (reader + 1));
	if (!new->content)
		return ;
	i = 0;
	while (buf[i] && i < reader)
	{
		new->content[i] = buf[i];
		i++;
	}
	new->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new;
		return ;
	}
	last = ft_lstlast(*stash);
	last->next = new;
}

/* Returns the next line of a file. Successive calls gets the next line
until EOF*/
char	*get_next_line(int fd)
{
	t_list			*stash;
	char			*line;
	int				reader;
	static char		cleanbuf[OPEN_MAX][BUFFER_SIZE + 1];

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	reader = 1;
	line = NULL;
	ft_read_stash(fd, &stash, &reader);
	if (stash == NULL)
		return (NULL);
	ft_getline(stash, &line);
	line = ft_strjoin(cleanbuf[fd], line);
	ft_clean_stash(&stash, &cleanbuf[fd]);
	ft_free_stash(stash);
	if (line[0] == '\0')
	{
		ft_free_stash(stash);
		free(line);
		return (NULL);
	}
	return (line);
}
