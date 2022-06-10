/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:47:26 by malord            #+#    #+#             */
/*   Updated: 2022/06/09 16:48:22 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen_until(char *s, char c);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_strncpy(char *dest, char *src, size_t n);
long	ft_getline(char **cleanbuf, int fd);
char	*get_next_line(int fd);
char	*ft_free(void *ptr);
#endif