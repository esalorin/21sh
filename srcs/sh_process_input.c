/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:26:53 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/27 18:45:06 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	se_readkey(void)
{
	int		key;

	key = 0;
	if (read(STDIN_FILENO, &key, 4) == -1)
		sh_exit("read: failed to read STDERR. Exiting..\n");
	return (key);
}

static int	se_process_keypress(t_sh *sh)
{
	while ((sh->key = se_readkey()))
	{
		if (sh->key == ENTER)
			break ;
		else if (sh->key == SPACE || sh->key == ASTERISK || sh->key == MINUS)
			ft_printf("You pressed space, * or -\n");
		else if (sh->key == DEL || sh->key == BSPACE || sh->key == ESC)
			ft_printf("You pressed DEL, backspace or ESC\n");
		else
			;
	}
	ft_printf("You pressed ENTER\n");
	exit(1);
	return (0);
}

void	sh_process_input(t_sh *sh)
{
	int		status;

	status = 1;
	while (status)
	{
		status = se_process_keypress(sh);
	}
}
