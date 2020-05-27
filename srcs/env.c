/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:58:21 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/27 15:54:48 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sh_unsetenv(t_sh *sh)
{
	char	**new;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	(!sh->args[1]) ? ft_putendl_fd("unset: not enough arguments", 2) : 0;
	while (sh->args[++i])
	{
		j = 0;
		tmp = ft_strjoin(sh->args[i], "=");
		while (sh->env[j])
		{
			if (ft_strncmp(sh->env[j], tmp, ft_strlen(tmp)) == 0)
			{
				new = ft_arrayrem(sh->env, j);
				ft_arraydel(sh->env);
				sh->env = new;
				break ;
			}
			j++;
		}
		ft_strdel(&tmp);
	}
}

static void	setenv_new(t_sh *sh, char *tmp)
{
	char	**envcpy;
	char	*newvar;

	newvar = ft_strjoin(tmp, sh->args[2]);
	envcpy = ft_array_push(sh->env, newvar, -1);
	ft_arraydel(sh->env);
	ft_strdel(&newvar);
	sh->env = envcpy;
}

void		sh_setenv(t_sh *sh)
{
	char	*tmp;
	int		i;

	if (ft_arraylen(sh->args) < 3)
		ft_putstr_fd("setenv: too few arguments", 2);
	else
	{
		tmp = ft_strjoin(sh->args[1], "=");
		i = 0;
		while (sh->env[i])
		{
			if (ft_strncmp(sh->env[i], tmp, ft_strlen(tmp)) == 0)
			{
				ft_strdel(&sh->env[i]);
				sh->env[i] = ft_strjoin(tmp, sh->args[2]);
				break ;
			}
			i++;
		}
		if (!sh->env[i])
			setenv_new(sh, tmp);
		ft_strdel(&tmp);
	}
}

void		sh_env(t_sh *sh)
{
	if (ft_arraylen(sh->args) == 1)
		ft_putarray(sh->env);
	else
		ft_putstr_fd("env: too many arguments", 2);
}
