/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:51:15 by esalorin          #+#    #+#             */
/*   Updated: 2019/11/18 13:22:30 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_lines(char *str, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	*line = ft_strsub(str, 0, i);
	if (str[i] != '\0')
		temp = ft_strdup(&str[++i]);
	else
		temp = ft_strdup(&str[i]);
	free(str);
	str = temp;
	return (str);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	static char	*str[4864];

	if (fd < 0 || fd > 4864 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(0);
		temp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (str[fd] && str[fd][0] != '\0')
	{
		str[fd] = ft_lines(str[fd], line);
		return (1);
	}
	return ((ret < 0) ? -1 : 0);
}
