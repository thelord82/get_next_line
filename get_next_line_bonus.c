/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:03:48 by malord            #+#    #+#             */
/*   Updated: 2022/06/09 16:46:37 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Allocates the memory and fills buffer, returns length of line including /n
long	ft_getline(char **cleanbuf, int fd)
{
	long	reader;
	char	*buf;

	while (!(*cleanbuf) || !ft_strlen_until(*cleanbuf, '\n'))
	{
		buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader <= 0)
			return ((int)ft_free(buf));
		*cleanbuf = ft_strjoin_free(*cleanbuf, buf);
		free(buf);
	}
	return (ft_strlen_until(*cleanbuf, '\n'));
}

/* Returns the next line of a file. Successive calls gets the next line
until EOF*/
char	*get_next_line(int fd)
{
	char		*line;
	long		len;
	static char	*cleanbuf[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	len = ft_getline(&(cleanbuf[fd]), fd);
	if (!len)
		len = ft_strlen_until(cleanbuf[fd], 0);
	if (!len)
	{
		cleanbuf[fd] = ft_free(cleanbuf[fd]);
		return (NULL);
	}
	line = ft_calloc(sizeof(char), len + 1);
	ft_strncpy(line, cleanbuf[fd], len);
	if (!ft_strlen_until(cleanbuf[fd], '\n'))
	{
		cleanbuf[fd] = ft_free(cleanbuf[fd]);
		cleanbuf[fd] = NULL;
	}
	else
		ft_strncpy(cleanbuf[fd], &cleanbuf[fd][len],
			ft_strlen_until(cleanbuf[fd], 0) - len + 1);
	return (line);
}
