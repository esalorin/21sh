/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init_signal_handlers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:55:10 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/28 14:40:12 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <signal.h>
#include <sys/ioctl.h>

static void	sh_signal_handler(int signum)
{
	if (signum == SIGTSTP)
	{
		// se_disable_rawmode(g_shell);
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
	else if (signum == SIGCONT)
	{
		// se_enable_rawmode(g_shell);
		sh_init_signal_handlers();
		// se_clear_screen();
		// se_print_arg_stderr(g_shell);
	}
	else if (signum == SIGWINCH)
	{
		;
		// se_print_arg_stderr(g_shell);
	}
	else if (signum == SIGINT || signum == SIGABRT || signum == SIGIOT || signum
		== SIGSTOP || signum == SIGKILL || signum == SIGQUIT)
	{
		;
		// se_disable_rawmode(g_shell);
		// se_close(g_shell);
	}
}

void		sh_init_signal_handlers(void)
{
	signal(SIGTSTP, sh_signal_handler);
	signal(SIGINT, sh_signal_handler);
	signal(SIGABRT, sh_signal_handler);
	signal(SIGIOT, sh_signal_handler);
	signal(SIGSTOP, sh_signal_handler);
	signal(SIGKILL, sh_signal_handler);
	signal(SIGQUIT, sh_signal_handler);
	signal(SIGCONT, sh_signal_handler);
	signal(SIGWINCH, sh_signal_handler);
}
