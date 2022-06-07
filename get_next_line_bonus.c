/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:03:48 by malord            #+#    #+#             */
/*   Updated: 2022/06/06 21:08:40 by malord           ###   ########.fr       */
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
char	*ft_clean_stash(t_list **stash)
{
	t_list	*last;
	char	*clean;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	last = ft_lstlast(*stash);
	i = 0;
	j = 0;
	while (last->content[j])
		j++;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	clean = malloc(sizeof(char) * ((j - i) + 1));
	if (!clean)
		return (NULL);
	j = 0;
	while (last->content[i])
		clean[j++] = last->content[i++];
	clean[j] = '\0';
	return (clean);
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

// Returns the length of the string in parameter
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// Copy string src into string dst. Returns length of src it tried to copy
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (src[c] != '\0')
		c++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (c);
}

/* Concatenate src string in dst string, returns the total length
	of the string it tried to create */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	j = dst_len;
	i = 0;
	if (dst_len < size - 1 && size > 0)
	{
		while (src[i] && dst_len + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dst_len >= size)
		dst_len = size;
	return (dst_len + src_len);
}

/* Allocates memory for the combination of s1 and s2, then returns pointer
	to the new string containing the two*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	nstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strlcpy(nstr, s1, len);
	ft_strlcat(nstr, s2, len);
	return (nstr);
}

/* Returns the next line of a file. Successive calls gets the next line
until EOF*/
char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;
	int				reader;
	char			cleanbuf[290][BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	reader = 1;
	line = NULL;
	ft_read_stash(fd, &stash, &reader);
	if (stash == NULL)
		return (NULL);
	ft_getline(stash, &line);
	if (cleanbuf[fd] != NULL)
		line = ft_strjoin(cleanbuf[fd], line);
	ft_strlcpy(cleanbuf[fd], ft_clean_stash(&stash), BUFFER_SIZE);
	ft_free_stash(stash);
	stash = NULL;
	if (line[0] == '\0')
	{
		ft_free_stash(stash);
		free(line);
		return (NULL);
	}
	return (line);
}
