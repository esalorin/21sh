/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:59:23 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/25 16:05:08 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*check_path(char *s1, char *s2)
{
	char		*tmp;
	char		*path;

	tmp = ft_strjoin(s1, "/");
	path = ft_strjoin(tmp, s2);
	ft_strdel(&tmp);
	if (access(path, F_OK) == 0)
		return (path);
	ft_strdel(&path);
	return (NULL);
}

static char	*find_path(t_sh *sh)
{
	char	**bin;
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (sh->env[i])
	{
		if (ft_strncmp("PATH=", sh->env[i], 5) == 0)
		{
			bin = ft_strsplit(&sh->env[i][5], ':');
			i = 0;
			while (bin[i])
			{
				if ((path = check_path(bin[i++], sh->args[0])))
					break ;
			}
			ft_arraydel(bin);
			break ;
		}
		i++;
	}
	return (path);
}

static int	sh_exec(t_sh *sh)
{
	pid_t	pid;
	char	*path;

	path = find_path(sh);
	pid = fork();
	if (pid == 0)
	{
		if (execve(((path) ? path : sh->args[0]), sh->args, sh->env) == -1)
			error("minishell: invalid command: ", sh->args[0]);
		exit(1);
	}
	else if (pid > 0)
		wait(NULL);
	else
		ft_putendl_fd("minishell: fork failed", 2);
	(path) ? ft_strdel(&path) : 0;
	return (1);
}

int			sh_commands(t_sh *sh)
{
	int				i;
	static char		**builtin;

	i = 0;
	if (!builtin && (!(builtin = make_builtin())))
	{
			ft_putendl_fd("Malloc error", 2);
			return (1);
	}
	if (!sh->args[0])
		return (1);
	while (builtin[i])
	{
		if (ft_strcmp(sh->args[0], builtin[i]) == 0)
			return (builtin_func(i, sh));
		i++;
	}
	return (sh_exec(sh));
}
