/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:05:36 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/18 11:05:07 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** here we will create stock[fd]. While the fd can be read, we add the content
** into stock[fd]. If there is an issue with the reading --> returns -1.
*/

static int	ft_make_line(int const fd, char *buffer, char *stock[fd])
{
	int		ret;
	char	*temp;

	while ((ft_strchr(buffer, '\n') == NULL) &&
			(ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		temp = stock[fd];
		stock[fd] = ft_strjoin(temp, buffer);
		ft_strdel(&temp);
	}
	if (buffer)
		ft_strdel(&buffer);
	if (ret == -1)
		return (-1);
	return (1);
}

/*
** Here we have de GNL fct: we ll firstly have the buffer for the reading.
** If there is wrong inputs the fct returns -1
** stock[fd] is the location of the content corresponding to the fd
** We call the fct ft_make_line to create the line, if there is an issue, will
** return -1
** if there is a \n into the created stock, it will copy the stock[fd] content
** into *line, for a (str - stock[fd]) length. str correspond to the occurence
** of the \n. then we offset stock[fd] at the \n adress + 1.
** FD correspond to the nb of files allowed to be read.
*/

int			get_next_line(int const fd, char **line)
{
	static char	*stock[FD];
	char		*buffer;
	int			ret;
	char		*str;
	char		*tmp;

	buffer = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buffer == NULL || BUFF_SIZE < 1)
		return (-1);
	if (stock[fd] == NULL)
		stock[fd] = ft_strnew(1);
	if ((ret = ft_make_line(fd, buffer, stock)) == -1)
		return (-1);
	if ((str = ft_strchr(stock[fd], '\n')) != NULL)
	{
		*line = ft_strsub(stock[fd], 0, str - stock[fd]);
		tmp = stock[fd];
		stock[fd] = ft_strdup(str + 1);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(stock[fd]);
	stock[fd] = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
