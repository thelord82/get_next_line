/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:47:26 by malord            #+#    #+#             */
/*   Updated: 2022/05/25 15:58:26 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h> // Pour Printf seulement. Remove before submission.
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		ft_found_newline(t_list *stash);
size_t	ft_strlen(const char *s);
t_list	*ft_lstlast(t_list *stash);
void	ft_add_to_stash(t_list **stash, char *buf, int readed);
t_list	*ft_clean_stash(t_list **stash);
void	ft_free_stash(t_list *stash);
void	ft_genline(char **line, t_list *stash);
void	ft_getline(t_list *stash, char **line);
void	ft_read_stash(int fd, t_list **stash, int *reader_ptr);
void	*ft_calloc(size_t count, size_t size);

#endif