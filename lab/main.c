/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:26:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/29 17:58:13 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lab.h"

/*

AUTHORIZED READLINE FUNCTIONS :

=> readline OK
you can use readline to add a prompt, the store the malloqued user_input in
a char * 
=> add_history OK
you use it after readline. Add the answer into the history. probably not malloqued
=> clear_history OK 
clear the history => check bash for more info
=> rl_on_new_line
=> rl_replace_line
=> rl_redisplay

*/

void	leaks_tracker(void)
{
	system("leaks readline_lab");
}

int main(void)
{
	char	*user_input;
	int		i = 0;
	
	atexit(leaks_tracker);
	while (42)
	{
		user_input = readline(">>> : ");
		add_history(user_input);
		if (!strncmp(user_input, "exit", 4))
			break ;
		if (!strncmp(user_input, "clear", 5))
			clear_history();
		free(user_input);
		// rl_redisplay();
		i++;
	}
	free(user_input);
	clear_history();
	return (0);
}
