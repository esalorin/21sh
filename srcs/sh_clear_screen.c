/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_clear_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:17:18 by jrignell          #+#    #+#             */
/*   Updated: 2020/05/28 16:18:29 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "sh.h"

void	sh_clear_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_putint_fd);
}
