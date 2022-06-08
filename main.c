/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:23:17 by malord            #+#    #+#             */
/*   Updated: 2022/06/08 14:51:00 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;
	int		i;

	fd = open("1", O_RDONLY);
	//fd[1] = open("2", O_RDONLY);
	//fd[2] = open("3", O_RDONLY);
	fd2 = open("4", O_RDONLY);
	//fd[4] = open("test.txt", O_RDONLY);
	//fd[5] = open("test2", O_RDONLY);
	i = 0;

	line = get_next_line(fd2);
	printf("%s", line);
	free (line);

	line = get_next_line(fd2);
	printf("%s", line);
	free (line);

	line = get_next_line(fd2);
	printf("%s", line);
	free (line);

	line = get_next_line(fd2);
	printf("%s", line);
	free (line);

	line = get_next_line(fd2);
	printf("%s", line);
	free (line);

	/*line = get_next_line(fd);
	printf("%s", line);
	free (line);

	line = get_next_line(fd2);
	printf("%s", line);
	free (line);

	line = get_next_line(fd2);
	printf("%s", line);
	free (line);*/

	/*line = get_next_line(fd[3]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[3]);
	printf("%s", line);
	free (line);*/

	return (0);
}
