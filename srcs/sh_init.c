/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:47:23 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/27 18:48:16 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		se_init(t_sh *sh)
{
	char	*term_name;

	g_shell = sh;
	// se_print_usage(t);
	if ((t->fd = open(ttyname(0), O_RDWR | O_NDELAY | O_NOCTTY)) < 0)
		return (se_exit("Failed to open port\n"));
	if (!(term_name = getenv("TERM")))
		return
		(se_exit("Set a terminal type using `export TERM=<type>`. Exiting.\n"));
	se_valid_terminal(term_name);
}