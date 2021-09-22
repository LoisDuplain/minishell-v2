/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:28:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/14 18:02:54 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_env(char **default_env)
{
	char	**new_env;
	size_t	line_index;

	new_env = ft_calloc(ft_get_splitted_size(default_env), sizeof(char *));
	if (new_env == NULL)
		return (NULL);
	line_index = 0;
	while (default_env[line_index] != NULL)
	{
		new_env[line_index] = ft_strdup(default_env[line_index], FALSE);
		line_index++;
	}
	return (new_env);
}

t_shell	*create_shell(char **env)
{
	t_shell	*shell;

	shell = ft_calloc(1, sizeof(t_shell));
	if (shell == NULL)
		return (NULL);
	shell->env = create_env(env);
	if (shell->env == NULL)
		return (destroy_shell(&shell));
	update_prompt(shell);
	shell->line = NULL;
	return (shell);
}
