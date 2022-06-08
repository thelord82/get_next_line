/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:19:27 by malord            #+#    #+#             */
/*   Updated: 2022/06/08 16:58:33 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Uses read to add characters to the stash.
void	ft_read_stash(int fd, t_list **stash, int *reader_ptr)
{
	char	*buf;

	while (ft_found_newline(*stash) == 0 && *reader_ptr != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		*reader_ptr = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && *reader_ptr == 0) || *reader_ptr == -1)
		{
			free (buf);
			return ;
		}
		buf[*reader_ptr] = '\0';
		ft_add_to_stash(stash, buf, *reader_ptr);
		free (buf);
	}
}

// Looks for a /n character in the given list.
int	ft_found_newline(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == NULL)
		return (0);
	current = ft_lstlast(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nstr;
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	while (s2[i++])
		len++;
	nstr = malloc((sizeof(char) * len) + 1);
	if (!nstr)
		return (NULL);
	while (*s1)
		*nstr++ = *s1++;
	while (*s2)
		*nstr++ = *s2++;
	*nstr++ = '\0';
	return (nstr - (len + 1));
}

// Returns a pointer to the last node in stash.
t_list	*ft_lstlast(t_list *stash)
{
	while (stash && stash->next)
		stash = stash->next;
	return (stash);
}

// Frees the full stash.
void	ft_free_stash(t_list *stash, char (*cleanbuf)[BUFFER_SIZE + 1])
{
	t_list	*next;
	t_list	*new;
	int		i;
	char	*str;

	str = *cleanbuf;
	i = 0;
	new = malloc(sizeof(t_list));
	while (stash)
	{
		free(stash->content);
		next = stash->next;
		free(stash);
		stash = next;
	}
	new->content = str;
	/*while (i < (BUFFER_SIZE + 1))
	{
		new->content[i] = *cleanbuf[i];
		i++;
	}*/
	stash = new;
	//free(new);
}
