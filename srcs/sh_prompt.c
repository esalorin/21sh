/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:14:17 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/28 17:32:21 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	sh_cursor_position(t_sh *sh, size_t col)
{
	sh->cursor->col = col + 4;
	sh->cursor->l_constraint = sh->cursor->col;
	// sh->cursor->row++;
}

void		sh_prompt(t_sh *sh)
{
	char	*pwd;
	char	*home;
	char	*dir;
	int		i;

	i = 0;
	pwd = getcwd(NULL, 1);
	if (pwd)
	{
		dir = ft_strrchr(pwd, '/');
		if ((home = checkhome(sh->env)))
		{
			if (ft_strcmp(pwd, home) == 0)
				dir = "~";
		}
		ft_printf(CBLUEB"%s%s $> %s", (ft_strlen(dir) > 1) ? ++dir : dir,
		CMAGENTAB, CRESET);
		ft_strdel(&pwd);
	}
	else
		ft_printf(CMAGENTAB"$> %s", CRESET);
	sh_cursor_position(sh, ft_strlen(dir));
}