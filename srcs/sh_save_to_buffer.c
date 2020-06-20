/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_save_to_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 20:58:24 by jrignell          #+#    #+#             */
/*   Updated: 2020/06/20 14:07:00 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	sh_allocate_more_space_and_copy(char **buf, int *allocs, t_sh *sh)
{
	char	*tmp;

	if (!(tmp = ft_strdup(*buf)))
		sh_exit("malloc(): allocation failed. Exiting..\r\n");
	free(*buf);
	(*allocs)++;
	if (!(*buf = ft_strnew((*allocs) * BUFF_SIZE)))
		sh_exit("malloc(): allocation failed. Exiting..\r\n");
	sh->buffer = *buf;
	ft_memcpy(*buf, tmp, ft_strlen(tmp));
	ft_strdel(&tmp);
	
}

int		sh_save_to_buffer(t_sh *sh)
{
	static char	*buf;
	static int	position;
	static int	allocs = 1;
	char		*byte;

	if (!buf && !(buf = ft_strnew(BUFF_SIZE)))
		sh_exit("malloc(): allocation failed. Exiting..\r\n");
	if (!(byte = ft_strnew(1)))
		sh_exit("malloc(): allocation failed. Exiting..\r\n");
	byte[0] = (char)sh->key;
	if (position >= allocs * BUFF_SIZE)
		sh_allocate_more_space_and_copy(&buf, &allocs, sh);
	position++;
	ft_strlcat(buf, byte, allocs * BUFF_SIZE + 1);
	if (sh->buffer == NULL)
		sh->buffer = buf;
	ft_strdel(&byte);
	return (0);
}
