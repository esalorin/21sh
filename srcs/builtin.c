/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:07:37 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/27 15:55:38 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**make_builtin(void)
{
	char	**des;

	if (!(des = (char**)malloc(sizeof(char*) * 7)))
		return (NULL);
	des[0] = ft_strdup("exit");
	des[1] = ft_strdup("cd");
	des[2] = ft_strdup("echo");
	des[3] = ft_strdup("env");
	des[4] = ft_strdup("setenv");
	des[5] = ft_strdup("unsetenv");
	des[6] = 0;
	return (des);
}

int		builtin_func(int i, t_sh *sh)
{
	if (i == 0)
		exit(1);
	if (i == 1)
		sh_cd(sh);
	else if (i == 2)
		sh_echo(sh);
	else if (i == 3)
		sh_env(sh);
	else if (i == 4)
		sh_setenv(sh);
	else if (i == 5)
		sh_unsetenv(sh);
	return (1);
}
