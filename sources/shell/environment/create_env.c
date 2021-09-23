/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:47:43 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/23 15:10:24 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_env(char **default_env)
{
	char	**new_env;
	size_t	line_index;

	new_env = ft_calloc(ft_get_splitted_size(default_env) + 1, sizeof(char *));
	if (new_env == NULL)
		return (NULL);
	line_index = 0;
	while (default_env[line_index] != NULL)
	{
		new_env[line_index] = ft_strdup(default_env[line_index], FALSE);
		line_index++;
	}
	new_env[line_index] = NULL;
	return (new_env);
}
