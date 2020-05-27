/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:56:25 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/27 18:47:11 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	prompt(t_sh *sh)
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
}

void		sh_loop(t_sh *sh)
{
	char	*line;
	int		status;

	status = 1;
	while (status)
	{
		prompt(sh);
		sh_process_input(sh);
		// get_next_line(0, &line);
		sh->args = check_if_quotes(line);
		expansions(sh);
		status = sh_commands(sh);
		ft_strdel(&line);
		ft_arraydel(sh->args);
	}
}

int			main(int ac, char **av, char **env)
{
	t_sh sh;

	if (ac && av[0])
	{
		sh_init(sh);
		sh.env = ft_arraydup(env);
		// update_shell_env(av[0], &sh.env);
		sh_loop(&sh);
		ft_arraydel(sh.env);
	}
	return (0);
}
