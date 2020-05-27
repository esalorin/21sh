/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:54:20 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/27 18:06:50 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "../libft/srcs/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>

# define BSLASH 92
# define DQUOTE 34
# define SQUOTE 39

typedef struct	s_sh
{
	char		**env;
	char		**args;
}				t_sh;

void			sh_loop(t_sh *sh);
void			sh_cd(t_sh *sh);
void			sh_echo(t_sh *sh);
void			error(char *s1, char *s2);
void			sh_env(t_sh *sh);
void			sh_unsetenv(t_sh *sh);
void			expansions(t_sh *sh);
void			sh_setenv(t_sh *sh);

int				sh_commands(t_sh *sh);
int				builtin_func(int i, t_sh *sh);
int				if_escape(char *s, char c);
int				quote_match(char *s);
int				count_slash(char *s, int i);

char			*ft_rmescapes_inquotes(char *s, char c);
char			*checkhome(char **env);

char			**make_builtin(void);
char			**check_if_quotes(char *s);

#endif
