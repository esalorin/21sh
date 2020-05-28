/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:56:25 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/28 17:49:09 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		sh_loop(t_sh *sh)
{
	char	*line;
	int		status;

	status = 1;
	while (status)
	{
		sh_prompt(sh);
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
	t_sh	sh;
	t_c		tc;

	if (ac && av[0])
	{
		sh_init(&sh, &tc);
		sh.env = ft_arraydup(env);
		sh_clear_screen();
		// update_shell_env(av[0], &sh.env);
		sh_loop(&sh);
		ft_arraydel(sh.env);
	}
	return (0);
}
