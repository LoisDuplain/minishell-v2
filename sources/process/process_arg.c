/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:43:34 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/20 16:18:32 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_processed_quote(char *arg, size_t *i, char quote)
{
	char	*result;

	result = NULL;
	i++;
	while (arg[i] != '\0' && arg[i] != quote)
	{
		
		i++;
	}
	i++;
	return (result);
}

char	*get_processed_arg(char *arg)
{
	char	*processed_arg;
	char	current_quote;
	size_t	arg_len;
	size_t	i;

	processed_arg = NULL;
	current_quote = '\0';
	arg_len = ft_strlen(arg);
	i = 0;
	while (i < arg_len)
	{
		if (arg[i] == "\'" || arg[i] == "\"")
			ft_append_strs(processed_arg,
				get_processed_quote(arg, &i, arg[i]), TRUE, FALSE);
		i++;
	}
	return (processed_arg);
}
