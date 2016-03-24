/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <acollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 17:37:21 by acollet           #+#    #+#             */
/*   Updated: 2015/05/12 15:45:14 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "wolf.h"
#include "libft.h"
#include "get_next_line.h"

static void		dellst(void *e, size_t s)
{
	ft_strdel((char **)&e);
	(void)s;
}

static int		count_lines(int fd, t_list **lst)
{
	char	*line;
	t_list	*node;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		node = ft_lstnew(line, ft_strlen(line) + 1);
		ft_lstadd(lst, node);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_lstrevert(lst);
	return (ft_lstlen(*lst));
}

static void		push_listtotab(const char *s, int ***tab, int i)
{
	char	**temp;
	char	*new;
	int		j;

	j = 0;
	new = ft_strnew(ft_strlen(s));
	while (s[j] != '\0')
	{
		new[j] = ((s[j] >= '0' && s[j] <= '9') || s[j] == '-') ? s[j] : ' ';
		j++;
	}
	temp = ft_strsplit(new, ' ');
	ft_strdel(&new);
	j = 0;
	while (temp[j] != '\0')
		j++;
	(*tab)[i] = (int *)malloc(sizeof(int) * (j + 1));
	(*tab)[i][0] = j;
	while (j--)
	{
		(*tab)[i][j + 1] = ft_atoi(temp[j]);
		ft_strdel(&temp[j]);
	}
	free(temp);
}

int				load_data(char *fname, t_map *map)
{
	int		fd;
	int		i;
	t_list	*lst;
	t_list	*node;

	i = 0;
	lst = NULL;
	((fd = open(fname, O_RDONLY)) < 0) ? perror("") : 0;
	if (fd < 0)
		return (-1);
	map->rows = count_lines(fd, &lst);
	if (map->rows <= 2
		|| !(map->tab = (int **)malloc(sizeof(int *) * map->rows)))
		return (-1);
	node = lst;
	while (node)
	{
		if (checkmap(node->content, i, map->rows) != 1)
			return (-1);
		push_listtotab(node->content, &(map->tab), i++);
		node = node->next;
	}
	ft_lstdel(&lst, &dellst);
	close(fd);
	return (1);
}

void			freetab(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
}
