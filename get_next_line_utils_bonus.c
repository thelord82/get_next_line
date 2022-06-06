/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:19:27 by malord            #+#    #+#             */
/*   Updated: 2022/06/06 16:14:56 by malord           ###   ########.fr       */
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

// Returns a pointer to the last node in stash.
t_list	*ft_lstlast(t_list *stash)
{
	while (stash && stash->next)
		stash = stash->next;
	return (stash);
}

// Frees the full stash.
void	ft_free_stash(t_list *stash)
{
	t_list	*next;

	while (stash)
	{
		free(stash->content);
		next = stash->next;
		free(stash);
		stash = next;
	}
	stash = NULL;
}
