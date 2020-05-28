/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:05:48 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/28 17:50:00 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <term.h>

static void	sh_left(t_sh *sh)
{
	if (sh->cursor->l_constraint < sh->cursor->col)
		tputs(tgoto(tgetstr("cm", NULL), --sh->cursor->col, sh->cursor->row), 1, ft_putint_fd);
}

static void	sh_right(t_sh *sh)
{
	// ft_printf("sh->cursor->row: %d\n", sh->cursor->row);
	tputs(tgoto(tgetstr("cm", NULL), ++sh->cursor->col, sh->cursor->row), 1, ft_putint_fd);
	// tgoto(tgetstr("cm", NULL), 24, 24);	
}

int		sh_move_cursor(t_sh *sh)
{
	if (sh->key == LEFT)
		sh_left(sh);
	else if (sh->key == RIGHT)
		sh_right(sh);
	return (1);
}
