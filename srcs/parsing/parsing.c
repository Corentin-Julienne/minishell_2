/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:49:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/25 16:55:06 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*parse_user_input(t_shell *shell)
{
	t_token		*tokens;
	char		*item;
	int			i;
	
	i = 0;
	while (shell->user_input)
	{
		item = isolate_item(shell);
		if (!ft_strlen(item))
		{
			free(item);
			break ;
		}
		
		i++;
	}
	return (tokens);
}
