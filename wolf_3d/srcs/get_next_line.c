/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:22:53 by acollet           #+#    #+#             */
/*   Updated: 2015/02/19 15:40:48 by acollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

static int		read_line(int fd, char **line, char **backup)
{
	char		buffer[BUFF_SIZE + 1];
	int			len;
	int			pos;

	len = 0;
	while ((len = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[len] = '\0';
		if ((pos = ft_strpos(buffer, '\n')) == -1)
			ft_strconcat(line, buffer);
		else
		{
			ft_strconcat(line, ft_strsub(buffer, 0, pos));
			*backup = ft_strsub(buffer, pos + 1, len - pos + 1);
			return (1);
		}
	}
	return (len);
}

static void		load_backup(char **line, char **backup, int pos)
{
	char	*temp;

	*line = ft_strsub(*backup, 0, pos);
	if (pos != (int)ft_strlen(*backup))
	{
		temp = ft_strsub(*backup, pos + 1, ft_strlen(*backup) - pos + 1);
		ft_strdel(backup);
		*backup = ft_strmove(&temp);
	}
	else
		ft_strdel(backup);
}

static int		use_save(char **line, char **backup)
{
	int		pos;

	if (backup == NULL)
		return (0);
	if (*backup != NULL && (pos = ft_strpos(*backup, '\n')) == -1)
	{
		if (!(*line = ft_strdup(*backup)))
			return (-1);
		ft_strdel(backup);
		return (0);
	}
	else if (*backup != NULL)
		load_backup(line, backup, pos);
	return (*backup != NULL ? 1 : 0);
}

int				get_next_line(int fd, char **line)
{
	static char	*backup = NULL;
	int			use_bak;
	int			use_read;

	use_bak = 0;
	use_read = 0;
	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (backup != NULL && (use_bak = use_save(line, &backup)) == -1)
		return (-1);
	if (use_bak == 0)
	{
		if ((use_read = read_line(fd, line, &backup)) == -1)
			return (-1);
		return (use_read);
	}
	return (*line == NULL ? (0) : (1));
}
