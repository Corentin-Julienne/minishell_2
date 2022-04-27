/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:59:00 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/27 18:00:38 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_shell_struct(t_shell *shell, char **envp)
{
	shell->exit_status = 0;
	shell->env = envdup(envp, -1);
	if (!shell->env)
		return (-1);
	shell->paths = recup_paths(envp);
	if (!shell->paths)
	{
		free_split(shell->env);
		return (-1);
	}
	return (0);
}
