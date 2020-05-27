/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:26:53 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/27 19:57:52 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	se_readkey(void)
{
	int		key;

	key = 0;
	if (read(STDIN_FILENO, &key, 4) == -1)
		sh_exit("read(): failed to read STDIN. Exiting..\n");
	return (key);
}

static int	se_process_keypress(t_sh *sh)
{
	while ((sh->key = se_readkey()))
	{
		if (sh->key == ENTER)
			break ;
		else if (sh->key == DEL || sh->key == BSPACE)
			ft_printf("You pressed DEL or backspace\n");
		else if (sh->key == LEFT || sh->key == RIGHT || sh->key == UP || sh->key == DOWN)
			ft_printf("You pressed one of the arrow keys\n");
		else if (ft_isprint(sh->key))
			ft_putchar(sh->key);
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
