/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 14:46:14 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/27 15:55:17 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*home(char *arg, char *home)
{
	int		i;
	char	*tmp;
	char	*des;

	i = 0;
	while (arg[i] && arg[i] != '~')
		i++;
	tmp = ft_strsub(arg, 0, i);
	des = ft_strjoin(tmp, home);
	ft_strdel(&tmp);
	if (arg[i + 1])
	{
		tmp = ft_strdup(&arg[i + 1]);
		des = ft_joindel(des, tmp);
	}
	return (des);
}

static char	*envar(char *arg, char **env, char *exp)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;
	char	*des;

	i = 0;
	des = NULL;
	while (arg[i] && arg[i] != '$')
		i++;
	s1 = ft_strsub(arg, 0, i);
	j = 1;
	while (exp[j] && exp[j] != '$')
		j++;
	s2 = ft_joindel(ft_strsub(exp, 1, j - 1), ft_strdup("="));
	i = 0;
	while (env[i] && (ft_strncmp(env[i], s2, j) != 0))
		i++;
	if (env[i])
		des = ft_joindel(s1, ft_strdup(&env[i][j]));
	if (exp[j])
		des = ft_joindel((des) ? des : s1, ft_strdup(&exp[j]));
	ft_strdel(&s2);
	return ((des) ? des : s1);
}

void		expansions(t_sh *sh)
{
	int		i;
	char	*tmp;
	char	*exp;

	i = 0;
	while (sh->args[i])
	{
		if ((exp = ft_strchr(sh->args[i], '$')))
		{
			tmp = envar(sh->args[i], sh->env, exp);
			ft_strdel(&sh->args[i]);
			sh->args[i] = tmp;
		}
		else if (ft_strchr(sh->args[i], '~'))
		{
			tmp = home(sh->args[i], checkhome(sh->env));
			ft_strdel(&sh->args[i]);
			sh->args[i] = tmp;
		}
		else
			i++;
	}
}

char		*checkhome(char **env)
{
	int		i;
	char	*home;

	i = 0;
	home = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
		{
			return (&env[i][5]);
		}
		i++;
	}
	return (home);
}
