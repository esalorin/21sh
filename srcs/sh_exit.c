/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:32:41 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/27 18:39:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	sh_exit(const char *message)
{
	char	*error;

	if (message == NULL)
		exit(EXIT_FAILURE);
	error = ft_strdup(message);
	ft_putendl_fd(error, STDERR_FILENO);
	ft_strdel(&error);
	exit(EXIT_FAILURE);
}
