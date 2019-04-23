/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:06:27 by sbruen            #+#    #+#             */
/*   Updated: 2019/04/23 18:59:03 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_line_fill(char **save, char **line, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (save[fd][i] != '\n' && save[fd][i] != '\0')
		i++;
	if (save[fd][i] == '\n')
	{
		*line = ft_strsub(save[fd], 0, i);
		tmp = ft_strdup(save[fd] + i + 1);
		free(save[fd]);
		save[fd] = tmp;
		if (save[fd][0] == '\0')
			ft_strdel(&save[fd]);
	}
	else if (save[fd][i] == '\0')
	{
		*line = ft_strdup(save[fd]);
		ft_strdel(&save[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char	*save[4096];
	int			ret;

	if (fd < 0 || !line || fd > 4096)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strnew(1);
		tmp = ft_strjoin(save[fd], buff);
		free(save[fd]);
		save[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && save[fd] == '\0')
		return (0);
	return (ft_line_fill(save, line, fd));
}
