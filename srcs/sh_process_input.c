/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:26:53 by jrignell          #+#    #+#             */
/*   Updated: 2020/06/20 12:42:17 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	sh_readkey(void)
{
	int		key;

	key = 0;
	if (read(STDIN_FILENO, &key, 4) == -1)
		sh_exit("read(): failed to read STDIN. Exiting..\n");
	return (key);
}

static int	sh_process_keypress(t_sh *sh)
{
	while ((sh->key = sh_readkey()))
	{
		if (sh->key == ENTER)
			break ;
		else if (sh->key == DEL || sh->key == BSPACE)
			ft_printf("You pressed DEL or backspace\n");
		else if (sh->key == LEFT || sh->key == RIGHT)
			return (sh_move_cursor(sh));
		else if (sh->key == UP || sh->key == DOWN)
			ft_printf("You pressed UP or DOWN key\n");
		else if (ft_isprint(sh->key))
			return (sh_save_to_buffer(sh));
			// ft_putchar(sh->key);
	}
	ft_printf("You pressed ENTER\n");
	exit(1);
	return (1);
}

void	sh_process_input(t_sh *sh)
{
	int		status;

	status = 0;
	while (status == 0)
	{
		status = sh_process_keypress(sh);
	}
}
