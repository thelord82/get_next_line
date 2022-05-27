/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:23:17 by malord            #+#    #+#             */
/*   Updated: 2022/05/27 16:13:31 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_bonus.h"


int	ft_check_fd(int fd, t_list *files)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	while (files)
	{
		if (fd == files->fds)
			return (1);
		files = files->next;
	}
	new->fds = fd;
	printf("FD insert : %d\n", new->fds);
	return (0);
}
int	main(void)
{
	int		*fd;
	char	*line;
	int		i;
	t_list	*new;
	t_list	*head;
	t_list	*fds;

	fd[0] = open("1", O_RDONLY);
	fd[1] = open("2", O_RDONLY);
	fd[2] = open("3", O_RDONLY);
	fd[3] = open("4", O_RDONLY);
	fd[4] = open("test.txt", O_RDONLY);
	fd[5] = open("test2", O_RDONLY);
	i = 0;
	//head = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));
	/*while (i < 6)
	{
		new->next = malloc(sizeof(t_list));
		new->fds = fd[i++];
		printf("Test de liste : %d\n", new->fds);
		new = new->next;
	}*/
	new->fds = fd[0];
	printf("%d\n", ft_check_fd(fd[1], new));
	printf("Valeur du FD : %d\n", fd[1]);
	free(new);
	/*while (1)
	{
		line = get_next_line(fd[4]);
		if (line == NULL)
			break ;
		printf("%s", line);
		free (line);
	}*/
	/*line = get_next_line(fd[4]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[5]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[4]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[5]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[4]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[0]);
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
