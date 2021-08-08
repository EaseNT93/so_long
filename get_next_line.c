/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:13:02 by dpants            #+#    #+#             */
/*   Updated: 2021/08/03 19:07:42 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	*ft_add_line(char *buf, char **line)
{
	char	*tmp;

	tmp = ft_strchr(buf, '\n');
	if (tmp)
	{
		*tmp++ = '\0';
		*line = ft_strjoin(*line, buf);
		ft_strcpy(buf, tmp);
	}
	else
		*line = ft_strjoin(*line, buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*line;
	static char	buf[SIZE + 1];
	static int	eof = 1;

	if (read(fd, NULL, 0) == -1 || SIZE == 0 || eof == -1)
		return (NULL);
	line = ft_strdup("");
	if (NULL == line)
		return (NULL);
	tmp = ft_add_line(buf, &line);
	while (eof > 0 && !tmp)
	{
		eof = read(fd, buf, SIZE);
		if (eof == -1)
		{
			free(line);
			return (NULL);
		}
		buf[eof] = '\0';
		tmp = ft_add_line(buf, &line);
	}
	if (eof == 0 && !tmp)
		eof = -1;
	return (line);
}
