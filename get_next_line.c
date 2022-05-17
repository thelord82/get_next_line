/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:03:48 by malord            #+#    #+#             */
/*   Updated: 2022/05/17 13:25:26 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*char	*get_next_line(int fd)
{
	char	*line;

	return (line);
}*/
int	main(void)
{
	int		fd;
	int		ret;
	char	*buf;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	buf = malloc(sizeof(buf));
	if (!buf)
		return (0);
	ret = read(fd, buf, sizeof(buf));
	while (buf[i] != '\n')
	{
		printf("%c", buf[i]);
		i++;
	}
	printf("\n");
	//printf("%d\n", i);
	close (fd);
	return (0);
}