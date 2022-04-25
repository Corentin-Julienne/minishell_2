/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:48:27 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/25 18:13:48 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	add_slashes(char **paths, char **paths_v2)
{
	char			*tmp;
	int				i;

	i = 0;	
	while (paths[i])
	{
		paths_v2[i] = ft_strdup(paths[i]);
		if (!paths_v2[i])
			free_problem_str_arr(paths_v2, i);
		tmp = ft_strjoin(paths_v2[i], "/");
		if (!tmp)
		{
			free(paths_v2[i]);
			free_problem_str_arr(paths_v2, i);
		}
		free(paths_v2[i]);
		paths_v2[i] = tmp;
		if (!paths_v2[i])
			free_problem_str_arr(paths_v2, i);
		i++;
	}
	paths_v2[i] = NULL;
}

static char	**paths_with_slash(char **paths)
{
	size_t		arr_len;
	char		**paths_v2;

	arr_len = 0;
	while (paths[arr_len])
		arr_len++;
	paths_v2 = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!paths_v2)
	{
		free_split(paths);
		return (NULL);
	}
	add_slashes(paths, paths_v2);
	free_split(paths);
	return (paths_v2);
}

/* recup paths find the PATH variable in envp,
then use ft_split on it based on sep ':' */

char	**recup_paths(char **envp)
{
	char	**paths;
	char	*paths_str;
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			paths_str = envp[i] + 5;
			break ;
		}
		i++;
	}
	paths = ft_split(paths_str, ':');
	if (!paths)
		return (NULL);
	paths = paths_with_slash(paths);	
	return (paths);
}
