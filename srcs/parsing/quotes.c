/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:51:38 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/28 16:18:58 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static char	*assemble_parts(t_args *args, size_t i, char *trm_q_str) // manage case if trm_q_str = ""
// {
// 	char			*new_str;
// 	char			*part_1;
// 	char			*part_3;
// 	unsigned int	start;
// 	size_t			len;
	
// 	part_1 = ft_substr(args->item, 0, i - 1);
// 	start = i + calc_quote_length(args->item, i) + 1;
// 	len = ft_strlen(args->item) - i + calc_quote_length(args->item, i);
// 	part_3 = ft_substr(args->item, start, len);
// 	if (trm_q_str[0] != '\0')
// 	{
// 		new_str = ft_strjoin_and_free(part_1, trm_q_str);
// 		new_str = ft_strjoin_and_free(new_str, part_3);
// 	}
// 	else
// 		new_str = ft_strjoin_and_free(part_1, part_3);
// 	free(part_3);
// 	if (!new_str)
// 		return (NULL); // change that
// 	return (new_str);
// }

int	remove_quotes(t_token *token)
{
	char		*trm_str;
	char		*new_str;
	size_t		quote_length;
	int			i;

	i = -1;
	while (token->item[++i])
	{
		if ((token->item[i] == '"' || token->item[i] == '\'') && 
			is_quote_valid(&token->item[i], token->item[i]))
		{
			quote_length = calc_quote_length(token->item, i);
			if (quote_length <= 2)
				trm_str = ft_strdup("");
			else
				trm_str = ft_substr(token->item, i + 1, quote_length - 1);
			if (!trm_str)
				return (-1);
			new_str = ft_strjoin();
			free(trm_str);
			if (!new_str)
				return (-1); // return
			i = -1;
		}
	}
	return (0);
}

/* return 1 if quote is valid (i.e. is NOT unclosed),
and 1 otherwise */

int	is_quote_valid(char *item, char sep)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (item[i])
	{
		if (item[i] == sep && i != 0)
		{
			res = 1;
			break ;
		}
		i++;
	}
	return (res);
}

/* calc the length of the quote (for tokenisation purpose)
return -1 if unclosed quote,
the length of the quote otherwise
[!!!! include the quotes in the length !!!!]
e.g : "truc" = 6, "" = 2, "y" = 3
*/

size_t	calc_quote_length(char *str, size_t i)
{
	char	sep;
	char	*sub_str;
	size_t	j;

	sep = str[i];
	j = i;
	sub_str = &str[i];
	if (!is_quote_valid(sub_str, sep))
		return (-1);
	if (ft_strlen(&str[i] >= 2) && str[i + 1] == sep)
		return (2);
	while (str[i])
	{
		if (str[i] == sep && i != 0)
		{
			i++;
			break ;
		}
		i++;
	}
	return (i - j);
}
