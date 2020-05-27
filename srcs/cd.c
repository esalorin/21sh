/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:27:17 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/27 18:09:36 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	modify_pwd(char **env, char *old, char *new)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!old || !new)
	{
		ft_putendl_fd("21sh: error while updating env", 2);
		return ;
	}
	while (env[i] && (ft_strncmp("PWD=", env[i], 4) != 0))
		i++;
	while (env[j] && (ft_strncmp("OLDPWD=", env[j], 7) != 0))
		j++;
	(!env[j]) ? 0 : ft_strdel(&env[j]);
	env[j] = ft_strjoin("OLDPWD=", old);
	(!env[i]) ? 0 : ft_strdel(&env[i]);
	env[i] = ft_strjoin("PWD=", new);
}

static char	*oldpwd(char **env)
{
	int		i;
	char	*old;

	i = 0;
	old = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			return (&env[i][7]);
		}
		i++;
	}
	return (old);
}

static void	cd_new(t_sh *sh, char *pwd, char *new)
{
	if (chdir(sh->args[1]) != -1)
		modify_pwd(sh->env, pwd, (new = getcwd(new, 1)));
	else
		error("cd: no such directory: ", sh->args[1]);
	(new) ? ft_strdel(&new) : 0;
}

static void	cd_old(char **env, char *pwd, char *new)
{
	if (chdir(oldpwd(env)) != -1)
		modify_pwd(env, pwd, (new = getcwd(new, 1)));
	ft_printf("%s\n", (new) ? new : pwd);
	(new) ? ft_strdel(&new) : 0;
}

void		sh_cd(t_sh *sh)
{
	char	*pwd;
	char	*new;

	pwd = NULL;
	new = NULL;
	pwd = getcwd(pwd, 1);
	if (ft_arraylen(sh->args) > 2)
		error("cd: string not in pwd: ", sh->args[1]);
	else if (!sh->args[1])
	{
		if (chdir(checkhome(sh->env)) != -1)
			modify_pwd(sh->env, pwd, (new = getcwd(new, 1)));
	}
	else if (sh->args[1])
	{
		if (ft_strcmp(sh->args[1], "-") == 0)
			cd_old(sh->env, pwd, new);
		else
			cd_new(sh, pwd, new);
	}
	(pwd) ? ft_strdel(&pwd) : 0;
	(new) ? ft_strdel(&new) : 0;
}
