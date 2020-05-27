/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:54:20 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/27 18:39:36 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "../libft/srcs/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <termios.h>

# define BSLASH 92
# define DQUOTE 34
# define SQUOTE 39
# define LEFT 0x445B1B
# define RIGHT 0x435B1B
# define DOWN 0x425B1B
# define UP 0x415B1B
# define ENTER 0xA
# define ESC 0x1B
# define DEL 0x7E335B1B
# define SPACE 0x20
# define BSPACE 0x7F
# define ASTERISK 0x2A
# define MINUS 0x2D

typedef struct termios	t_termios;

typedef struct	s_sh
{
	int			key;
	char		**env;
	char		**args;
	t_termios	original_term_mode;
	t_termios	current_term_mode;
}				t_sh;

t_sh			*g_shell;

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

/*
********************************************************************************
**          FUNCTIONS THAT HAD BEEN ADDED AFTER MINISHELL                     **
********************************************************************************
*/

void			sh_exit(const char *message);
void			sh_process_input(t_sh *sh);

#endif
