/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:54:20 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/20 14:17:25 by jrignell         ###   ########.fr       */
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

# define BSLASH 0x5C
# define DQUOTE 0x22
# define SQUOTE 0x27
# define LEFT 0x445B1B
# define RIGHT 0x435B1B
# define DOWN 0x425B1B
# define UP 0x415B1B
# define ENTER 0xD
# define DEL 0x7E335B1B
# define BSPACE 0x7F

typedef struct termios	t_termios;

typedef struct	s_cursor
{
	size_t	l_constraint;
	size_t	r_constraint;
	size_t	col;
	int		row;
}				t_c;

typedef struct	s_sh
{
	int			key;
	int			term_fd;
	int			file_fd;
	char		**env;
	char		**args;
	char		*buffer;
	t_c			*cursor;
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
void			sh_init(t_sh *sh, t_c *tc);
void			sh_init_signal_handlers(void);
int				sh_move_cursor(t_sh *sh);
int				sh_save_to_buffer(t_sh *sh);
void			sh_clear_screen(void);
void			sh_prompt(t_sh *sh);


#endif
