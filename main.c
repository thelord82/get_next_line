/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:23:17 by malord            #+#    #+#             */
/*   Updated: 2022/06/06 21:16:03 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_bonus.h"

/*int	ft_check_fd(int fd, t_list **files)
{
	t_list	*new;
	t_list	*current;

	current = (*files);
	while (current != NULL)
	{
		if (fd == current->fds)
			return (1);
		current = current->next;
	}
	new = malloc(sizeof(t_list));
	new->fds = fd;
	new->next = (*files);
	(*files) = new;
	return (0);
}*/
int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	int		i;
	t_list	*new;
	t_list	*list;
	t_list	*head;

	
	fd = open("1", O_RDONLY);
	fd2 = open("2", O_RDONLY);
	fd3 = open("3", O_RDONLY);
	/*fd[3] = open("4", O_RDONLY);
	fd[4] = open("test.txt", O_RDONLY);
	fd[5] = open("test2", O_RDONLY);*/
	i = 0;
	/*printf("Element inséré : %d\n", list->fds);
	while (i < 6)
	{
		new = malloc(sizeof(t_list));
		list->next = new;
		new->fds = fd[i++];
		printf("Element inséré : %d\n", new->fds);
		list = new;
	}
	list = head;
	while (list != NULL)
	{
		printf("Element de la liste : %d\n", list->fds);
		list = list->next;
	}*/
	
	//new->fds = fd[0];
	//new->next = NULL;
	//list = new;
	/*for (t_list *tmp = list; tmp != NULL; tmp = tmp->next)
	{
		printf("Element de la liste : %d\n", tmp->fds);
	}*/
	//new->fds = fd[0];
	//new->next = NULL;
	//list = new;
	//list = malloc(sizeof(t_list));
	/*printf("FD dans la liste? %d\n", ft_check_fd(fd[0], &head));
	printf("FD dans la liste? %d\n", ft_check_fd(fd[2], &head));
	printf("FD dans la liste? %d\n", ft_check_fd(fd[0], &head));
	printf("FD dans la liste? %d\n", ft_check_fd(fd[1], &head));
	printf("FD dans la liste? %d\n", ft_check_fd(fd[1], &head));
	printf("FD dans la liste? %d\n", ft_check_fd(fd[2], &head));
	printf("FD dans la liste? %d\n", ft_check_fd(fd[3], &head));
	printf("FD dans la liste? %d\n", ft_check_fd(fd[3], &head));

	printf("Elements de la liste : ");
	for (t_list *tmp = head; tmp != NULL; tmp = tmp->next)
	{
		printf("%d ", tmp->fds);
	}*/
	//printf("Valeur du FD : %d\n", fd[0]);

	//free(new);
	/*while (1)
	{
		line = get_next_line(fd[4]);
		if (line == NULL)
			break ;
		printf("%s", line);
		free (line);
	}*/	
	line = get_next_line(fd);
	printf("%s", line);
	free (line);

	line = get_next_line(fd2);
	printf("%s", line);
	free (line);

	line = get_next_line(fd3);
	printf("%s", line);
	free (line);

	line = get_next_line(fd2);
	printf("%s", line);
	free (line);

	line = get_next_line(fd);
	printf("%s", line);
	free (line);

	line = get_next_line(fd2);
	printf("%s", line);
	free (line);

	line = get_next_line(fd3);
	printf("%s", line);
	free (line);

	line = get_next_line(fd2);
	printf("%s", line);
	free (line);

	line = get_next_line(fd3);
	printf("%s", line);
	free (line);

	/*line = get_next_line(fd[3]);
	printf("%s", line);
	free (line);

	line = get_next_line(fd[3]);
	printf("%s", line);
	free (line);*/

	/*printf("%d\n", ft_check_fd(fd[0], &head));
	printf("%d\n", ft_check_fd(fd[1], &head));
	printf("%d\n", ft_check_fd(fd[2], &head));
	printf("%d\n", ft_check_fd(fd[2], &head));*/

	/*line = get_next_line(fd[4]);
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
