/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:23:17 by malord            #+#    #+#             */
/*   Updated: 2022/05/19 11:26:11 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	//fd = open("test.txt", O_RDONLY);
	fd = open("test2", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free (line);
	}
	/*line = get_next_line(fd);
	printf("%s", line);
	free (line);
	
	line = get_next_line(fd);
	printf("%s", line);
	free (line);
	line = get_next_line(fd);
	printf("%s", line);
	free (line);*/
	return (0);
}
