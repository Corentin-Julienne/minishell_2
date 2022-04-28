/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:49:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/28 16:28:25 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* bash allows CMDS to work regardless of the case
e.g echo will works but also Echo or eChO */

static void	*lowercase_cmds(t_token *token)
{
	int			i;

	i = 0;
	while (token->item[i])
	{
		if (token->item[i] >= 97 && token->item[i] <= 122)
			token->item[i] = token->item[i] - 32;
		i++;
	}
}

/* as asked by the subject, we need to expand the env variables (preceded by $)*/

int	modify_tokens(t_token *token)
{
	int				i;
	char			*expanded_token;

	while (token)
	{
		isolate_env_var(token);
		// remove quotes there

		// remove quotes before
		if (token->type == CMD)
			lowercase_cmds(token);
		token = token->next;
	}
	return (0);
}

static void	find_token_type(t_token *token)
{		
	while (token)
	{
		if (!ft_strcmp(token->item, "|"))
			token->type = PIPE;
		else if (!ft_strcmp(token->item, "<"))
			token->type = REDIR_INPUT;
		else if (!ft_strcmp(token->item, ">"))
			token->type = REDIR_OUTPUT;
		else if (!ft_strcmp(token->item, "<<"))
			token->type = RI_CUT;
		else if (!ft_strcmp(token->item, ">>"))
			token->type = RO_APPEND;
		else if (!token->prev || token->prev->type == PIPE)
			token->type = CMD;
		else if (!ft_strcmp(token->item, "'"))
			token->type = S_QUOTES;
		else if (!ft_strcmp(token->item, "\""))
			token->type = D_QUOTES;
		else
			token->type = ARG;
		token = token->next;
	}
}

t_token	*parse_user_input(t_shell *shell)
{
	t_token		*tokens;
	t_token		*new_elem;
	char		*item;
	int			i;

	tokens = NULL;
	i = 0;
	while (shell->user_input)
	{
		item = isolate_item(shell);
		if (!ft_strlen(item))
		{
			free(item);
			break ;
		}
		new_elem = token_new(item);
		if (!new_elem)
			return (NULL); // change this !!!
		new_elem->shell = shell;
		token_add_back(&tokens, new_elem);
		i++;
	}
	find_token_type(tokens);
	modify_tokens(tokens);
	return (tokens);
}
