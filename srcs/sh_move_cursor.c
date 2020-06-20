/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:05:48 by jrignell          #+#    #+#             */
/*   Updated: 2020/06/20 14:25:16 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <term.h>

static void	to_left(t_sh *sh)
{
	if (sh->cursor->l_constraint < sh->cursor->col)
		tputs(tgoto(tgetstr("cm", NULL), --sh->cursor->col, sh->cursor->row), 1, ft_putint_fd);
}

static void	to_right(t_sh *sh)
{
	sh->cursor->r_constraint = ft_strlen(sh->buffer) + sh->cursor->l_constraint;
	if (sh->cursor->r_constraint > sh->cursor->col)
		tputs(tgoto(tgetstr("cm", NULL), ++sh->cursor->col, sh->cursor->row), 1, ft_putint_fd);
}

int		sh_move_cursor(t_sh *sh)
{
	if (sh->key == LEFT)
		to_left(sh);
	else if (sh->key == RIGHT)
		to_right(sh);
	return (0);
}
