/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:47:23 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/28 20:43:40 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <fcntl.h>
#include <term.h>

static void	sh_assign_values(t_sh *sh, t_c *tc)
{
	g_shell = sh;
	sh->cursor = tc;
}

static void	sh_validate_terminal(t_sh *sh)
{
	char	*term_name;
	int		res;
	char	buf[2048];

	if ((sh->term_fd = open(ttyname(0), O_RDWR | O_NDELAY | O_NOCTTY)) < 0)
		sh_exit("Failed to open port\n");
	if (!(term_name = getenv("TERM")))
		sh_exit("Set a terminal type using `export TERM=<type>`. Exiting.\n");
	if (!isatty(STDERR_FILENO))
		sh_exit("Not a terminal. Exiting..\n");
	if ((res = tgetent(buf, term_name)) < 1)
	{
		res == -1 ? sh_exit("Could not access termcap data base. Exiting..\n")
		: sh_exit("Terminal type not found. Exiting..\n");
	}
}

static void	sh_configure_term_settings(t_sh *sh)
{
	if (tcgetattr(sh->term_fd, &sh->original_term_mode) == -1)
		sh_exit("tcgetattr(): failed to get current state. Exiting..\n");
	sh->current_term_mode = sh->original_term_mode;
	sh->current_term_mode.c_lflag &= ~(IEXTEN);
	sh->current_term_mode.c_lflag &= ~(ICANON | ECHO);
	sh->current_term_mode.c_iflag &= ~(IXON | ICRNL);
	sh->current_term_mode.c_cc[VMIN] = 1;
	sh->current_term_mode.c_cc[VTIME] = 0;
	if (tcsetattr(sh->term_fd, TCSANOW, &sh->current_term_mode) == -1)
		sh_exit("tcsetattr(): failed to make requested changes. Exiting..\n");
}

void		sh_init(t_sh *sh, t_c *tc)
{
	ft_bzero(sh, sizeof(t_sh));
	ft_bzero(tc, sizeof(t_c));
	sh_assign_values(sh, tc);
	sh_validate_terminal(sh);
	sh_configure_term_settings(sh);
	sh_init_signal_handlers();
}
