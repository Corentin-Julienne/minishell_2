/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:01:13 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/24 17:07:29 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

#include <readline/readline.h>
#include <readline/history.h>

#define PIPE			1
#define REDIR_INPUT		2
#define REDIR_OUTPUT	3
#define RI_CUT			4
#define RO_APPEND		5
#define CMD				6
#define	S_QUOTES		7
#define D_QUOTES		8
#define	ARG				9

typedef struct s_shell
{
	int				i;
	int				j;
	int				rtn;
	char			**env;
	char			**paths;
	char			*user_input;
	char			*ui_copy;
	int				fd_in;
	int				fd_out;
}					t_shell;

typedef struct s_token
{
	char			*item;
	int				type;
	int				used;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_seq
{
	char			*cmd;
	char			**cmds;
	char			*redir;
	char			**redirs;
}
				t_seq;

/* BUILTINS */

int			built_in_cd(char **args, t_shell *shell);
int			built_in_echo(char **args);
int			built_in_env(t_shell *shell);
void		built_in_exit(char **args, t_shell *shell);
int 		built_in_export(t_shell *shell, char **args);
int			built_in_pwd(void);
int 		built_in_unset(t_shell *shell, char **args);

/* ENV */

/*env_ops.c*/
void		add_env_var(t_shell *shell, const char *str);
void		update_env(t_shell *shell, const char *str, int index);
char		**envdup(char **envp, int pass, t_shell *shell);

/* EXEC */

/* exec_builtins.c */
int			is_built_in(char *cmd);
void		exec_built_in(char **args, t_shell *shell);
/* exec_cmd.c */
void		exec_shell_cmds(char **execve_prm2, t_shell *shell);
void		exec_cmd(char **args, t_shell *shell);
void		exec_instructions(t_args *args, t_shell *shell);
char		*parse_cmds(t_args *args);
/* MINISHELL */

/* init_structs.c */
void		init_shell_struct(t_shell *shell, char **envp);
void		init_seq_struct(t_seq *seq, t_args *args);
/* minishell.c */
void		display_args(t_args *args); // debug function only, suppress after
int			is_spaces_only(char *str);
void		modify_args(t_args *args);
int			minishell(t_shell *shell);

/* OPS */

/* expansions.c */
void		rpl_env_var(t_args *args, char *str_to_expand, size_t i, size_t j);
void		isolate_env_var(t_args *args);
void		manage_quote_args(t_args *args, int type);
/* pipes.c */
size_t		get_pipes_num(t_args *args);
void		pipeline(t_shell *shell, char **cmd);
/* redirections.c */
void		handle_redirs(t_seq *seq, t_shell *shell);
/* signals.c */
int			str_to_exitval(const char *str);

/* PARSING */

/* parse_input.c */
void		find_arg_type(t_args *args);
void		trim_user_input(t_shell *shell, size_t item_len);
size_t		manage_chevrons_length(t_shell *shell, size_t i);
size_t		calc_arg_length(t_shell *shell);
char		*isolate_item(t_shell *shell);
t_args		*parse_user_input(t_shell *shell);
/* quotes.c */
int			is_quote_valid(char *item, char sep);
size_t		calc_quote_length(char *str, size_t i);
void		remove_quotes(t_args *args);

/* UTILS */

/* args_utils_1.c */ 
t_args		*args_new(int type, char *item);
t_args		*args_last(t_args *args);
int			args_size(t_args *args);
/* args_utils_2.c */
void		args_delone(t_args **args);
void		args_clear(t_args **args);
void		args_add_front(t_args **args, t_args *new);
void		args_add_back(t_args **args, t_args *new);
/* free_utils.c */
void		free_split(char **split);
void		purge_seq(t_seq *seq);

#endif
