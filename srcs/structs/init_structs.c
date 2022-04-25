/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:59:00 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/25 18:18:02 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_shell_struct(t_shell *shell, char **envp)
{
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
