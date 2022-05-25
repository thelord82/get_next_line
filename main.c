/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:23:17 by malord            #+#    #+#             */
/*   Updated: 2022/05/25 16:32:26 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd[6];
	char	*line;

	fd[0] = open("1", O_RDONLY);
	fd[1] = open("2", O_RDONLY);
	fd[2] = open("3", O_RDONLY);
	fd[3] = open("4", O_RDONLY);
	fd[4] = open("test.txt", O_RDONLY);
	fd[5] = open("test2", O_RDONLY);

	/*while (1)
	{
		line = get_next_line(fd[4]);
		if (line == NULL)
			break ;
		printf("%s", line);
		free (line);
	}*/
	printf("\n");
	line = get_next_line(fd[0]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[4]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[0]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[4]);
	printf("%s", line);
	free (line);

	/*line = get_next_line(fd[1]);
	printf("%s", line);
	free (line);*/

	/*line = get_next_line(fd[0]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[1]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[3]);
	printf("%s", line);
	free (line);*/
	return (0);
}
