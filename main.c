/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:23:17 by malord            #+#    #+#             */
/*   Updated: 2022/05/31 14:53:42 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_bonus.h"

t_list	*ft_lstlast(t_list *stash)
{
	while (stash && stash->next)
		stash = stash->next;
	return (stash);
}

int	ft_check_fd(int fd, t_list *files)
{
	t_list	*new;
	t_list	*last;

	while (files)
	{
		if (fd == files->fds)
			return (1);
		files = files->next;
	}
	new = malloc(sizeof(t_list));
	new->fds = fd;
	new->next = NULL;
	files = malloc(sizeof(t_list));
	files->fds = new->fds;
	printf("%d\n", files->fds);
	last = ft_lstlast(files);
	last->next = new;
	return (0);
}
int	main(void)
{
	int		*fd;
	char	*line;
	int		i;
	t_list	*new;
	t_list	*list;
	t_list	*head;

	fd[0] = open("1", O_RDONLY);
	fd[1] = open("2", O_RDONLY);
	fd[2] = open("3", O_RDONLY);
	fd[3] = open("4", O_RDONLY);
	fd[4] = open("test.txt", O_RDONLY);
	fd[5] = open("test2", O_RDONLY);
	i = 0;
	list = malloc(sizeof(t_list));
	head = list;
	list->fds = fd[i++];
	printf("Element inséré : %d\n", list->fds);
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
	}
	
	//new->fds = fd[0];
	//new->next = NULL;
	//list = new;
	/*for (t_list *tmp = list; tmp != NULL; tmp = tmp->next)
	{
		printf("Element de la liste : %d\n", tmp->fds);
	}*/
	//new->fds = fd[0];
	/*new->next = NULL;
	list = new;
	printf("FD dans la liste? %d\n", ft_check_fd(fd[0], list));
	printf("FD dans la liste? %d\n", ft_check_fd(fd[0], list));
	printf("FD dans la liste? %d\n", ft_check_fd(fd[1], list));
	printf("FD dans la liste? %d\n", ft_check_fd(fd[1], list));
	printf("Valeur du FD : %d\n", fd[0]);*/

	//free(new);
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
